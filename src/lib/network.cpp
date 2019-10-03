#include <QDebug>

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

QStringList Network::getWifiCards() {
	return wifiCardsCache;
}

QStringList Network::getCards() {
	return cardsCache;
}

QDir Network::interfacesDir = QDir(QStringLiteral("/sys/class/net"));

void Network::loadCards() {
	cardsCache = interfacesDir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs);
	wifiCardsCache = interfacesDir.entryList(QStringList() << "w*", QDir::NoDotAndDotDot|QDir::AllDirs);

	qDebug() << "Found interfaces: " << cardsCache;
	qDebug() << "Found wireless interfaces: " << wifiCardsCache;
	emit wifiCardsChanged();
}