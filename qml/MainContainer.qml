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
    width: 800
    height: 600

    LayoutMirroring.enabled: Qt.locale().textDirection == Qt.RightToLeft
    LayoutMirroring.childrenInherit: true

    Image {
        anchors.fill: parent
        source: assetsPath + 'background.jpg'
        fillMode: Image.PreserveAspectCrop
        clip: true
        focus: true
        smooth: true
    }

    Rectangle {
        width: 640
        height: 480
        anchors.centerIn: parent
        color: Material.background
        
        Material.theme: Material.Light
        Material.accent: Material.Indigo

        StackView {
            id: contentStack
            anchors.fill: parent
            initialItem: languagePicker
        }
    }

    LanguagePicker { id: languagePicker }
}