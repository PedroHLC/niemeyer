#!/usr/bin/env sh
set -o errexit
DEST="$PWD/archlive"

# build ISO if doesn't exists
[ -f "$DEST/out"/archlinux-*.iso ] || ./build-iso.sh

# check qemu dependencies
[ -f /usr/bin/qemu-system-x86_64 ] || sudo pacman -S --needed qemu
[ -n "$(groups | grep kvm)" ] || sudo usermod -aG kvm "$(whoami)"

# grab last image only
LAST_IMAGE=`ls -1 "$DEST/out"/archlinux-*.iso | tail -n 1`

# run in qemu
qemu-system-x86_64 -m 2G -enable-kvm -cdrom "$LAST_IMAGE"