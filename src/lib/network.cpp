#include <QDebug>
#include <QProcess>
#include <QTextCodec>

#include "network.hpp"

Network::Network(QObject *parent) : QObject (parent) {
	loadCards();
}

bool Network::getAvailability() {
    return false;
}

bool Network::getWifiCardsExists() {
    return wifiCardsCache.size() > 0;
}

QStringList Network::getWifiAPs() {
	return wifiAPs;
}

QStringList Network::getWifiCards() {
	return wifiCardsCache;
}

QStringList Network::getCards() {
	return cardsCache;
}

QString Network::getWifiIface() {
	return wifiIface;
}

QDir Network::interfacesDir = QDir(QStringLiteral("/sys/class/net"));

void Network::loadCards() {
	cardsCache = interfacesDir.entryList(QStringList(), QDir::NoDotAndDotDot|QDir::AllDirs);
	
	wifiCardsCache = QStringList();
	QStringListIterator cardsI(cardsCache);
	while (cardsI.hasNext()) {
		QString iname = cardsI.next();
		QDir interface = QDir(interfacesDir);
		interface.cd(iname);
		if(interface.exists("wireless"))
			wifiCardsCache << iname;
	}

	qDebug() << "Found interfaces: " << cardsCache;
	qDebug() << "Found wireless interfaces: " << wifiCardsCache;

	if(wifiCardsCache.size() >= 1)
		setWifiIface(0);
	
	emit wifiCardsChanged();
}

void Network::scanWifi() {
	QProcess process = QProcess();
	process.setReadChannel(QProcess::StandardOutput);
	process.start(
			QStringLiteral(
				"sudo bash -c \"cat `"
					". /usr/lib/netctl/globals;"
					". /usr/lib/netctl/wpa;"
					"wpa_supplicant_scan '%1' 5`"
				"\""
			).arg(wifiIface)
		);

	QByteArray data;
	while(process.waitForFinished())
	    data.append(process.readAll());

	wifiAPs = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
	wifiAPs.removeAll(QString(""));

	if(wifiAPs.size() >= 1)
		setWifiAP(0);

	emit wifiAPsChanged();
}

void Network::setWifiIface(int iface_i) {
	wifiIface = wifiCardsCache.at(iface_i);
}

void Network::setWifiAP(int ap_i) {
	wifiSSID = wifiAPs.at(ap_i);
	qDebug() << "User selected " << wifiSSID;
}