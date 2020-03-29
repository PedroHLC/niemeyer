#!/usr/bin/bash
set -o errexit
DEST="$PWD/archlive"
REPO='niemeyer'

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

# cleanup old files
sudo rm -v "$DEST/work"/build.make_* "$DEST/work"/out/*.iso
rm "$DEST/repo"/*

# install Niemeyer
cp ../pkg/niemeyer*.pkg.tar.* "$DEST/repo/"

tee -a "$DEST"/packages.* << EOF
breeze-icons
capitaine-cursors
cantarell-fonts
niemeyer
EOF

# create the local repo for installing it
pushd "$DEST/repo"
	repo-add "${REPO}.db.tar.gz" *.pkg.tar.*
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
	ln -s ../../../usr/lib/systemd/system/niemeyer.service ./display-manager.service
popd

sed -i'' \
	's/multi-user.target/graphical.target/g' \
	"$DEST/airootfs/root/customize_airootfs.sh"

# increment locale to other translations
sudo sed -i \
	-e "/\/etc\/locale.gen/r /dev/stdin" \
	"$DEST/airootfs/root/customize_airootfs.sh" \
	> /dev/null << EOF
sed -i 's/#\(pt_BR\.UTF-8\)/\1/' /etc/locale.gen
EOF


# finally build it
cd "$DEST"
sudo ./build.sh -v