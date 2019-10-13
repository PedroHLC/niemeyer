/*  Chaotic Installer Locales Selecting Screen

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.9
import QtQml.Models 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Component {
    Column {
        anchors.fill: parent
        anchors.leftMargin: 20
        anchors.rightMargin: 20

        Row {
            id: localesHeader
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                spacing: 20

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr('Select enabled locales:')
                    }
                }
           }
        }

        Row {
            id: localeListView
            anchors.top: localesHeader.bottom
            anchors.bottom: langPicker.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottomMargin: 20
            ScrollView {
                anchors.fill:parent
                clip: true
                
                contentWidth: localeList.width
                contentHeight: localeList.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    parent: localeListView
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                ListView {
                    id: localeList
                    width: parent.width
                    model: locales.codes
                    delegate: CheckBox {
                        text: modelData
                        checked: false
                        onClicked: locales.setEnabled(index, checked)
                    }
                }
            }
        }

        Row {
            id: langPicker
            anchors.bottom: localesFooter.top
            anchors.bottomMargin: 20

            Column {
                anchors.verticalCenter: parent.verticalCenter
                Text { text: qsTr('Select system language: ') }
            }
            Column {
                ComboBox {
                    model: locales.langs
                    onActivated: locales.setLANG(currentIndex)
                }
            }
        }

        Row {
            id: localesFooter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 80

            
            Button {
                text: qsTr('Back')
                onClicked: contentStack.pop()
            }
            
            Button {
                text: qsTr('Next')
                highlighted: true
                onClicked: contentStack.push(userSetup)
            }
        }
    }
}
