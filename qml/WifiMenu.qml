/*  Chaotic Installer Wireless Config Screen

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
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            
            Column {
                spacing: 20

                Row {
                    spacing: 20
                    
                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        Text { text: qsTr('Select adapter: ') }
                    }
                    Column {
                        ComboBox {
                            model: ['wlp1s0', 'wlp2s0']
                        }
                    }
                }

                Row {
                    spacing: 20

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        Text { text: qsTr('Select SSID: ') }
                    }
                    Column {
                        ComboBox {
                            model: ['#NET-CLARO-WIFI']
                        }
                    }
                    Column {
                        Button { text: qsTr('Refresh') }
                    }
                }

                Row {
                    spacing: 20
                    
                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        Text { text: qsTr('Password: ') }
                    }
                    Column {
                        TextField {
                            placeholderText: qsTr('WPA2 personal password only')
                        }
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
                id: pickKeyboardBackBtnCol
                Button {
                    text: qsTr('Cancel')
                    onClicked: contentStack.pop()
                }
            }

            Column {
                Button {
                    text: qsTr('Save && Return')
                    highlighted: true
                }
            }
        }
    }
}