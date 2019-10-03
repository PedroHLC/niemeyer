#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QDir>

class Network : public QObject {
	Q_OBJECT
	Q_PROPERTY(bool available READ getAvailability NOTIFY availabilityChanged)
	Q_PROPERTY(bool wifiCardExists READ getWifiCardsExists NOTIFY wifiCardsChanged)

private:
	static QDir interfacesDir;
	QStringList cardsCache;
	QStringList wifiCardsCache;

public:
	explicit Network(QObject *parent = nullptr);

	bool getAvailability();
	bool getWifiCardsExists();

	QStringList getWifiCards();
	QStringList getCards();

	void loadCards();

signals:
	void availabilityChanged();
	void wifiCardsChanged();
};

#endif // NETWORK_H