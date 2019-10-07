#ifndef MIRRORS_H
#define MIRRORS_H

#include <QObject>
#include <QList>

class MirrorEntry : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString url READ getURL)
	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY toggled)
private:
	QString url;
	bool enabled;
public:
	explicit MirrorEntry(QString url, QObject *parent = nullptr);
	Q_INVOKABLE QString getURL();
	Q_INVOKABLE bool isEnabled();
	Q_INVOKABLE void setEnabled(bool);
signals:
	void toggled();
};

class Mirrors : public QObject {
	Q_OBJECT
	Q_PROPERTY(QList<MirrorEntry*> list READ getMirrors NOTIFY mirrorsChanged)
	Q_PROPERTY(QStringList urlList READ getMirrorsURLs NOTIFY mirrorsChanged)
private:
	QList<MirrorEntry*> mirrorsList;
public:
	explicit Mirrors(QObject *parent = nullptr);
	QList<MirrorEntry*> getMirrors();
	QStringList getMirrorsURLs();
	Q_INVOKABLE void setEnabled(int, bool);
	Q_INVOKABLE void move(int, int);
	Q_INVOKABLE void apply();
signals:
	void mirrorsChanged();
};

#endif // MIRRORS_H