#!/usr/bin/qmake -makefile
QT += quick
QT += quickcontrols2
CONFIG += c++17

DESTDIR=bin
OBJECTS_DIR=build
MOC_DIR=build

BASEDIR = $${PWD}
VPATH *= $${BASEDIR}/src

TRANSLATIONS = langs/en_US.ts langs/pt_BR.ts

HEADERS = chaotic-installer.hpp \
	lib/translations.hpp lib/keymap.hpp \
	lib/network.hpp lib/mirrors.hpp \
	lib/locales.hpp lib/user.hpp \
	lib/diskmgr.hpp

SOURCES = main.cpp \
	lib/translations.cpp  lib/keymap.cpp \
	lib/network.cpp lib/mirrors.cpp \
	lib/locales.cpp lib/user.cpp \
	lib/diskmgr.cpp

TARGET = chaotic-installer

lupdate_only {
    SOURCES = qml/*.qml
}
