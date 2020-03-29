# Maintainer: PedroHLC <root@pedrohlc.com>
pkgname=niemeyer
pkgver=0.0.1
pkgrel=1
pkgdesc='An ArchLinux installer that focuses on generating a customizable mkrootfs script.'
arch=(x86_64 aarch64)
url=""
license=('GPL')
depends=(qt5-base qt5-quickcontrols2 libinput libxkbcommon qmltermwidget)
makedepends=(qt5-tools)
source=('git+https://github.com/PedroHLC/niemeyer.git')
md5sums=('SKIP')

build() {
  cd "$pkgname"

  qmake -makefile -project niemeyer.pro
  make
  lrelease niemeyer.pro
}

package() {
  cd "$pkgname"

  make DESTDIR="$pkgdir/" install
}