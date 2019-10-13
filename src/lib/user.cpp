#include <QDebug>

#include "user.hpp"

User::User(QObject *parent) : QObject(parent)
{

}

void User::setHostName(QString hostname) {
    hostName = hostname;
}

void User::setUserName(QString username) {
    userName = username;
}

void User::setUserPassword(QString password) {
    userPassword = password;
}

void User::setUserPasswordConfirm(QString passwordConfirm) {
    userPasswordConfirm = passwordConfirm;
}

void User::setRootPassword(QString password) {
    rootPassword = password;
}

void User::setRootPasswordConfirm(QString passwordConfirm) {
    rootPasswordConfirm = passwordConfirm;
}

void User::setError(QString errorMessage) {
    error = errorMessage;
    emit errorChanged();
}

void User::setIsValid(bool valid) {
    isValid = valid;
    emit validationChanged();
}

QString User::getHostName() {
    return hostName;
}

QString User::getUserName() {
    return userName;
}

QString User::getUserPassword() {
    return userPassword;
}

QString User::getUserPasswordConfirm() {
    return userPasswordConfirm;
}

QString User::getRootPassword() {
    return rootPassword;
}

QString User::getRootPasswordConfirm() {
    return rootPasswordConfirm;
}

QString User::getError() {
    return error;
}

bool User::getIsValid() {
    return isValid;
}

bool isEmpty(QString text) {
    return text.trimmed().size() == 0;
}

void User::validatePasswords(QString errorMessage, QString password, QString passwordConfirm) {
    bool passwordsEqual = password == passwordConfirm;

    if (!passwordsEqual) {
        setError(errorMessage);
        setIsValid(false);
    }
}

void User::validateField(QString errorMessage, QString text) {
    if (isEmpty(text)) {
        setError(errorMessage);
        setIsValid(false);
    }
}

void User::validateFields() {
    setError("");
    setIsValid(true);

    validatePasswords("User passwords don't match", userPassword, userPasswordConfirm);
    validatePasswords("Root passwords don't match", rootPassword, rootPasswordConfirm);

    validateField("User name should not be empty", userName);
    validateField("User password should not be empty", userPassword);
    validateField("User password should not be empty", userPasswordConfirm);

    validateField("Root password should not be empty", rootPassword);
    validateField("Root password should not be empty", rootPasswordConfirm);

    validateField("Host name should not be empty", hostName);
}
