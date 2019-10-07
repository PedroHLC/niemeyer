/*  Chaotic Installer Keyboard Picker Screen

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Component {
    Column {
        Row {
            id: pickKeyboardTitleRow
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            
            Text {
                text: qsTr('Select your key-map:\n\nIf unsure leave default')
            }
        }
        Row {
            id: pickKeyboardListView
            anchors.top: pickKeyboardTitleRow.bottom
            anchors.bottom: pickKeyboardActionRow.top
            anchors.bottomMargin: 20
            width: parent.width
            
            //Flickable {
            ScrollView {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                width: 320
                clip: true
                
                contentWidth: pickKeyboardList.width
                contentHeight: pickKeyboardList.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    parent: pickKeyboardListView
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                Column {
                    id: pickKeyboardList

                    Repeater {
                        model: keymap.allKeyboards

                        RadioButton {text: modelData; onClicked: keymap.selectedKeyboard = modelData }
                    }
                }
            }
        }
        
        Row {
            id: pickKeyboardActionRow
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 80

            Column {
                Button {
                    text: qsTr('Back')
                    onClicked: contentStack.pop()
                }
            }

            Column {
                TextField {
                    placeholderText: qsTr('Testing area')
                }
            }

            Column {
                Button {
                    text: qsTr('Next')
                    highlighted: true
                    onClicked: contentStack.push(networkUp)
                }
            }
        }
    }
}