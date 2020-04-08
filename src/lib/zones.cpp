/*  Niemeyer Timezones
        (List availables, choose and set a keyboard keymap)

    Copyright (C) 2019-2020 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QDebug>
#include <QDirIterator>
#include <QtPlatformHeaders/QEglFSFunctions>

#include "zones.hpp"

QDir Timezone::timezoneDir = QDir(QStringLiteral("/usr/share/zoneinfo"));

Timezone::Timezone(QObject *parent) : QObject(parent) {}

int Timezone::getSelectedIndex() { return selectedId; }

void Timezone::setSelectedIndex(int index) {
  selectedId = index;

  emit selectedChanged();
}

QStringList Timezone::grabZones() {
  timezoneDir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
  QDirIterator it(timezoneDir, QDirIterator::Subdirectories);
  while (it.hasNext())
    qDebug() << it.next();

  return paths;
}