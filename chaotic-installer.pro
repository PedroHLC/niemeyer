#!/usr/bin/qmake -makefile
QT += quick
QT += quickcontrols2
CONFIG += c++17

BASEDIR = $${PWD}
VPATH *= $${BASEDIR}/src

TRANSLATIONS = langs/en_US.ts langs/pt_BR.ts

HEADERS = chaotic-installer.hpp \
	lib/language.hpp lib/locale.hpp
SOURCES = main.cpp \
	lib/language.cpp  lib/locale.cpp
TARGET = bin/chaotic-installer

lupdate_only {
    SOURCES = qml/*.qml
}