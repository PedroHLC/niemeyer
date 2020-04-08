/*  Niemeyer Keymaps Headers

    Copyright (C) 2019-2020 Pedro Henrique Lara Campos <root@pedrohlc.com>
    Distributed under the GPL v2. For full terms see the file LICENSE.
*/

#ifndef KEYMAP_H
#define KEYMAP_H

#include <QDir>
#include <QObject>

class Keymap : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString selectedKeyboard READ getSelectedKeyboard WRITE setKeyboard
                 NOTIFY keyboardChanged)
  Q_PROPERTY(
      QStringList allKeyboards READ allKeyboards NOTIFY allKeyboardsChanged)

private:
  QString selectedKeyboard;
  QStringList keyboardsCache;
  static QDir keymapDir;

public:
  explicit Keymap(QObject *parent = nullptr);

  void setKeyboard(const QString &keymap);
  void setZone(const QString &locale);

  QStringList allKeyboards();
  QString getSelectedKeyboard();

signals:
  void keyboardChanged();
  void allKeyboardsChanged();
};

#endif // KEYMAP_H