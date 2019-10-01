/*  Chaotic Installer Language Abstraction (Dummy by now)
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>

    License: GPL v2.0

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "lang.hpp"

QString Lang::sysEnv() const {
	return QStringLiteral("en_US.UTF-8");
}

QString Lang::mainError() const {
	return QStringLiteral("Error:");
}

QString Lang::mainYes() const {
	return QStringLiteral("Yes");
}

QString Lang::mainNo() const {
	return QStringLiteral("No");
}

QString Lang::mainOk() const {
	return QStringLiteral("Ok");
}

QString Lang::mainCancel() const {
	return QStringLiteral("Cancel");
}

QString Lang::mainOther() const {
	return QStringLiteral("Other");
}

QString Lang::mainDefault() const {
	return QStringLiteral("Default");
}

QString Lang::mainEdit() const {
	return QStringLiteral("Edit");
}

QString Lang::mainBack() const {
	return QStringLiteral("Back");
}

QString Lang::mainDoneMsg() const {
	return QStringLiteral("Done");
}

QString Lang::mainPartition() const {
	return QStringLiteral("Partition");
}

QString Lang::mainSize() const {
	return QStringLiteral("Size");
}

QString Lang::mainAdd() const {
	return QStringLiteral("Add");
}

QString Lang::mainNewUser() const {
	return QStringLiteral("New User");
}

QString Lang::mainChangePass() const {
	return QStringLiteral("Change-Password");
}

QString Lang::mainChangeFn() const {
	return QStringLiteral("Change-Full-Username");
}

QString Lang::mainChangeSh() const {
	return QStringLiteral("Change-Shell");
}

QString Lang::mainChangeSu() const {
	return QStringLiteral("Change-Privilege");
}

QString Lang::mainDelUser() const {
	return QStringLiteral("Remove-User");
}

QString Lang::mainInstall() const {
	return QStringLiteral("Install");
}

QString Lang::mainMountpoint() const {
	return QStringLiteral("Mount point");
}

QString Lang::mainCustom() const {
	return QStringLiteral("Custom");
}

QString Lang::mainWrite() const {
	return QStringLiteral("Write-Changes");
}

QString Lang::mainNone() const {
	return QStringLiteral("None");
}

QString Lang::mainSelect() const {
	return QStringLiteral("Select");
}

QString Lang::mainDrivers() const {
	return QStringLiteral("Drivers");
}

QString Lang::mainOs() const {
	return QStringLiteral("Open Source");
}

QString Lang::mainCustomMsg() const {
	return QStringLiteral("Enter a new custom mount point: \n\n $a Will be mounted under Root '/'");
}

QString Lang::mainCustomErrMsg0() const {
	return QStringLiteral("\n$error New mount point can't contain special characters...");
}

QString Lang::mainCustomErrMsg1() const {
	return QStringLiteral("\n$error New mount point can't be root mount point '/'");
}

QString Lang::mainWriteConfirm() const {
	return QStringLiteral("Write changes to disk?");
}

QString Lang::mainIntroMsg() const {
	return QStringLiteral("Welcome to the Anarchy Linux installer! \n\n $a Would you like to begin the install process?");
}

QString Lang::mainWifiMsg0() const {
	return QStringLiteral("Wifi interface detected, would you like to connect?");
}

QString Lang::mainWifiMsg1() const {
	return QStringLiteral("Unable to connect to wifi network, exiting installer.");
}

QString Lang::mainConnectErr0() const {
	return QStringLiteral("$error No network connection exiting installer.");
}

QString Lang::mainConnectErr1() const {
	return QStringLiteral("You must be connected to the internet to install Anarchy Linux.\n Please check your connection and try again.");
}

QString Lang::mainLocaleMsg() const {
	return QStringLiteral("Please select your desired locale:");
}

QString Lang::mainZoneMsg0() const {
	return QStringLiteral("Please enter your Time Zone:");
}

QString Lang::mainZoneMsg1() const {
	return QStringLiteral("Please enter your sub-zone:");
}

QString Lang::mainKeysMsg() const {
	return QStringLiteral("Select your key-map: \n\n $a If unsure leave default");
}

QString Lang::mainDriveMsg() const {
	return QStringLiteral("Auto Partition Drive:\n $a Select a drive to install Anarchy Linux onto \n $a NOTE: Selected drive will be formatted");
}

QString Lang::mainPartMsg() const {
	return QStringLiteral("Select your desired method of partitioning: \n\n $a NOTE Auto Partitioning will format the selected drive \n $a Press cancel to return to drive selection");
}

QString Lang::mainMenuMsg() const {
	return QStringLiteral("Return To Menu");
}

QString Lang::mainFsMsg() const {
	return QStringLiteral("Select your desired filesystem type: \n\n $a Default is EXT4");
}

QString Lang::mainSwapMsg0() const {
	return QStringLiteral("Would you like to create SWAP space? \n\n $a (Recommend 512M - 1024M space on drive)");
}

QString Lang::mainSwapMsg1() const {
	return QStringLiteral("Specify your desired swap size: \n\n $a (Align to 'M' for MiB or 'G' for GiB):");
}

QString Lang::mainSwapErrMsg0() const {
	return QStringLiteral("$error not enough space on drive!");
}

QString Lang::mainSwapErrMsg1() const {
	return QStringLiteral("$error swap must end in 'M' for MiB or 'G' for GiB");
}

QString Lang::mainSwapErrMsg2() const {
	return QStringLiteral("\n$error failed turning on swap, try formatting first \n\n $a Returning to partition menu...");
}

QString Lang::mainEfiMsg0() const {
	return QStringLiteral("Would you like to enable UEFI bios? \n\n $a May not work on some systems \n $a Enable with caution");
}

QString Lang::mainGptMsg() const {
	return QStringLiteral("Would you like to use GPT partitioning? \n\n $a (GUID Partition Table)");
}

QString Lang::mainInstallTypeMsg() const {
	return QStringLiteral("Select the type of system you would like to install: \n\n $a If unsure use 'Base' or 'Base-devel'");
}

QString Lang::mainPasswdMsg0() const {
	return QStringLiteral("$error you must enter a password here.");
}

QString Lang::mainPasswdMsg1() const {
	return QStringLiteral("Passwords do not match, please try again...");
}

QString Lang::mainPartErrMsg() const {
	return QStringLiteral("An error was detected during partitioning \n\n $a Returning partitioning menu");
}

QString Lang::mainPartErrMsg1() const {
	return QStringLiteral("Drive operations error. (mount/umount failure) \n\n Returning to menu...");
}

QString Lang::mainPartErrMsg2() const {
	return QStringLiteral("\n$error failed mounting device \n\n Returning to partition menu...");
}

QString Lang::mainManualPartMsg() const {
	return QStringLiteral("Guided Manual Partition Drive: \n $a Select a drive to edit partition scheme \n $a Select a partition to edit the mount point \n $a Select 'Done' when finished");
}

QString Lang::mainRootErrMsg() const {
	return QStringLiteral("$error partition too small to be root partition. \n\n $a Root partition must be at least 4 GiB in size");
}

QString Lang::mainRootErrMsg1() const {
	return QStringLiteral("$error you must select a root partition before continuing with install.");
}

QString Lang::mainWriteConfirmMsg() const {
	return QStringLiteral("Confirm writing changes to disk:");
}

QString Lang::mainReturnMsg() const {
	return QStringLiteral("\n ${Yellow}You have opened a new command line session.\n This enables you to run any custom commands from the installer.\n\n The Anarchy installer is still running in the background\n Return to the install where you left off with the command: \n    ${Green}anarchy\n    exit\n${ColorOff}");
}

QString Lang::mainArchChrootMsg() const {
	return QStringLiteral("\n ${Yellow}You have opened a new anarchy-chroot session.\n This enables you to run commands on your newly installed system.\n\n Note: This is not a standard terminal emulator.\n Commands here are fed into installed system and the results displayed\n Up/down arrow history and most standard commands work \n To show this message again type: ${Green}help \n ${Yellow}You may install or search packages with the commands:\n\n    ${Green}pacman -S <install package(s) here>\n    pacman -Ss <search-package-here>\n\n ${Yellow}You may edit text files with nano or vim editors: \n\n    ${Green}nano /path/to/file\n    vim /path/to/file\n\n ${Yellow}The Anarchy installer is still running in the background.\n Return to the installer with the command:\n\n    ${Green}anarchy\n    exit\n${ColorOff}");
}

QString Lang::mainMirrorMsg0() const {
	return QStringLiteral("Update mirrorlist:");
}

QString Lang::mainMirrorMsg1() const {
	return QStringLiteral("Please select your country code:");
}

QString Lang::mainMirrorEditorMsg() const {
	return QStringLiteral("Select a text editor to edit mirrors:");
}

QString Lang::mainManualMirrors() const {
	return QStringLiteral("Edit Mirrorlist Manually");
}

QString Lang::mainFetchmirrors() const {
	return QStringLiteral("Download & Rank New Mirrors");
}

QString Lang::mainCancelMirrors() const {
	return QStringLiteral("Skip Updating Mirrors");
}

QString Lang::mainMirrorCancelMsg() const {
	return QStringLiteral("Are you sure you want to skip updating mirrors? \n\n $a This may have an effect on download speed");
}

QString Lang::mainWifiOptionMsg() const {
	return QStringLiteral("Install wireless utilities? Provides wifi support. \n\n $a Necessary for connecting to wifi \n $a Select yes if using wifi");
}

QString Lang::mainWifiUtilMsg() const {
	return QStringLiteral("Select your desired network utility: \n\n $a Default is netctl (select networkmanager for GUI)");
}

QString Lang::mainNetUtilMsg0() const {
	return QStringLiteral("Netctl network utility (wifi-menu)");
}

QString Lang::mainNetUtilMsg1() const {
	return QStringLiteral("NetworkManager Utility (nmcli)");
}

QString Lang::mainPppoeMsg() const {
	return QStringLiteral("Include support for PPPoE DSL connections? \n\n $a Select yes if using PPPoE \n $a If unsure select No");
}

QString Lang::mainBaseMsg0() const {
	return QStringLiteral("Vanilla kernel");
}

QString Lang::mainBaseMsg1() const {
	return QStringLiteral("Vanilla kernel with base-devel");
}

QString Lang::mainHardenedMsg0() const {
	return QStringLiteral("Hardened kernel");
}

QString Lang::mainHardenedMsg1() const {
	return QStringLiteral("Hardened kernel with base-devel");
}

QString Lang::mainLTSMsg0() const {
	return QStringLiteral("Long term support kernel");
}

QString Lang::mainLTSMsg1() const {
	return QStringLiteral("Long term support kernel with base-devel");
}

QString Lang::mainZenMsg0() const {
	return QStringLiteral("Zen kernel");
}

QString Lang::mainZenMsg1() const {
	return QStringLiteral("Zen kernel with base-devel");
}

QString Lang::mainOsProberMsg() const {
	return QStringLiteral("Install os-prober? \n\n $a Required for multiboot \n $a If dual booting select yes");
}

QString Lang::mainGrubWarnMsg0() const {
	return QStringLiteral("Warning! System will not be bootable! \n\n $a You will need to configure a boot loader yourself \n $a Continue without a boot loader?");
}

QString Lang::mainGrubWarnMsg1() const {
	return QStringLiteral("After install is complete choose not to reboot, you may choose to keep the system mounted at /mnt allowing you to arch-chroot into it and configure your own boot loader.");
}

QString Lang::mainSyslinuxWarnMsg() const {
	return QStringLiteral("Installing syslinux in BIOS mode requires 64bit volume support to be disabled for boot partition.\n\n $a Note: This will format your boot partition\n Continue disabling 64bit volume on boot partition?");
}

QString Lang::mainExitMsg() const {
	return QStringLiteral("Ready to install system \n\n $a Are you sure you want to exit to menu?");
}

QString Lang::mainInstallErrMsg0() const {
	return QStringLiteral("$error root filesystem already installed \n\n $a Continuing to menu.");
}

QString Lang::mainInstallErrMsg1() const {
	return QStringLiteral("$error no filesystem mounted \n\n $a Return to drive partitioning?");
}

QString Lang::mainMultilibMsg() const {
	return QStringLiteral("64-bit architecture detected.\n\n $a Add multilib repos to pacman.conf? \n   (Allows installing 32-bit software on 64-bit system)");
}

QString Lang::mainDhcpMsg() const {
	return QStringLiteral("Enable DHCP at boot? (Recommended)\n\n $a Dynamic Host Control Protocol \n   (Automatic IP address configuration)");
}

QString Lang::mainHostMsg() const {
	return QStringLiteral("Set your system hostname:\n\n $a Computer/host name \n $a No spaces or special characters");
}

QString Lang::mainHostErrMsg() const {
	return QStringLiteral("$error hostname must begin with letter and can't contain special characters. \n\n $a Please try again.");
}

QString Lang::mainUserExistsMsg() const {
	return QStringLiteral("Would you like to add a new user account? \n\n $a Select 'yes' to add a new user.");
}

QString Lang::mainUserMenuMsg() const {
	return QStringLiteral("Add or edit user accounts:\n\n            Username:   |   Shell:");
}

QString Lang::mainUserMsg0() const {
	return QStringLiteral("Create a new user account? \n\n $a (Recommended) Create a user now.");
}

QString Lang::mainUserMsg1() const {
	return QStringLiteral("Set username: \n\n $a Lowercase letters and numbers only \n $a No capital letters or special characters");
}

QString Lang::mainUserMsg2() const {
	return QStringLiteral("Set full username: \n\n $a Write your full name");
}

QString Lang::mainUserErrMsg() const {
	return QStringLiteral("$error username must begin with letter and cannot contain special characters or uppercase letters. \n\n $a Please try again...");
}

QString Lang::mainUserErrMsg1() const {
	return QStringLiteral("$error username already in use. \n\n $a Please try again");
}

QString Lang::mainUserErrMsg2() const {
	return QStringLiteral("$error you must enter a username \n\n $a Please try again" );
}

QString Lang::mainFulluserErrMsg() const {
	return QStringLiteral("$error There are forbidden characters (,)\n\n $a Please try again");
}

QString Lang::mainFulluserErrMsg1() const {
	return QStringLiteral("$error This Fullname already in use.\n\n $a Please try again");
}

QString Lang::mainGraphicsMsg() const {
	return QStringLiteral("Select your desired graphics driver:\nDetected chipset: $chipset  \n\n $a If unsure use xf86-video-vesa or default");
}

QString Lang::mainDesktopCancelMsg() const {
	return QStringLiteral("Are you sure you don't want a desktop? \n\n $a You will be booted into command line only.");
}

QString Lang::mainNvidiaMsg() const {
	return QStringLiteral("Select your desired Nvidia driver: \n\n $a Cancel if none");
}

QString Lang::mainTouchpadMsg() const {
	return QStringLiteral("Would you like to install xf86-input touchpad drivers?  \n\n $a Required for laptop touchpad support.");
}

QString Lang::mainDesktopMsg() const {
	return QStringLiteral("Would you like to install a desktop or window manager? \n\n $a Select 'yes' to install a desktop environment");
}

QString Lang::mainDmMsg() const {
	return QStringLiteral("Would you like to install a display manager? \n\n $a Graphical login manager");
}

QString Lang::mainDmMsg1() const {
	return QStringLiteral("Select your desired display manager:\n\n $a Default is lightdm");
}

QString Lang::mainEnvironmentMsg() const {
	return QStringLiteral("Select your desired environment:\n $a Use spacebar to check/uncheck \n $a Press enter when finished");
}

QString Lang::mainStartxMsg() const {
	return QStringLiteral("Xinitrc file created. \n\n $a After login use the command 'startx' to access your desktop.");
}

QString Lang::mainExtraMsg0() const {
	return QStringLiteral("Install xfce4 goodies? \n\n $a XFCE4 Extra programs");
}

QString Lang::mainExtraMsg1() const {
	return QStringLiteral("Install gnome extra? \n\n $a Gnome Extra programs");
}

QString Lang::mainExtraMsg2() const {
	return QStringLiteral("Install mate extra? \n\n $a Mate Extra programs");
}

QString Lang::mainExtraMsg3() const {
	return QStringLiteral("\n $a Install minimal plasma desktop?");
}

QString Lang::mainExtraMsg4() const {
	return QStringLiteral("Install deepin extra? \n\n $a Deepin Extra programs");
}

QString Lang::mainExtraMsg5() const {
	return QStringLiteral("Install xmonad-contrib? \n\n $a xmonad Extra programs");
}

QString Lang::mainExtraMsg6() const {
	return QStringLiteral("Install gnome group? \n\n $a Gnome group programs");
}

QString Lang::mainExtraMsg7() const {
	return QStringLiteral("Install windowmaker extra? \n\n $a WindowMaker Extra programs");
}

QString Lang::mainExtraMsg8() const {
	return QStringLiteral("Install desktop extras software? \n\n $a Adds additional desktop software (recommended)");
}

QString Lang::mainSoftwareMsg0() const {
	return QStringLiteral("Would you like to install some common software? \n\n $a Select yes for a list of additional software");
}

QString Lang::mainSoftwareMsg1() const {
	return QStringLiteral("Choose your desired software: \n $a Use spacebar to check/uncheck software \n $a Press enter when finished");
}

QString Lang::mainSoftwareTypeMsg() const {
	return QStringLiteral("Select your desired software type \n\n $a Press 'install' when finished selecting software");
}

QString Lang::mainSoftwareWarnMsg() const {
	return QStringLiteral("Are you sure you want to continue without any extra software? \n\n $a Press yes to continue without software.");
}

QString Lang::mainSoftwareNoconfirmMsg() const {
	return QStringLiteral("Are you sure you don't want any software from:");
}

QString Lang::mainCompleteNoBootMsg() const {
	return QStringLiteral("Install process complete! \n\n $a You did not configure a boot loader \n $a Return to the command line to configure?");
}

QString Lang::mainNotCompleteMsg() const {
	return QStringLiteral("Install not complete, are you sure you want to reboot?");
}

QString Lang::mainCompleteMsg() const {
	return QStringLiteral("Install completed successfully. \n\n $a What would you like to do now?");
}

QString Lang::mainPartFrmtMsg() const {
	return QStringLiteral("Would you like to format the selected partition? \n\n $a Select 'yes' to format partition. \n $a Select 'no' to mount without formating.");
}

QString Lang::mainSwapFrmtMsg() const {
	return QStringLiteral("Would you like to format the swap space? \n\n $a Select yes to format new swap space. \n $a No to enable without formatting.");
}

QString Lang::mainVboxMsg() const {
	return QStringLiteral("VirtualBox guest install detected \n\n $a Installer will provide virtualbox-guest-utils.");
}

QString Lang::mainVmwareMsg() const {
	return QStringLiteral("Vmware guest install detected \n\n $a Installer will provide xf86-video-vmware xf86-input-vmmouse open-vm-tools.");
}

QString Lang::mainHypervMsg() const {
	return QStringLiteral("Hyper-v guest install detected \n\n $a Installer will provide xf86-video-fbdev.");
}

QString Lang::mainVmMsg() const {
	return QStringLiteral("Virtual machine guest install detected \n\n $a Installer will provide default drivers.");
}

QString Lang::mainBluetoothMsg() const {
	return QStringLiteral("Bluetooth support detected. \n\n $a Would you like to install bluez and bluez-utils? \n $a Required for bluetooth.");
}

QString Lang::mainBluemanMsg() const {
	return QStringLiteral("Would you like to install blueman bluetooth manager? \n\n $a Select 'yes' to install graphical bluetooth manager.");
}

QString Lang::mainBtenableMsg() const {
	return QStringLiteral("Enabling bluetooth...");
}

QString Lang::mainNwmanagerMsg0() const {
	return QStringLiteral("Enabling NetworkManager...");
}

QString Lang::mainNwmanagerMsg1() const {
	return QStringLiteral("Enabling netctl...");
}

QString Lang::mainVboxEnableMsg() const {
	return QStringLiteral("Enabling virtual system services...");
}

QString Lang::mainEfiManMsg() const {
	return QStringLiteral("EFI partition detected. \n\n $a Would you like to enable EFI boot?");
}

QString Lang::mainEfiErrMsg() const {
	return QStringLiteral("$error A mount point has already been created at '/boot' \n\n Please unmount and mount EFI partition as boot.");
}

QString Lang::mainEfiErrMsg1() const {
	return QStringLiteral("$error Multiple EFI partitions found but not mounted. \n\n Please mount EFI partition at '/boot' and try again.");
}

QString Lang::mainVfatMsg() const {
	return QStringLiteral("EFI system partition detected. \n\n $a Vfat required to create bootable EFI partition.");
}

QString Lang::mainLoaderTypeMsg() const {
	return QStringLiteral("Select your desired bootloader: \n\n $a Default is grub");
}

QString Lang::mainLoaderMsg() const {
	return QStringLiteral("GRand Unified Bootloader");
}

QString Lang::mainLoaderMsg1() const {
	return QStringLiteral("SysLinux Bootloader");
}

QString Lang::mainLoaderMsg2() const {
	return QStringLiteral("Systemd Bootloader");
}

QString Lang::mainLoaderMsg3() const {
	return QStringLiteral("EFISTUB Bootloader");
}

QString Lang::mainFailedMsg() const {
	return QStringLiteral("$error Failed to install packages to new root. \n\n $a Please check the file '/tmp/anarchy.log' for more info.");
}

QString Lang::mainShellMsg() const {
	return QStringLiteral("Select your desired command shell \n\n $a Default is bash");
}

QString Lang::mainNvidiaModesetMsg() const {
	return QStringLiteral("Would you like to enable Nvidia DRM kernel mode setting? \n\n $a Direct Rendering Manager Kernel Module.");
}

QString Lang::mainNvidia340msg() const {
	return QStringLiteral("Your chipset is supported by nvidia-340xx legacy drivers. \n\n $a Continue installing nvidia-340xx? graphics drivers");
}

QString Lang::mainNvidia390msg() const {
	return QStringLiteral("Your chipset is supported by nvidia-390xx legacy drivers. \n\n $a Continue installing nvidia-390xx? graphics drivers");
}

QString Lang::mainNvidiaCurmsg() const {
	return QStringLiteral("Your chipset is supported by the latest nvidia drivers. \n\n $a Continue installing nvidia graphics drivers?");
}

QString Lang::mainUcodeMsg() const {
	return QStringLiteral("Would you like to install intel-ucode? \n\n $a CPU microcode updates.");
}

QString Lang::mainUcodeFailedMsg() const {
	return QStringLiteral("Intel ucode failed to install for unknown reason. Please check (after install): /tmp/anarchy.log");
}

QString Lang::mainShrcMsg() const {
	return QStringLiteral("Select your desired zsh configuration:");
}

QString Lang::mainShrcMsg1() const {
	return QStringLiteral("Default Anarchy RC");
}

QString Lang::mainShrcMsg2() const {
	return QStringLiteral("Oh-My-Zsh Plugin & RC");
}

QString Lang::mainShrcMsg3() const {
	return QStringLiteral("Clean ZSH install no RC");
}

QString Lang::mainShrcMsg4() const {
	return QStringLiteral("grml-zsh-config");
}

QString Lang::mainNanoMsg() const {
	return QStringLiteral("User Friendly Text Editor");
}

QString Lang::mainVimMsg() const {
	return QStringLiteral("Advanced Text Editor");
}

QString Lang::mainSshMsg() const {
	return QStringLiteral("Enable SSH server at boot? \n\n $a Enables secure shell server");
}

QString Lang::mainFtpMsg() const {
	return QStringLiteral("Enable FTP server at boot? \n\n $a Enables file transfer server");
}

QString Lang::mainApacheMsg() const {
	return QStringLiteral("Enable Apache server at boot? \n\n $a Enables http server");
}

QString Lang::mainNginxMsg() const {
	return QStringLiteral("Enable Nginx server at boot? \n\n $a Enables http server");
}

QString Lang::mainCupsMsg() const {
	return QStringLiteral("Enable cups at boot? \n\n $a Enables printing system");
}

QString Lang::mainPartUtil() const {
	return QStringLiteral("Graphical partition editor");
}

QString Lang::mainPartUtil0() const {
	return QStringLiteral("Semi-Graphical partition editor");
}

QString Lang::mainPartUtil1() const {
	return QStringLiteral("Text mode partition editor");
}

QString Lang::mainPartUtil2() const {
	return QStringLiteral("GPT partition editor");
}


QString Lang::loadWaitLoad() const {
	return QStringLiteral("\n Please wait...");
}

QString Lang::loadConnectionLoad() const {
	return QStringLiteral("Please wait while we test your connection...");
}

QString Lang::loadBootLoad() const {
	return QStringLiteral("Creating boot partition...");
}

QString Lang::loadSwapLoad() const {
	return QStringLiteral("Creating swap space...");
}

QString Lang::loadFrmtLoad() const {
	return QStringLiteral("Formatting...");
}

QString Lang::loadMntLoad() const {
	return QStringLiteral("Mounting...");
}

QString Lang::loadPvLoad() const {
	return QStringLiteral("Creating physical volumes");
}

QString Lang::loadLvLoad() const {
	return QStringLiteral("Creating logical volumes");
}

QString Lang::loadEncryptLoad() const {
	return QStringLiteral("Encrypting drive...");
}

QString Lang::loadMirrorLoad0() const {
	return QStringLiteral("Retrieving new mirror list...");
}

QString Lang::loadMirrorLoad1() const {
	return QStringLiteral("Please wait while ranking mirrors...");
}

QString Lang::loadEfiLoad1() const {
	return QStringLiteral("Configuring efi boot...");
}

QString Lang::loadGrubLoad1() const {
	return QStringLiteral("Installing grub to drive...");
}

QString Lang::loadGrubLoad2() const {
	return QStringLiteral("Configuring grub...");
}

QString Lang::loadSyslinuxLoad() const {
	return QStringLiteral("Installing syslinux to drive...");
}

QString Lang::loadUefiConfigLoad() const {
	return QStringLiteral("Please wait while configuring kernel for uEFI...");
}

QString Lang::loadF2fsConfigLoad() const {
	return QStringLiteral("Please wait while configuring kernel for F2FS...");
}

QString Lang::loadKernelConfigLoad() const {
	return QStringLiteral("Please wait while configuring kernel...");
}

QString Lang::loadEncryptLoad1() const {
	return QStringLiteral("Please wait while configuring kernel for encryption...");
}

QString Lang::loadDhcpLoad() const {
	return QStringLiteral("Enabling DHCP...");
}

QString Lang::loadSshLoad() const {
	return QStringLiteral("Enabling SSH...");
}

QString Lang::loadCupsLoad() const {
	return QStringLiteral("Enabling print system...");
}

QString Lang::loadFtpLoad() const {
	return QStringLiteral("Enabling FTP...");
}

QString Lang::loadHttpLoad() const {
	return QStringLiteral("Enabling HTTP...");
}

QString Lang::loadDmLoad() const {
	return QStringLiteral("Enabling lightdm...");
}

QString Lang::loadPacmanLoad() const {
	return QStringLiteral("Please wait while we update your pacman databases...");
}

QString Lang::partMethod0() const {
	return QStringLiteral("Auto Partition Drive");
}

QString Lang::partMethod1() const {
	return QStringLiteral("Auto partition encrypted LVM");
}

QString Lang::partMethod2() const {
	return QStringLiteral("Manual Partition Drive");
}


QString Lang::FS0() const {
	return QStringLiteral("4th extended file system");
}

QString Lang::FS1() const {
	return QStringLiteral("3rd extended file system");
}

QString Lang::FS2() const {
	return QStringLiteral("2nd extended file system");
}

QString Lang::FS3() const {
	return QStringLiteral("B-Tree File System");
}

QString Lang::FS4() const {
	return QStringLiteral("Journaled File System");
}

QString Lang::FS5() const {
	return QStringLiteral("Reiser File System");
}

QString Lang::FS6() const {
	return QStringLiteral("F2FS File System");
}

QString Lang::FS7() const {
	return QStringLiteral("VFAT/FAT32 File System");
}

QString Lang::FS8() const {
	return QStringLiteral("XFS");
}


QString Lang::menuItem0() const {
	return QStringLiteral("Re-Set Locale");
}

QString Lang::menuItem1() const {
	return QStringLiteral("Re-Set Timezone");
}

QString Lang::menuItem2() const {
	return QStringLiteral("Re-Set Keymap");
}

QString Lang::menuItem3() const {
	return QStringLiteral("Partition Drive");
}

QString Lang::menuItem4() const {
	return QStringLiteral("Update Mirror list");
}

QString Lang::menuItem5() const {
	return QStringLiteral("Install Base System");
}

QString Lang::menuItem11() const {
	return QStringLiteral("Reboot System");
}

QString Lang::menuItem12() const {
	return QStringLiteral("Exit Installer");
}

QString Lang::menuItem13() const {
	return QStringLiteral("Command Line Session");
}

QString Lang::menuErrMsg3() const {
	return QStringLiteral("Drive already mounted, ready to install system. \n\n $a Are you sure you want to return to partition menu?");
}

QString Lang::menuExitMsg() const {
	return QStringLiteral("System not installed yet... \n\n $a Are you sure you want to exit?");
}

QString Lang::menuAarAddMsg() const {
	return QStringLiteral("Caution: adds custom Anarchy Linux repository to /etc/pacman.conf \n\n $a Continue adding custom package repo?");
}

QString Lang::menuSteamAddMsg() const {
	return QStringLiteral("Installing Steam requires multilib to be enabled. \n\n $a Enable multilib repos now?");
}

QString Lang::menuAar() const {
	return QStringLiteral("Anarchy Repository");
}

QString Lang::menuAarMsg() const {
	return QStringLiteral("AAR Software");
}

QString Lang::menuAudio() const {
	return QStringLiteral("Audio");
}

QString Lang::menuAudioMsg() const {
	return QStringLiteral("Audio Software");
}

QString Lang::menuDatabase() const {
	return QStringLiteral("Database");
}

QString Lang::menuDatabaseMsg() const {
	return QStringLiteral("Database Software");
}

QString Lang::menuGraphic() const {
	return QStringLiteral("Graphics");
}

QString Lang::menuGraphicMsg() const {
	return QStringLiteral("Graphics Software");
}

QString Lang::menuInternet() const {
	return QStringLiteral("Internet");
}

QString Lang::menuInternetMsg() const {
	return QStringLiteral("Internet Software");
}

QString Lang::menuMultimedia() const {
	return QStringLiteral("Multimedia");
}

QString Lang::menuMultimediaMsg() const {
	return QStringLiteral("Multimedia Software");
}

QString Lang::menuOffice() const {
	return QStringLiteral("Office");
}

QString Lang::menuOfficeMsg() const {
	return QStringLiteral("Office Software");
}

QString Lang::menuProgramming() const {
	return QStringLiteral("Programming");
}

QString Lang::menuProgramMsg() const {
	return QStringLiteral("Programming Software");
}

QString Lang::menuTerminal() const {
	return QStringLiteral("Terminal");
}

QString Lang::menuTerminalMsg() const {
	return QStringLiteral("Terminal Emulators");
}

QString Lang::menuTextEditor() const {
	return QStringLiteral("Text Editors");
}

QString Lang::menuTextEditorMsg() const {
	return QStringLiteral("Text Editing Software");
}

QString Lang::menuUtil() const {
	return QStringLiteral("Utilities");
}

QString Lang::menuUtilMsg() const {
	return QStringLiteral("Utilities Software");
}

QString Lang::menuServers() const {
	return QStringLiteral("Server");
}

QString Lang::menuServersMsg() const {
	return QStringLiteral("Server software");
}

QString Lang::menuFonts() const {
	return QStringLiteral("Fonts");
}

QString Lang::menuFontsMsg() const {
	return QStringLiteral("Linux Fonts");
}

QString Lang::menuGames() const {
	return QStringLiteral("Games");
}

QString Lang::menuGamesMsg() const {
	return QStringLiteral("Linux Games");
}

QString Lang::menuReboot0() const {
	return QStringLiteral("Reboot System");
}

QString Lang::menuReboot1() const {
	return QStringLiteral("Return To Command Prompt");
}

QString Lang::menuReboot2() const {
	return QStringLiteral("Anarchy-Chroot Into Installed System");
}

QString Lang::menuReboot3() const {
	return QStringLiteral("Add New User Account");
}

QString Lang::menuReboot4() const {
	return QStringLiteral("View Install Log");
}

QString Lang::menuReboot5() const {
	return QStringLiteral("Install Additional Software");
}

QString Lang::menuReboot6() const {
	return QStringLiteral("Power Off System");
}

QString Lang::menuCustomizedDe() const {
	return QStringLiteral("Customized Desktop");
}

QString Lang::menuCustomizedDeMsg() const {
	return QStringLiteral("Customized Desktop Environments");
}

QString Lang::menuMoreDe() const {
	return QStringLiteral("Clean Desktop Environments");
}

QString Lang::menuMoreDeMsg() const {
	return QStringLiteral("Default Desktop Environments");
}

QString Lang::menuMoreWm() const {
	return QStringLiteral("More Window Managers");
}

QString Lang::menuMoreWmMsg() const {
	return QStringLiteral("Default Window Managers");
}


QString Lang::opMsgWelcome() const {
	return QStringLiteral("Anarchy Linux");
}

QString Lang::opMsgConnection() const {
	return QStringLiteral("Check Connection");
}

QString Lang::opMsgLocale() const {
	return QStringLiteral("Set Locale");
}

QString Lang::opMsgZone() const {
	return QStringLiteral("Set Timezone");
}

QString Lang::opMsgKey() const {
	return QStringLiteral("Set Keymap");
}

QString Lang::opMsgPart() const {
	return QStringLiteral("Partition Drive");
}

QString Lang::opMsgPartload() const {
	return QStringLiteral("Partitioning Drive");
}

QString Lang::opMsgManual() const {
	return QStringLiteral("Partition Menu");
}

QString Lang::opMsgEdit() const {
	return QStringLiteral("Edit Partition");
}

QString Lang::opMsgMirror() const {
	return QStringLiteral("Update Mirrorlist");
}

QString Lang::opMsgInstall() const {
	return QStringLiteral("Install System");
}

QString Lang::opMsgConfig() const {
	return QStringLiteral("Configure System");
}

QString Lang::opMsgHost() const {
	return QStringLiteral("Set Hostname");
}

QString Lang::opMsgPasswd() const {
	return QStringLiteral("Set Password");
}

QString Lang::opMsgUser() const {
	return QStringLiteral("Add User");
}

QString Lang::opMsgUser1() const {
	return QStringLiteral("Edit User");
}

QString Lang::opMsgDe() const {
	return QStringLiteral("Install Desktop");
}

QString Lang::opMsgSoftware() const {
	return QStringLiteral("Install Software");
}

QString Lang::opMsgComplete() const {
	return QStringLiteral("Install Complete");
}

QString Lang::opMsgMenu() const {
	return QStringLiteral("Main Menu");
}


QString Lang::installOptMsg() const {
	return QStringLiteral("Select your desired install option: \n\n $a Quick install select 'Anarchy-Desktop' or 'Anarchy-Server' \n $a Advanced install options select 'Anarchy-Advanced'");
}

QString Lang::installOpt0() const {
	return QStringLiteral("Manually selection install options");
}

QString Lang::installOpt1() const {
	return QStringLiteral("Quick desktop install");
}

QString Lang::installOpt2() const {
	return QStringLiteral("Quick LTS desktop install");
}

QString Lang::installOpt3() const {
	return QStringLiteral("Quick server install");
}

QString Lang::installOpt4() const {
	return QStringLiteral("Quick LTS server install");
}


QString Lang::varGtk3() const {
	return QStringLiteral("Install $DE gtk3? \n\n $a (experimental version)");
}

QString Lang::varDrive() const {
	return QStringLiteral("WARNING! Will erase all data on drive! \n\n $a Location: /dev/$DRIVE \n $a Size: $driveGigs GiB \n $a Filesystem: $FS \n $a Would you like to continue?");
}

QString Lang::varDrive1() const {
	return QStringLiteral("WARNING! Will erase all data on drive! \n\n $a Location: /dev/$DRIVE \n $a Size: $driveGigs GiB \n $a Filesystem: $FS \n $a Swap space: $SWAPSPACE MiB \n $a Would you like to continue?");
}

QString Lang::varDrive2() const {
	return QStringLiteral("WARNING! Will erase all data on drive! \n\n $a Location: /dev/$DRIVE \n $a Size: $driveGigs GiB \n $a Filesystem: $FS \n $a Swap space $SWAPSPACE MiB \n $a Boot: UEFI \n $a Would you like to continue?");
}

QString Lang::varDrive3() const {
	return QStringLiteral("WARNING! Will erase all data on drive! \n\n $a Location: /dev/$DRIVE \n $a Size: $driveGigs GiB \n $a Filesystem: $FS \n $a Boot: UEFI \n $a Would you like to continue?");
}

QString Lang::varEncrypt0() const {
	return QStringLiteral("Warning this will encrypt /dev/$DRIVE! \n\n $a Continue?");
}

QString Lang::varEncrypt1() const {
	return QStringLiteral("\nPlease enter a new password for /dev/$DRIVE \n\n $a Note this password is used to unencrypt your drive at boot");
}

QString Lang::varEncrypt2() const {
	return QStringLiteral("\nNew /dev/$DRIVE password again. \n\n $a Encryption password again:");
}

QString Lang::varRoot() const {
	return QStringLiteral("Create a new root mount point: \n $a Note: Root mount point must be created first. \n\n $a Partition: /dev/$part \n $a Size: $partSize \n\n Create new root mount point?");
}

QString Lang::varManualPart0() const {
	return QStringLiteral("Partition already mounted. \n\n $a Mount point: $partMount \n $a Partition: /dev/$part \n $a Size: $partSize\n\n Edit to create new mount point");
}

QString Lang::varManualPart1() const {
	return QStringLiteral("Would you like to unmount partition: /dev/$part and remove $partMount mount point? \n\n $a Note will unmount all partitions mounted under");
}

QString Lang::varManualPart2() const {
	return QStringLiteral("Warning: partition: /dev/$part is set as your root filesystem, this will erase all mount point under it. \n\n $a Are you sure you want to continue?");
}

QString Lang::varManualPart3() const {
	return QStringLiteral("Would you like to edit the partition scheme now? \n\n $a Drive: /dev/$part \n $a Size: $partSize \n\n Edit partition scheme? -Don't forget to 'write' changes");
}

QString Lang::varManualNewPart() const {
	return QStringLiteral("Would you like to create a new mount point? \n\n $a Partition: /dev/$part \n $a Size: $partSize \n\n Edit to create new mount point");
}

QString Lang::varManualSwap() const {
	return QStringLiteral("Would you like to remove SWAP filesystem from /dev/$part? \n\n $a Select 'yes' to remove SWAP filesystem.");
}

QString Lang::varMountWarn() const {
	return QStringLiteral("Warning: disk /dev/$part contains mounted partitions. \n\n $a Would you like to unmount and edit partition scheme?");
}

QString Lang::varMnt0() const {
	return QStringLiteral("Select a new mount point for /dev/$part: \n\n $a Select 'custom' to create new mount point");
}

QString Lang::varFsErr() const {
	return QStringLiteral("$error A separate '/boot' partition must be setup when using an $FS filesystem. \n\n $a Returning to partition menu...");
}

QString Lang::varInstall() const {
	return QStringLiteral("Begin installing Anarchy Linux base system onto /dev/$DRIVE?\n\n $a Download size: $softwareSize \n $a Estimated install time: $downMin minutes.\n $a Estimated speed: $connectionSpeed $connectionRate \n $a Packages to add: \n\nbase${baseInstall}");
}

QString Lang::varUserEdit() const {
	return QStringLiteral("Edit user:\n $a Username: $user\n $a Login Shell: $userSh\n $a Full Username : $fullUser\n $a Sudo User: $sudo");
}

QString Lang::varUserShell() const {
	return QStringLiteral("Select a new shell for $user:\n $a Set user login shell");
}

QString Lang::varUser0() const {
	return QStringLiteral("\nPlease enter a new login password for: $user \n\n $a Set $user password");
}

QString Lang::varUser1() const {
	return QStringLiteral("\nRe-enter login password for: $user \n\n $a $user password again");
}

QString Lang::varSudo() const {
	return QStringLiteral("Enable sudo privilege for $user? \n\n $a Enables administrative privilege for $user.");
}

QString Lang::varSudo1() const {
	return QStringLiteral("Disable sudo privilege for $user? \n\n $a Disables administrative privilege for $user.");
}

QString Lang::varDeluser() const {
	return QStringLiteral("Delete user: $user? \n\n $a Removes user account from system");
}

QString Lang::varRootConfirm() const {
	return QStringLiteral("Confirm creating mount point? \n\n $a Mount point: '/' Root File System \n $a Partition: /dev/$part \n $a Size: $partSize \n $a Filesystem: $FS \n\n Write changes to disk?");
}

QString Lang::varPartConfirm() const {
	return QStringLiteral("Confirm creating mount point? \n\n $a Mount point: $mnt \n $a Partition: /dev/$part \n $a Size: $partSize \n $a Filesystem: $FS \n\n Write changes to disk?");
}

QString Lang::varSoftwareConfirm0() const {
	return QStringLiteral("Add the following packages to install list? \n\n $a Number of packages: $softwareInt \n $a Download size: $softwareSize \n $a Packages to add: \n\n$softwareList");
}

QString Lang::varSoftwareConfirm1() const {
	return QStringLiteral("Proceed with installing software? \n\n $a Number of packages: $softwareInt \n $a Total download size: $softwareSize \n $a Estimated install time: $downMin minutes \n $a Estimated speed: $connectionSpeed $connectionRate \n $a Packages to install: \n\n$downloadList");
}

QString Lang::varEfi() const {
	return QStringLiteral("A mounted EFI system has been detected at $espPart \n\n $a Would you like to enable EFI boot?");
}

QString Lang::varVfat() const {
	return QStringLiteral("The EFI system mounted at $espPart does not contain a valid vfat filesystem. \n\n $a Would you like to format and create new vfat system?");
}

QString Lang::varEfiMnt() const {
	return QStringLiteral("The EFI partition detected at $espPart has not been mounted. \n\n Mount EFI boot partition now?");
}

QString Lang::varF2Err() const {
	return QStringLiteral("$error You must create a separate boot partition in order to use an $FS filesystem. \n\n $a Returning to partition menu...");
}


QString Lang::loadFS0() const {
	return QStringLiteral("Partitioning /dev/$DRIVE...");
}

QString Lang::loadFS1() const {
	return QStringLiteral("Please wait while creating $FS filesystem...");
}

QString Lang::loadinstall() const {
	return QStringLiteral("$h\nInstalling Anarchy Linux to: /dev/$DRIVE \n\n $a Download size: $softwareSize");
}

QString Lang::loadsoftware() const {
	return QStringLiteral("$h\nInstalling additional software \n\n $a Download size: $softwareSize");
}

QString Lang::loadlocale() const {
	return QStringLiteral("Generating $LOCALE locale...");
}

QString Lang::loadzone() const {
	return QStringLiteral("Setting timezone $ZONE...");
}
