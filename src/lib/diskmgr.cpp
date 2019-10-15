/*  Chaotic Installer Disks Manager
	(Overall disk tools wrapper)
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QProcess>
#include <QTextCodec>

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