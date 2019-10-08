#include <QDebug>
#include <QDir>

#include "translations.hpp"

Translations::Translations(QGuiApplication* app, QQmlEngine * engine, QObject *parent) :
	QObject (parent), app(app),  engine(engine) {
	translator = new QTranslator(this);
}

void Translations::setLang(QString locale) {
	QString path =
		QStringLiteral("langs/%1.qm")
		.arg(locale);

	if(!translator->load(path)) {
		qDebug() << "Failed to load translation file " << path;
		return;
	}

    QLocale::setDefault(QLocale(locale));
    selectedLang = locale;

    app->installTranslator(translator);
    engine->retranslate();

    emit languageChanged();
}

QString Translations::getLang()
{
    return selectedLang;
}