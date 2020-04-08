/*  Niemeyer Disks Manager
        (Overall disk tools wrapper)

    Copyright (C) 2019-2020 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QDebug>
#include <QProcess>
#include <QRegularExpression>
#include <QTextCodec>

#include "diskmgr.hpp"

DiskMgr::DiskMgr(QObject *parent) : QObject(parent) {}

QString DiskMgr::askPartedList() {
  QProcess process = QProcess();
  process.setReadChannel(QProcess::StandardOutput);
  process.start(QStringLiteral("sudo parted -l"));

  QByteArray data;
  while (process.waitForFinished())
    data.append(process.readAll());

  return QTextCodec::codecForMib(106)->toUnicode(data.data());
}

QStringList DiskMgr::getTasks() { return tasks; }

QStringList DiskMgr::getDevices() {
  QProcess process = QProcess();
  process.setReadChannel(QProcess::StandardOutput);
  process.start(QStringLiteral("lsblk -lndo NAME"));

  QByteArray data;
  while (process.waitForFinished())
    data.append(process.readAll());

  devices = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
  devices.removeAll(QString(""));
  return devices;
}

QStringList DiskMgr::getPartitions() {
  QProcess process = QProcess();
  process.setReadChannel(QProcess::StandardOutput);
  process.start(
      QStringLiteral("bash -c \"blkid | grep -Po '(?<=^/dev/)[^:]+'\""));

  QByteArray data;
  while (process.waitForFinished())
    data.append(process.readAll());

  partitions = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
  partitions.removeAll(QString(""));
  return partitions;
}

QStringList DiskMgr::getEXTPartitions() {
  QProcess process = QProcess();
  process.setReadChannel(QProcess::StandardOutput);
  process.start(QStringLiteral(
      "bash -c \"blkid | grep 'ext[2-4]' | grep -Po '(?<=^/dev/)[^:]+'\""));

  QByteArray data;
  while (process.waitForFinished())
    data.append(process.readAll());

  extPartitions =
      QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
  extPartitions.removeAll(QString(""));
  return extPartitions;
}

void DiskMgr::setTask(int index, QString newText) {
  if (newText.size() >= 1)
    tasks[index] = newText;
  else
    tasks.removeAt(index);

  emit tasksChanged();
}

void DiskMgr::taskDelete(int partIndex) {
  QString device;
  tasks << QString("parted /dev/%2 rm %1")
               .arg(getPartNum(partitions.at(partIndex), &device))
               .arg(device);
  emit tasksChanged();
}

void DiskMgr::taskResize(int extPartIndex, QString newEnd) {
  QString partition = extPartitions.at(extPartIndex);
  QString device;
  tasks << QString("parted /dev/%2 resizepart %1 %3")
               .arg(getPartNum(partition, &device))
               .arg(device)
               .arg(newEnd);
  tasks << QString("resize2fs /dev/%1").arg(partition);
  emit tasksChanged();
}

void DiskMgr::taskMove(int partIndex, QString relocation) {
  QString partition = partitions.at(partIndex);
  QString device;
  tasks << QString("echo '%3,' | sfdisk --move-data /dev/%2 -N %1")
               .arg(getPartNum(partition, &device))
               .arg(device)
               .arg(relocation);
  emit tasksChanged();
}

void DiskMgr::taskTables(int action, int devIndex, QString mode) {
  if (action == 0)
    tasks << QString("parted /dev/%1 mktable %2")
                 .arg(devices.at(devIndex))
                 .arg(mode);
  else if (mode == "GPT")
    tasks << QString("sgdisk -g /dev/%1").arg(devices.at(devIndex));
  else
    tasks << QString("sgdisk -m /dev/%1").arg(devices.at(devIndex));
  emit tasksChanged();
}

void DiskMgr::cleanTasks() {
  tasks.clear();
  emit tasksChanged();
}

void DiskMgr::taskCreate(int devIndex, QString type, QString fs, QString begin,
                         QString end) {
  tasks << QString("parted /dev/%1 mkpart %2 %3 %4 %5")
               .arg(devices.at(devIndex))
               .arg(type)
               .arg(fs)
               .arg(begin)
               .arg(end);
}

void DiskMgr::taskFlag(int minor, QString flag, bool state) {
  QString partition = partitions.at(minor);
  QString device;
  tasks << QString("parted /dev/%2 set %1 %2 %3")
               .arg(getPartNum(partition, &device))
               .arg(flag)
               .arg(state ? "on" : "off");
}

void DiskMgr::taskFormat(int partIndex, int fsIndex) {
  QString partition = partitions.at(partIndex);
  switch (fsIndex) {
  case 0: // BtrFS
    tasks << QString("mkfs.btrfs -q /dev/%1").arg(partition);
    break;
  case 1: // ExFAT
    tasks << QString("mkexfatfs /dev/%1").arg(partition);
    break;
  case 2: // EXT4
    tasks << QString("mkfs.ext4 -q /dev/%1").arg(partition);
    break;
  case 3: // FAT32
    tasks << QString("mkfs.fat -F32 -q /dev/%1").arg(partition);
    break;
  case 4: // NTFS
    tasks << QString("mkntfs -qf /dev/%1").arg(partition);
    break;
  case 5: // F2FS
    tasks << QString("mkfs.f2fs -q /dev/%1").arg(partition);
    break;
  default:
    tasks << QString("mkfs %1").arg(partition);
  }
}

int DiskMgr::getPartNum(QString deviceAndPart, QString *deviceOnly) {
  QRegularExpression re("^([^0-9]+)([0-9]+)$");
  QRegularExpressionMatch match = re.match(deviceAndPart);
  *deviceOnly = match.captured(1);
  return match.captured(2).toInt();
}

bool DiskMgr::genFinalScript() {
  QFile finalScript("/tmp/00-disks.sh");
  if (!finalScript.open(QIODevice::WriteOnly | QIODevice::Text))
    return false;

  finalScript.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner |
                             QFileDevice::ExeOwner);

  QTextStream scriptStream(&finalScript);
  scriptStream << "#!/usr/bin/bash -e\n" << tasks.join("\n");

  finalScript.close();
  return true;
}