/*  Chaotic Installer Main View

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Rectangle {
    id: container
    width: 640
    height: 480

    LayoutMirroring.enabled: Qt.locale().textDirection == Qt.RightToLeft
    LayoutMirroring.childrenInherit: true

    Connections {
    }

    Image {
        anchors.fill: parent
        source: assetsPath + config.background
        fillMode: Image.PreserveAspectCrop
        clip: true
        focus: true
        smooth: true

        onStatusChanged: {
            if (status == Image.Error && source != config.defaultBackground) {
                source = config.defaultBackground
            }
        }
    }

    Material.theme: Material.Dark
    Material.accent: Material.Indigo

    Column {
        id: content
        anchors.centerIn: parent
        
        Button {
            text: qsTr("Hello World, I'm alive!")
            highlighted: true
            Material.accent: Material.Orange
        }
    }

}