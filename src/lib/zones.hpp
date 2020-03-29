/*  Niemeyer Timezones Headers
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef ZONE_H
#define ZONE_H

#include <QObject>
#include <QDir>

class Timezone : public QObject {
	Q_OBJECT
	Q_PROPERTY(int selectedId READ getSelectedIndex WRITE setSelectedIndex NOTIFY selectedChanged)
	Q_PROPERTY(QStringList paths READ grabZones NOTIFY allZonesChanged)

private:
	int selectedId;
	QStringList paths;
	static QDir timezoneDir;

public:
	explicit Timezone(QObject *parent = nullptr);

	void setSelectedIndex(int index);

	QStringList grabZones();
	int getSelectedIndex();

signals:
	void selectedChanged();
	void allZonesChanged();
};

#endif // ZONE_H