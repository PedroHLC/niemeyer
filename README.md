# Chaotic Installer

This a port Anarchy Linux to C++ using Qt with QML.
It's recommended to use with EGLFS as platform abstraction.

## What it shares with Anarchy Linux?

* Consider `:%s/Anarchy( Linux| installer)?/Chaotic Installer/g`

Anarchy Linux is an Arch Linux installer providing a hassle-free pure installation and polished user experience.
Every aspect of the install is taken into account from partitioning and general system configuration,
to installing your favorite DE/WM and additional software from the official Arch Linux repos.

The Anarchy installer is intended to provide both novice and experienced Linux users a simple and pain free way to install Arch Linux.
Install when you want it, where you want it, and how you want it.
That is the Anarchy philosophy.

Anarchy aims to provide a polished and pure Arch install while leaving open every possible configuration avenue for the user to choose from.

# What is different from Anarchy Linux?

 * Chaotic Installer has a Graphical Interface
 * Chaotic Installer is written in C++ and because of that, it's hard to say it follows KISS philosophy.
 * It doesn't includes `yay`

# Is it related to Chaotic-AUR repository?

Nope, it absolutely doesn't include Chaotic-AUR or it's pacakges.
But you'll find a ready to burn ISO with Chaotic Installer available in chaotic-aur, and both projects are mantained by the same Pedro.

# Why EGLFS?

So you won't need Wayland neither X or a WM.

# Dependencies
```
yay -S qt5-base qt5-quickcontrols2 libevdev
```