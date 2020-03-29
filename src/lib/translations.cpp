/*  Niemeyer Translations
	(Load and set Qt translator and locale)
    
    Copyright (C) 2019-2020 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QDebug>
#include <QDir>

#include "translations.hpp"

Translations::Translations(QGuiApplication* app, QQmlEngine * engine, QObject *parent) :
	QObject (parent), app(app),  engine(engine) {
	appDir = app->applicationDirPath();
	translator = new QTranslator(this);
}

void Translations::setLang(QString locale) {
	QString path =
		QStringLiteral("../" LANGS_PATH "%1.qm")
		.arg(locale);

	if(!translator->load(path, appDir)) {
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
