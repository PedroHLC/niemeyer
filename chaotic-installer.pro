#!/usr/bin/qmake -makefile
QT += quick
CONFIG += c++17

BASEDIR = $${PWD}
VPATH *= $${BASEDIR}/src

TRANSLATIONS = langs/en-us.ts  langs/pt-br.ts

HEADERS = chaotic-installer.hpp
SOURCES = main.cpp
TARGET = bin/chaotic-installer