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
	Q_PROPERTY(QStringList partitions READ getPartitions NOTIFY syncDisks)
	Q_PROPERTY(QStringList extPartitions READ getEXTPartitions NOTIFY syncDisks)
	Q_PROPERTY(QStringList devices READ getDevices NOTIFY syncDisks)

private:
	QStringList tasks;
	QStringList devices;
	QStringList partitions;
	QStringList extPartitions;
	QString finalScript;

	int getPartNum(QString, QString*);

public:
	explicit DiskMgr(QObject *parent = nullptr);
	
	QString askPartedList();
	QStringList getTasks();
	QStringList getDevices();
	QStringList getPartitions();
	QStringList getEXTPartitions();

	Q_INVOKABLE void setTask(int, QString);
	Q_INVOKABLE void taskDelete(int);
	Q_INVOKABLE void taskTables(int, int, QString);
	Q_INVOKABLE void taskResize(int, QString);
	Q_INVOKABLE void taskMove(int, QString);
	Q_INVOKABLE void taskCreate(int, QString, QString, QString, QString);
	Q_INVOKABLE void taskFlag(int, QString, bool);
	Q_INVOKABLE void taskFormat(int, int);
	Q_INVOKABLE void cleanTasks();

signals:
	void syncDisks();
	void tasksChanged();
};

#endif // DISKMGR_H