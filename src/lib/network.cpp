#include "network.hpp"

Network::Network(QObject *parent) :
	QObject (parent) {}

bool Network::getAvailability()
{
    return false;
}

bool Network::getWifiCardsExists()
{
    return true;
}
