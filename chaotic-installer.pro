#!/usr/bin/qmake -makefile
QT += quick
CONFIG += c++17

BASEDIR   = $${PWD}
VPATH *= $${BASEDIR}/src $${INCLUDEPATH}

HEADERS = chaotic-installer.hpp lang.hpp
SOURCES = main.cpp lang.cpp
TARGET = bin/chaotic-installer