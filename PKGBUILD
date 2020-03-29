# Maintainer: PedroHLC <root@pedrohlc.com>
pkgname=niemeyer
pkgver=0.0.1
pkgrel=1
pkgdesc='An ArchLinux GUI installer that focuses on generating a customizable mkrootfs script.'
arch=(x86_64 aarch64)
url=""
license=('GPL')
depends=(qt5-base qt5-quickcontrols2 libinput libxkbcommon qmltermwidget)
makedepends=(qt5-tools)
source=('git+https://github.com/PedroHLC/niemeyer.git')
md5sums=('SKIP')

build() {
  cd "$pkgname"

  qmake -makefile niemeyer.pro
  make
  lrelease niemeyer.pro
}

package() {
  cd "$pkgname"

  install -dm 755 "$pkgdir/usr/bin/"
  install -Dm 755 bin/niemeyer "$pkgdir/usr/bin/"
  install -Dm 755 launcher/start-niemeyer "$pkgdir/usr/bin/"

  install -dm 755 "$pkgdir/usr/share/niemeyer"
  install -Dm 644 share/niemeyer/background.jpg "$pkgdir/usr/share/niemeyer/"
  
  install -dm 755 "$pkgdir/usr/lib/niemeyer/qml"
  install -Dm 644 lib/niemeyer/qml/* "$pkgdir/usr/lib/niemeyer/qml/"

  install -dm 755 "$pkgdir/usr/lib/systemd/system"
  install -Dm 644 launcher/niemeyer.service "$pkgdir/usr/lib/systemd/system/"
}