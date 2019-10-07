#include <QDebug>
#include <QProcess>
#include <QTextCodec>
#include <QTextStream>

#include "locales.hpp"

Locales::Locales(QObject *parent) : QObject (parent), selectedLANG("C") {}

QList<LocaleEntry*> Locales::getLocales() {
	if(localesList.size() < 1) {
		QProcess process = QProcess();
		process.setReadChannel(QProcess::StandardOutput);
		process.start(QStringLiteral("grep -Po \"(?<=^#|^)[a-z]+(?:_[A-Z]+)?(?:@[a-z]+|.[A-Z0-9-]+)? [A-Z0-9-]+\" /etc/locale.gen"));

		QByteArray data;
		while(process.waitForFinished())
		    data.append(process.readAll());

		QStringList txtList = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
		txtList.removeAll(QString(""));

		for (const auto& code : txtList)
			localesList << new LocaleEntry(code);

		emit langsChanged();
	}
	return localesList;
}

LocaleEntry::LocaleEntry(QString ncode, QObject *parent) : QObject (parent), code(ncode), enabled(false) {}

QString LocaleEntry::getCode() {
	return code;
}

QString LocaleEntry::getLANG() {
	if(langCode.size() < 1) {
		langCode = QString(code);
		langCode.remove(QRegExp(" [A-Z0-9-]+"));	
	}
	return langCode;
}

bool LocaleEntry::isEnabled() {
	return enabled;
}
void LocaleEntry::setEnabled(bool state) {
	enabled = state;

	emit toggled();
}

// that's not how I wanted to do this, but I don't want to do a QAbstractItemModel
// I'll be happy if you do it for me! 
QStringList Locales::getLocalesCodes() {
	QStringList _;
	for (const auto item : getLocales())
		_ << item->getCode();
	return _;
}

void Locales::setEnabled(int i, bool en) {
	localesList.at(i)->setEnabled(en);
	selectedLANG = "C";
	emit langsChanged();
}

void Locales::apply() {
	QFile file("/mnt/etc/locale.gen");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
	for (const auto item : getLocales())	
		out << (item->isEnabled() ? "" : "#") << item->getCode() << "\n";
	file.close();
}

QStringList Locales::getAvailableLANGs() {
	QStringList _;
	_ << "C";
	for (const auto item : getLocales())
		if(item->isEnabled())
			_ << item->getLANG();
	return _;
}

QString Locales::getLANG() {
	return selectedLANG;
}

void Locales::setLANG(int lang_i) {
	selectedLANG = getAvailableLANGs().at(lang_i);
}