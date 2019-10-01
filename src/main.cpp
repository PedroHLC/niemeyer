
/*  Chaotic Installer Top Wrapper
    
    Copyright (C) 2019 Pedro Henrique Lara Campos <root@pedrohlc.com>

    License: GPL v2.0

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QQmlComponent>
#include <QQuickView>
#include <QTranslator>

#include "chaotic-installer.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QUrl appPath(app.applicationDirPath());
    
    // Get view and context
    QQuickView view;
    QQmlContext *context = view.rootContext();

    // Set translator
    QTranslator* translator = new QTranslator;
    translator->load(QStringLiteral("langs/pt-br.ts"));
    app.installTranslator(translator);

    // Debug locale
    QLocale::setDefault(QLocale(QLocale::Portuguese, QLocale::Brazil));
    qDebug() << QLocale().name();
    
    // Components
    //Component * m_compo = new Component(&view);

    // Context props
    //context->setContextProperty(QStringLiteral("compo"), m_compo);
    context->setContextProperty(QStringLiteral("assetsPath"), appPath.resolved(QStringLiteral(ASSETS_PATH)));
    
    // Show view
    view.setSource(appPath.resolved(QStringLiteral(QML_PATH "MainContainer.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
