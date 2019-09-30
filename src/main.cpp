
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

#include "chaotic-installer.hpp"
#include "config.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QUrl appPath(app.applicationDirPath());
    
    QQuickView view;
    QQmlContext *context = view.rootContext();
    
    // Components
    Config * m_config = new Config(&view);

    // Context props
    context->setContextProperty(QStringLiteral("config"), m_config);
    context->setContextProperty("assetsPath", appPath.resolved(QStringLiteral(ASSETS_PATH)));
    
    // Show view
    view.setSource(appPath.resolved(QStringLiteral(QML_PATH "Welcome.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
