#ifndef LOCALE_H
#define LOCALE_H

#include <QObject>
#include <QDir>

class Locale : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString selectedKeyboard READ getSelectedKeyboard WRITE setKeyboard NOTIFY keyboardChanged)
	Q_PROPERTY(QStringList selectedLocales READ getSelectedLocales NOTIFY localesChanged)
	Q_PROPERTY(QString selectedZone READ getSelectedZone WRITE setZone NOTIFY zoneChanged)

private:
	QString selectedKeyboard;
	QStringList selectedLocales;
	QString selectedZone;
	static QStringList keyboardsCache;
	static QDir keymapDir;

public:
	explicit Locale(QObject *parent = nullptr);

	void setKeyboard(const QString &keymap);
	void setZone(const QString &locale);
	Q_INVOKABLE void toggleLocale(const QString locale);

	QStringList allKeyboards() const;
	QString getSelectedKeyboard();
	QStringList getSelectedLocales();
	QString getSelectedZone();
signals:
	void keyboardChanged();
	void localesChanged();
	void zoneChanged();
};

#endif // LOCALE_H