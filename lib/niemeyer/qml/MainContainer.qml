/*  Niemeyer Main View

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.13

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
        id: contentPage
        width: 640
        height: 480
        clip: true
        anchors.centerIn: parent
        color: Material.background
        
        Material.theme: Material.Light
        Material.primary: Material.Grey
        Material.accent: Material.BlueGrey

        ToolBar {
            id: containerToolBar
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            
            RowLayout {
                anchors.fill: parent
                ToolButton {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    id: containerBack
                    text: "‹"
                    onClicked: contentStack.pop()
                }
                Label {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    text: "Niemeyer"
                }
                Column {
                    Layout.fillWidth: true
                }
                ToolButton {
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    text: "⋮"
                    onClicked: menu.open()
                    Menu {
                        id: menu
                        Action {
                            text: qsTr("Open Terminal")
                            onTriggered: contentStack.push(terminalRun)
                        }
                        MenuSeparator {}
                        Action {
                            text: "640x480"
                            onTriggered: {
                                contentPage.width = 640
                                contentPage.height = 480
                            }
                        }
                        Action {
                            text: "800x600"
                            enabled: (container.width >= 800 && container.height >= 600)
                            onTriggered: {
                                contentPage.width = 800
                                contentPage.height = 600
                            }
                        }
                        Action {
                            text: "1024x768"
                            enabled: (container.width >= 1024 && container.height >= 768)
                            onTriggered: {
                                contentPage.width = 1024
                                contentPage.height = 768
                            }
                        }
                        MenuSeparator {}
                        Action {
                            text: qsTr("Abort")
                            onTriggered: Qt.quit()
                        }
                    }
                }
            }
        }

        StackView {
            id: contentStack
            anchors.top: containerToolBar.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            initialItem: languagePicker
        }
    }

    LanguagePicker { id: languagePicker }
    KeyboardPicker { id: keyboardPicker }
    NetworkUp { id: networkUp }
    WifiMenu { id: wifiMenu }
    EthernetMenu { id: ethMenu }
    MirrorsSort { id: mirrorsSort }
    LocalesSelect { id: localesSelect }
    DisksWizard { id: disksWizard }
    MountPoints { id: fsTab }
    UserSetup { id: userSetup }
    ZonePicker { id: zonePicker }
    PkgSelect { id: pkgSelect }
    TerminalRun { id: terminalRun }
    Finalize { id: finalize }
}
