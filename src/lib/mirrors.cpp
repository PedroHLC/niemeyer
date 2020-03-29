/*  Niemeyer Repo's Mirrors
	(List URLs, toogle each one, sort as preferred)
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QProcess>
#include <QTextCodec>
#include <QTextStream>

#include "mirrors.hpp"

Mirrors::Mirrors(QObject *parent) : QObject (parent) {}

QList<MirrorEntry*> Mirrors::getMirrors() {
	if(mirrorsList.size() < 1) {
		QProcess process = QProcess();
		process.setReadChannel(QProcess::StandardOutput);
		process.start(QStringLiteral("grep -Po \"(?<=Server\\ =\\ ).*$\" /etc/pacman.d/mirrorlist"));

		QByteArray data;
		while(process.waitForFinished())
		    data.append(process.readAll());

		QStringList txtList = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
		txtList.removeAll(QString(""));

		for (const auto& url : txtList)
			mirrorsList << new MirrorEntry(url);
	}
	return mirrorsList;
}

MirrorEntry::MirrorEntry(QString nurl, QObject *parent) : QObject (parent), url(nurl), enabled(true) {}

QString MirrorEntry::getURL() {
	return url;
}
bool MirrorEntry::isEnabled() {
	return enabled;
}
void MirrorEntry::setEnabled(bool state) {
	enabled = state;

	emit toggled();
}

// that's not how I wanted to do this, but I don't want to do a QAbstractItemModel
// I'll be happy if you do it for me! 
QStringList Mirrors::getMirrorsURLs() {
	QStringList _;
	for (const auto item : getMirrors())
		_ << item->getURL();
	return _;
}

void Mirrors::setEnabled(int i, bool en) {
	mirrorsList.at(i)->setEnabled(en);
}

void Mirrors::move(int from, int to) {
	mirrorsList.move(from, to);
	//emit mirrorsChanged(); I HAD TO SILENCE THIS
}

void Mirrors::apply() {
	QFile file("/etc/pacman.d/mirrorlist");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
	for (const auto item : getMirrors())	
		out << (item->isEnabled() ? "Server = " : "# Server = ") << item->getURL() << "\n";
	file.close();
}