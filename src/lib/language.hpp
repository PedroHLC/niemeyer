#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QObject>
#include <QLocale>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlEngine>

#define LOCALE_DEFAULT "en_US"

class Lang : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString selectedLang READ getSelectedLang NOTIFY languageChanged)

private:
	QGuiApplication *app;
	QQmlEngine *engine;
	QTranslator *translator;
	QString selectedLang;

public:
	explicit Lang(QGuiApplication *app, QQmlEngine *engine,
		QObject *parent = nullptr);

	QString getSelectedLang();
	Q_INVOKABLE void setLang(const QString locale);

signals:
	void languageChanged();
};

#endif // LANGUAGE_H