/*  Chaotic Installer Disks Manager
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef DISKMGR_H
#define DISKMGR_H

#include <QObject>
#include <QDir>

class DiskMgr : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString partedListOutput READ askPartedList NOTIFY syncDisks)
	Q_PROPERTY(QStringList tasks READ getTasks NOTIFY tasksChanged)

private:
	QStringList tasks;
	QString finalScript;

public:
	explicit DiskMgr(QObject *parent = nullptr);
	
	QString askPartedList();
	QString getTasks();

signals:
	void syncDisks();
	void tasksChanged();
};

#endif // DISKMGR_H