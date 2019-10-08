#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QObject>
#include <QLocale>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlEngine>

class Translations : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString selectedLang READ getLang WRITE setLang NOTIFY languageChanged)

private:
	QGuiApplication *app;
	QQmlEngine *engine;
	QTranslator *translator;
	QString selectedLang;

public:
	explicit Translations(QGuiApplication *app, QQmlEngine *engine,
		QObject *parent = nullptr);

	QString getLang();
	Q_INVOKABLE void setLang(const QString locale);

signals:
	void languageChanged();
};

#endif // TRANSLATIONS_H