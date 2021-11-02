#!/usr/bin/bash
set -o errexit
DEST="$PWD/archlive"
REPO='niemeyer'

# Install tools in case it's required
([ -f /usr/bin/mkarchiso ] && [ -f /usr/bin/sudo ] && [ -f /usr/bin/makepkg ]) \
	|| sudo pacman -S --needed base-devel archiso sudo

# build niemeyer if needed
build_niemeyer()
{
	pushd ../pkg
	makepkg PKGDEST="$PWD" -cCsf
	popd
}
[ -f ../pkg/niemeyer*.pkg.tar.zst ] || build_niemeyer

# Copy (overwriting) the original's profile
if [ -d "$DEST" ]; then
	cp -rt "$DEST" /usr/share/archiso/configs/releng/*
else
	cp -r /usr/share/archiso/configs/releng "$DEST"
fi
mkdir -p "$DEST/repo"

# cleanup old files
sudo rm -rf "$DEST/"/{work/{out/*.iso,build.make_*},airootfs/etc/systemd/system/display-manager.service}
sudo rm -rf "$DEST/work/"*/airootfs/var/cache/pacman/pkg/niemeyer*
rm -f "$DEST/repo"/*

# install Niemeyer
cp ../pkg/niemeyer*.pkg.tar.zst "$DEST/repo/"

tee -a "$DEST"/packages.* << EOF
noto-fonts
niemeyer
EOF

# create the local repo for installing it
pushd "$DEST/repo"
repo-add  "${REPO}.db.tar.gz" *.pkg.tar.*
popd

# install the repo
tee -a "$DEST/pacman.conf" > /dev/null << EOF
# local repository
[$REPO]
SigLevel = Optional TrustAll
Server = file:///$PWD/archlive/repo

EOF

# install Niemeyer as Display Manager
pushd "$DEST/airootfs/etc/systemd/system"
ln  -s  ../../../usr/lib/systemd/system/niemeyer.service ./display-manager.service
ln  -sf ../../../usr/lib/systemd/system/graphical.target ./default.target
popd

# finally build it
cd "$DEST/.."

sudo mkarchiso -v -w "$DEST/../" "$DEST"
