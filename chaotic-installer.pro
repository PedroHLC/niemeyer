#!/usr/bin/qmake -makefile
QT += quick
QT += quickcontrols2
CONFIG += c++17

BASEDIR = $${PWD}
VPATH *= $${BASEDIR}/src

TRANSLATIONS = langs/en_US.ts langs/pt_BR.ts

HEADERS = chaotic-installer.hpp \
	lib/translations.hpp lib/keymap.hpp \
	lib/network.hpp lib/mirrors.hpp \
	lib/locales.hpp
SOURCES = main.cpp \
	lib/translations.cpp  lib/keymap.cpp \
	lib/network.cpp lib/mirrors.cpp \
	lib/locales.cpp
TARGET = bin/chaotic-installer

lupdate_only {
    SOURCES = qml/*.qml
}