# Chaotic Installer
A setup wizard for ArchLinux using Qt and compatible with EGLFS.

# Features
 * Compatible with EGLFS:
     * Does not require X11 or Wayland to run.
 * Lazy scriptable setup:
     * At one point you'll be presented to an editable bash script containing all the instructions that will be used during setup.
     * The same happens for network connections and partitioning.
 * No package will be installed without your consent.

# Building
## Dependencies
```
pacman -S qt5-base qt5-quickcontrols2 libinput libxkbcommon qmltermwidget
```

## How to build?
```
pacman -S qt5-tools
cd chaotic-installer-qt
qmake -makefile -project chaotic-installer.pro
make
lrelease chaotic-installer.pro
```

## How to run without X/Wayland?
Open a TTY without an open graphical session (`Ctrl+Alt+F3` should do it):

```
export QT_QPA_PLATFORM='eglfs'
./bin/chaotic-installer
```

# What it looks like?
![Language Picking Screen](screenshot.png)

# Is it related to Chaotic-AUR repository?
Both projects are maintained by the same Pedro, and you'll find a ready to burn ISO with Chaotic Installer available in Chaotic-AUR (soon).
But, this installer doesn't include Chaotic-AUR, any of its packages, and won't offer to add it.