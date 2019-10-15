/*  Chaotic Installer Disks Manager
	(Overall disk tools wrapper)
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QProcess>
#include <QTextCodec>
#include <QDebug>

#include "diskmgr.hpp"

DiskMgr::DiskMgr(QObject *parent) :
	QObject (parent) {}

QString DiskMgr::askPartedList() {
	QProcess process = QProcess();
	process.setReadChannel(QProcess::StandardOutput);
	process.start(QStringLiteral("sudo parted -l"));

	QByteArray data;
	while(process.waitForFinished())
	    data.append(process.readAll());

	return QTextCodec::codecForMib(106)->toUnicode(data.data());
}

QStringList DiskMgr::getTasks() {
	return tasks;
}

QStringList DiskMgr::getDevices() {
	devices = QStringList();
	devices << QStringLiteral("sda");
	devices << QStringLiteral("sdb");
	return devices;
}

QStringList DiskMgr::getPartitions() {
	partitions = QStringList();
	partitions << QStringLiteral("sda1");
	partitions << QStringLiteral("sda2");
	partitions << QStringLiteral("sda3");
	partitions << QStringLiteral("sdb1");
	return partitions;
}


void DiskMgr::setTask(int index, QString newText) {
	if(newText.size() >= 1)
		tasks[index] = newText;	
	else
		tasks.removeAt(index);

	emit tasksChanged();
}

void DiskMgr::taskTables(int action, int devIndex, QString mode) {
	if(action == 0)
		tasks << QString("parted /dev/%1 mktable %2").arg(devices.at(devIndex)).arg(mode);
	else if(mode == "GPT")
		tasks << QString("sgdisk -g /dev/%1").arg(devices.at(devIndex));
	else
		tasks << QString("sgdisk -m /dev/%1").arg(devices.at(devIndex));
	emit tasksChanged();
}

void DiskMgr::cleanTasks() {
	tasks.clear();
	emit tasksChanged();
}