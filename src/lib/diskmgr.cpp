/*  Chaotic Installer Disks Manager
	(Overall disk tools wrapper)
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QRegularExpression>

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
	QProcess process = QProcess();
	process.setReadChannel(QProcess::StandardOutput);
	process.start(QStringLiteral("lsblk -lndo NAME"));

	QByteArray data;
	while(process.waitForFinished())
	    data.append(process.readAll());

	devices = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
	devices.removeAll(QString(""));
	return devices;
}

QStringList DiskMgr::getPartitions() {
	QProcess process = QProcess();
	process.setReadChannel(QProcess::StandardOutput);
	process.start(QStringLiteral("bash -c \"blkid | grep -Po '(?<=^/dev/)[^:]+'\""));

	QByteArray data;
	while(process.waitForFinished())
	    data.append(process.readAll());

	partitions = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
	partitions.removeAll(QString(""));
	return partitions;
}

QStringList DiskMgr::getEXTPartitions() {
	QProcess process = QProcess();
	process.setReadChannel(QProcess::StandardOutput);
	process.start(QStringLiteral("bash -c \"blkid | grep 'ext[2-4]' | grep -Po '(?<=^/dev/)[^:]+'\""));

	QByteArray data;
	while(process.waitForFinished())
	    data.append(process.readAll());

	extPartitions = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
	extPartitions.removeAll(QString(""));
	return extPartitions;
}

void DiskMgr::setTask(int index, QString newText) {
	if(newText.size() >= 1)
		tasks[index] = newText;	
	else
		tasks.removeAt(index);

	emit tasksChanged();
}

void DiskMgr::taskDelete(int partIndex) {
	QString device;
	tasks << QString("parted /dev/%2 rm %1").arg(getPartNum(partitions.at(partIndex), &device)).arg(device);
	emit tasksChanged();
}

void DiskMgr::taskResize(int extPartIndex, QString newEnd) {
	QString partition = extPartitions.at(extPartIndex);
	QString device;
	tasks << QString("parted /dev/%2 resizepart %1 %3").arg(getPartNum(partition, &device)).arg(device).arg(newEnd);
	tasks << QString("resize2fs /dev/%1").arg(partition);
	emit tasksChanged();
}

void DiskMgr::taskMove(int partIndex, QString relocation) {
	QString partition = partitions.at(partIndex);
	QString device;
	tasks << QString("echo '%3,' | sfdisk --move-data /dev/%2 -N %1").arg(getPartNum(partition, &device)).arg(device).arg(relocation);
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

void DiskMgr::taskCreate(int devIndex, QString type, QString fs, QString begin, QString end) {

}

void DiskMgr::taskFlag(int minor, QString type, bool state) {

}

void DiskMgr::taskFormat(int partIndex, int fsIndex) {

}


int DiskMgr::getPartNum(QString deviceAndPart, QString *deviceOnly) {
	QRegularExpression re("^([^0-9]+)([0-9]+)$");
	QRegularExpressionMatch match = re.match(deviceAndPart);
	*deviceOnly = match.captured(1);
	return match.captured(2).toInt();	
}