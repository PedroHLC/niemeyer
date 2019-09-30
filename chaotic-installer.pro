#!/usr/bin/qmake -makefile
QT += quick
CONFIG += c++17

BASEDIR   = $${PWD}
VPATH *= $${BASEDIR}/src $${INCLUDEPATH}

HEADERS = chaotic-installer.hpp config.hpp
SOURCES = main.cpp config.cpp
TARGET = bin/chaotic-installer