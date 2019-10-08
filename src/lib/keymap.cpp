#include <QProcess>
#include <QDebug>
#include <QtPlatformHeaders/QEglFSFunctions>

#include "keymap.hpp"

QDir Keymap::keymapDir = QDir(QStringLiteral("/usr/share/kbd/keymaps/i386/qwerty"));

Keymap::Keymap(QObject *parent) :
	QObject (parent) {}

QString Keymap::getSelectedKeyboard() {
    return selectedKeyboard;
}

void Keymap::setKeyboard(const QString &keymap) {
	qDebug() << "Setting keymap " << keymap;

	selectedKeyboard = keymap;
	QProcess::execute(QStringLiteral("loadkeys %1").arg(keymap));	
	QProcess::execute(QStringLiteral("localectl set-keymap %1").arg(keymap));	
	QEglFSFunctions::loadKeymap(
		keymapDir.filePath(QStringLiteral("%1.map.gz").arg(keymap))
	);

	emit keyboardChanged();
}

QStringList Keymap::allKeyboards() {
	if(keyboardsCache.size() < 1) {
		keyboardsCache = keymapDir
			.entryList(QStringList() << "*.map.gz")
			.replaceInStrings(".map.gz", "");
		emit allKeyboardsChanged();
	}

	return keyboardsCache;	
}