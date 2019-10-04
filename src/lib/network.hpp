#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QDir>

class Network : public QObject {
	Q_OBJECT
	Q_PROPERTY(bool available READ getAvailability NOTIFY availabilityChanged)
	Q_PROPERTY(bool wifiCardExists READ getWifiCardsExists NOTIFY wifiCardsChanged)
	Q_PROPERTY(QStringList wifiCards READ getWifiCards NOTIFY wifiCardsChanged)
	Q_PROPERTY(QStringList wifiAPs READ getWifiAPs NOTIFY wifiAPsChanged)
	//Q_PROPERTY(QString selectedWifiIface READ getWifiIface WRITE setWifiIface NOTIFY wifiCardsChanged)
	//Q_PROPERTY(QString selectedWifiAP READ getWifiSSID WRITE setWifiAP NOTIFY wifiAPsChanged)

private:
	static QDir interfacesDir;
	QStringList cardsCache;
	QStringList wifiCardsCache;
	QStringList wifiAPs;
	QString wifiIface;
	QString wifiSSID;

public:
	explicit Network(QObject *parent = nullptr);

	bool getAvailability();
	bool getWifiCardsExists();

	QStringList getWifiAPs();
	QStringList getWifiCards();
	QStringList getCards();
	QString getWifiIface();

	void loadCards();

	Q_INVOKABLE void scanWifi();
	Q_INVOKABLE void setWifiAP(int ap_i);
	Q_INVOKABLE void setWifiIface(int iface_i);

signals:
	void availabilityChanged();
	void wifiAPsChanged();
	void wifiCardsChanged();
};

#endif // NETWORK_H