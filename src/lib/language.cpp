#include "language.hpp"
#include <QDebug>
#include <QDir>

Lang::Lang(QGuiApplication* app, QQmlEngine * engine, QObject *parent) :
	QObject (parent), app(app),  engine(engine) {
	translator = new QTranslator(this);
	//setLang(LOCALE_DEFAULT);
}

void Lang::setLang(QString locale) {
	QString path =
		QStringLiteral("langs/%2.qm")
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

QString Lang::getSelectedLang()
{
    return selectedLang;
}
