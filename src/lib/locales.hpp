/*  Chaotic Installer System's Locales Headers
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef LOCALES_H
#define LOCALES_H

#include <QObject>
#include <QList>

class LocaleEntry : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString code READ getCode)
	Q_PROPERTY(QString lang READ getLANG)
	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY toggled)
private:
	QString code;
	QString langCode;
	bool enabled;
public:
	explicit LocaleEntry(QString code, QObject *parent = nullptr);
	Q_INVOKABLE QString getCode();
	Q_INVOKABLE QString getLANG();
	Q_INVOKABLE bool isEnabled();
	Q_INVOKABLE void setEnabled(bool);
signals:
	void toggled();
};

class Locales : public QObject {
	Q_OBJECT
	Q_PROPERTY(QList<LocaleEntry*> list READ getLocales)
	Q_PROPERTY(QStringList codes READ getLocalesCodes)
	Q_PROPERTY(QStringList langs READ getAvailableLANGs NOTIFY langsChanged)
	Q_PROPERTY(QString selectedLANG READ getLANG)
private:
	QList<LocaleEntry*> localesList;
	QString selectedLANG;
public:
	explicit Locales(QObject *parent = nullptr);
	QList<LocaleEntry*> getLocales();
	QStringList getLocalesCodes();
	QStringList getAvailableLANGs();
	QString getLANG();
	Q_INVOKABLE void setEnabled(int, bool);
	Q_INVOKABLE void setLANG(int);
	Q_INVOKABLE QString genLocaleConfFile();
	Q_INVOKABLE QString genLocaleGenFile();
signals:
	void langsChanged();
};

#endif // LOCALES_H