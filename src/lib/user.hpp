/*  Chaotic Installer Users Headers
    
    Copyright (C) 2019 Vagner S. <vagnervst17@gmail.com>

    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef USER_HPP
#define USER_HPP

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString hostName READ getHostName WRITE setHostName)
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName)
    Q_PROPERTY(QString userPassword READ getUserPassword WRITE setUserPassword)
    Q_PROPERTY(QString userPasswordConfirm READ getUserPasswordConfirm WRITE setUserPasswordConfirm)
    Q_PROPERTY(QString rootPassword READ getRootPassword WRITE setRootPassword)
    Q_PROPERTY(QString rootPasswordConfirm READ getRootPasswordConfirm WRITE setRootPasswordConfirm)
    Q_PROPERTY(QString error READ getError NOTIFY errorChanged)
    Q_PROPERTY(bool isValid READ getIsValid NOTIFY validationChanged)

private:
    QString hostName;
    QString userName;
    QString userPassword;
    QString userPasswordConfirm;
    QString rootPassword;
    QString rootPasswordConfirm;
    QString error = "";
    bool isValid = false;

    void validatePasswords(QString errorMessage, QString password, QString passwordConfirm);
    void validateField(QString errorMessage, QString text);

public:
    explicit User(QObject *parent = nullptr);

    QString getHostName();
    QString getUserName();
    QString getUserPassword();
    QString getUserPasswordConfirm();
    QString getRootPassword();
    QString getRootPasswordConfirm();
    QString getError();
    bool getIsValid();

    Q_INVOKABLE void setHostName(QString hostname);
    Q_INVOKABLE void setUserName(QString username);
    Q_INVOKABLE void setUserPassword(QString password);
    Q_INVOKABLE void setUserPasswordConfirm(QString passwordConfirm);
    Q_INVOKABLE void setRootPassword(QString password);
    Q_INVOKABLE void setRootPasswordConfirm(QString passwordConfirm);
    Q_INVOKABLE void validateFields();
    void setError(QString errorMessage);
    void setIsValid(bool valid);

signals:
    void errorChanged();
    void validationChanged();
};

#endif // USER_HPP
