#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>

class Config : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString background READ background NOTIFY backgroundChanged)
public:
    explicit Config(QObject *parent = nullptr) : QObject(parent) {}
    QString background() const;
signals:
    void backgroundChanged(QString &hostName);
};

#endif // CONFIG_H
