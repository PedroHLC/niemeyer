#include <QProcess>
#include <QDebug>
#include <QtPlatformHeaders/QEglFSFunctions>

#include "locale.hpp"

Locale::Locale(QObject *parent) :
	QObject (parent) {}

void Locale::toggleLocale(QString locale) {
	//TODO
}

QString Locale::getSelectedKeyboard() {
    return selectedKeyboard;
}

QStringList Locale::getSelectedLocales() {
    return selectedLocales;
}

QString Locale::getSelectedZone() {
    return selectedZone;
}

void Locale::setKeyboard(const QString &keymap) {
	qDebug() << "Setting keymap " << keymap;

	selectedKeyboard = keymap;
	QProcess::execute(QStringLiteral("loadkeys %1").arg(keymap));	
	QProcess::execute(QStringLiteral("localectl set-keymap %1").arg(keymap));	
	QEglFSFunctions::loadKeymap(
		keymapDir.filePath(QStringLiteral("%1.map.gz").arg(keymap))
	);

	emit keyboardChanged();
}

void Locale::setZone(const QString &zone) {
	//TODO
}

QStringList Locale::keyboardsCache = QStringList();
QDir Locale::keymapDir = QDir(QStringLiteral("/usr/share/kbd/keymaps/i386/qwerty"));

QStringList Locale::allKeyboards() const {
	if(keyboardsCache.size() < 1) {
		keyboardsCache = keymapDir
			.entryList(QStringList() << "*.map.gz")
			.replaceInStrings(".map.gz", "");
	}
	return keyboardsCache;	
}