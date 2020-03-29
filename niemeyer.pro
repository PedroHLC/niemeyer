#!/usr/bin/qmake -makefile
QT += widgets quick quickcontrols2
CONFIG += c++17

DESTDIR=bin
OBJECTS_DIR=build
MOC_DIR=build

BASEDIR = $${PWD}
VPATH *= $${BASEDIR}/src

TRANSLATIONS = lib/niemeyer/i18n/en_US.ts lib/niemeyer/i18n/pt_BR.ts

HEADERS = niemeyer.hpp \
	lib/translations.hpp lib/keymap.hpp \
	lib/network.hpp lib/mirrors.hpp \
	lib/locales.hpp lib/user.hpp \
	lib/diskmgr.hpp lib/zones.hpp

SOURCES = main.cpp \
	lib/translations.cpp  lib/keymap.cpp \
	lib/network.cpp lib/mirrors.cpp \
	lib/locales.cpp lib/user.cpp \
	lib/diskmgr.cpp lib/zones.cpp

TARGET = niemeyer

lupdate_only {
    SOURCES = qml/*.qml
}
