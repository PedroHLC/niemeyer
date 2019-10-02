# Chaotic Installer

This a port Anarchy Linux to C++ using Qt with QML.
It's recommended to use with EGLFS as platform abstraction.

## What it shares with Anarchy Linux?

 * This text is valid for both projects:

Anarchy Linux is an Arch Linux installer providing a hassle-free pure installation and polished user experience.
Every aspect of the install is taken into account from partitioning and general system configuration,
to installing your favorite DE/WM and additional software from the official Arch Linux repos.

The Anarchy installer is intended to provide both novice and experienced Linux users a simple and pain free way to install Arch Linux.
Install when you want it, where you want it, and how you want it.
That is the Anarchy philosophy.

Anarchy aims to provide a polished and pure Arch install while leaving open every possible configuration avenue for the user to choose from.

# What is different from Anarchy Linux?

 * Chaotic Installer has a Graphical Interface (still light and fast).
 * Chaotic Installer is written in C++, has qt as deps, needs compilation, doesn't give you a terminal, and because of that it's hard to say it still follows KISS philosophy.
 * It doesn't includes `yay`.

# Is it related to Chaotic-AUR repository?

Nope. And if it worries you, this installer doesn't include Chaotic-AUR or it's pacakges.
But, you'll find a ready to burn ISO with Chaotic Installer available in chaotic-aur (soon), and both projects are mantained by the same Pedro.

# Why EGLFS?

So you won't need Wayland, neither X nor a WM.

# Dependencies
```
yay -S qt5-base qt5-quickcontrols2 libinput libxkbcommon
```

# How to compile?
```
yay -S qt5-tools
cd chaotic-installer-qt
qmake -project chaotic-installer.pro
make
```

# How to run without X/Wayland?
Open a TTY without an open graphical session (`Ctrl+Alt+F3` should do it):

```
./bin/chaotic-installer
```

There is also a `launcher/startchaotic` script that will be used in generated ISO.

# What it looks like?

![Language Picking Screen](screenshot.png)
