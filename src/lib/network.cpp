/*  Niemeyer Network
        (Wifi Scan and Netctl's profile generator)

    Copyright (C) 2019-2020 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#include <QDebug>
#include <QProcess>
#include <QTextCodec>

#include "network.hpp"

Network::Network(QObject *parent) : QObject(parent) { loadCards(); }

bool Network::getAvailability() {
  return QProcess::execute("wget -q --spider http://google.com") == 0;
}

bool Network::getWifiCardsExists() { return wifiCardsCache.size() > 0; }

QStringList Network::getWifiAPs() { return wifiAPs; }

QStringList Network::getWifiCards() { return wifiCardsCache; }

QStringList Network::getCards() { return cardsCache; }

QString Network::getWifiIface() { return wifiIface; }

QString Network::getWifiProfile() { return wifiProfile; }

QString Network::getEthProfile() { return ethProfile; }

QString Network::getWifiPassword() { return wifiPsw; }

QDir Network::interfacesDir = QDir(QStringLiteral("/sys/class/net"));

void Network::loadCards() {
  cardsCache = interfacesDir.entryList(QStringList(),
                                       QDir::NoDotAndDotDot | QDir::AllDirs);

  wifiCardsCache = QStringList();
  QStringListIterator cardsI(cardsCache);
  while (cardsI.hasNext()) {
    QString iname = cardsI.next();
    QDir interface = QDir(interfacesDir);
    interface.cd(iname);
    if (interface.exists("wireless"))
      wifiCardsCache << iname;
  }

  qDebug() << "Found interfaces: " << cardsCache;
  qDebug() << "Found wireless interfaces: " << wifiCardsCache;

  if (wifiCardsCache.size() >= 1)
    setWifiIface(0);

  if (cardsCache.size() >= 1)
    setEthIface(0);

  emit cardsChanged();
}

void Network::scanWifi() {
  QProcess process = QProcess();
  process.setReadChannel(QProcess::StandardOutput);
  process.start(QStringLiteral("sudo bash -c \"cat `"
                               ". /usr/lib/netctl/globals;"
                               ". /usr/lib/netctl/wpa;"
                               "wpa_supplicant_scan '%1' 5`"
                               "\"")
                    .arg(wifiIface));

  QByteArray data;
  while (process.waitForFinished())
    data.append(process.readAll());

  wifiAPs = QTextCodec::codecForMib(106)->toUnicode(data.data()).split("\n");
  wifiAPs.removeAll(QString(""));

  if (wifiAPs.size() >= 1)
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

void Network::setWifiPassword(QString psw) {
  wifiPsw = psw;
  qDebug() << QString("%1 characters password was entered.").arg(psw.size());

  emit wifiPasswordChanged();
}

void Network::setWifiProfile(QString profile) {
  wifiProfile = profile;

  emit wifiProfileChanged();
}

void Network::genWifiProfile() {
  wifiProfile = QString("Interface=%1\n"
                        "Connection=wireless\n"
                        "Security=wpa\n"
                        "IP=dhcp\n"
                        "ESSID='%2'\n"
                        "Key=\"%3\"\n")
                    .arg(wifiIface)
                    .arg(wifiSSID)
                    .arg(wifiPsw);

  emit wifiProfileChanged();
}

void Network::applyWifiProfile() {
  if (wifiProfile.size() < 1)
    genWifiProfile();
  applyProfile(wifiProfile);
}

void Network::applyProfile(QString profileData) {
  QProcess::execute(QStringLiteral("netctl stop-all"));

  QFile proFile("/etc/netctl/niemeyer");
  if (!proFile.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
  proFile.write(profileData.toUtf8());
  proFile.close();

  QProcess::execute(QStringLiteral("netctl start niemeyer"));

  emit availabilityChanged();
}

void Network::setEthIface(int iface_i) { ethIface = cardsCache.at(iface_i); }

void Network::setEthProfile(QString profile) {
  ethProfile = profile;

  emit ethProfileChanged();
}

void Network::genEthProfile() {
  ethProfile = QString("Interface=%1\n"
                       "Connection=ethernet\n"
                       "IP=dhcp\n")
                   .arg(ethIface);

  emit ethProfileChanged();
}

void Network::applyEthProfile() {
  if (ethProfile.size() < 1)
    genEthProfile();
  applyProfile(ethProfile);
}
