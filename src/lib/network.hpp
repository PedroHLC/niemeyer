/*  Chaotic Installer Network Headers
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QDir>

class Network : public QObject {
	Q_OBJECT
	Q_PROPERTY(bool available READ getAvailability NOTIFY availabilityChanged)
	Q_PROPERTY(bool wifiCardExists READ getWifiCardsExists NOTIFY cardsChanged)
	Q_PROPERTY(QStringList cards READ getCards NOTIFY cardsChanged)
	Q_PROPERTY(QStringList wifiCards READ getWifiCards NOTIFY cardsChanged)
	Q_PROPERTY(QStringList wifiAPs READ getWifiAPs NOTIFY wifiAPsChanged)
	Q_PROPERTY(QString wifiPassword READ getWifiPassword WRITE setWifiPassword NOTIFY wifiPasswordChanged)
	Q_PROPERTY(QString wifiProfile READ getWifiProfile WRITE setWifiProfile NOTIFY wifiProfileChanged)
	Q_PROPERTY(QString ethProfile READ getEthProfile WRITE setEthProfile NOTIFY ethProfileChanged)

private:
	static QDir interfacesDir;
	QStringList cardsCache;
	QStringList wifiCardsCache;
	QStringList wifiAPs;
	QString wifiIface;
	QString wifiSSID;
	QString wifiPsw;
	QString wifiProfile;
	QString ethIface;
	QString ethProfile;

	void applyProfile(QString);

public:
	explicit Network(QObject *parent = nullptr);

	bool getAvailability();
	bool getWifiCardsExists();

	QStringList getWifiAPs();
	QStringList getWifiCards();
	QStringList getCards();
	QString getWifiIface();
	QString getWifiPassword();
	QString getWifiProfile();
	QString getEthIface();
	QString getEthProfile();

	Q_INVOKABLE void loadCards();
	Q_INVOKABLE void scanWifi();
	Q_INVOKABLE void setWifiAP(int ap_i);
	Q_INVOKABLE void setWifiIface(int iface_i);
	Q_INVOKABLE void setWifiPassword(QString password);
	Q_INVOKABLE void setWifiProfile(QString script);
	Q_INVOKABLE void genWifiProfile();
	Q_INVOKABLE void applyWifiProfile();
	Q_INVOKABLE void setEthIface(int iface_i);
	Q_INVOKABLE void setEthProfile(QString script);
	Q_INVOKABLE void genEthProfile();
	Q_INVOKABLE void applyEthProfile();

signals:
	void availabilityChanged();
	void cardsChanged();
	void wifiAPsChanged();
	void wifiPasswordChanged();
	void wifiProfileChanged();
	void ethProfileChanged();
};

#endif // NETWORK_H