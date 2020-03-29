#!/usr/bin/bash
DEST="$PWD/archlive"
set -o errexit

# Install tools in case it's required
([ -f /usr/bin/mkarchiso ] && [ -f /usr/bin/sudo ] && [ -f /usr/bin/makepkg ]) \
	|| sudo pacman -S --needed base-devel archiso sudo 

# build niemeyer if needed
build_niemeyer() {
	pushd ../pkg
		makepkg PKGDEST="$PWD" -cCs
	popd
}
[ -f ../pkg/niemeyer*.pkg.tar.* ] || build_niemeyer

# Copy the original's profile
cp -r /usr/share/archiso/configs/releng "$DEST"
mkdir -p "$DEST/repo"

# install Niemeyer
cp ../pkg/niemeyer*.pkg.tar.* "$DEST/repo/"

echo 'niemeyer' >> "$DEST"/packages.*

# create the local repo for installing it
pushd "$DEST/repo"
	repo-add local.db.tar.gz *.pkg.tar.*
popd

# install the repo
tee -a "$DEST/pacman.conf" > /dev/null << EOF
# local repository
[local]
SigLevel = Optional TrustAll
Server = file:///$PWD/archlive/repo

EOF

# install Niemeyer as Display Manager
ln -s /usr/lib/systemd/system/niemeyer.service \
	"$DEST/airootfs/etc/systemd/system/display-manager.service"

cd archlive
sudo ./build.sh -v