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
        Connections {
            target: net

            onWifiAPsChanged: {
                apPicker.currentIndex = 0;
            }

            onWifiCardsChanged: {
                wifiIfacePicker.currentIndex = 0;
            }
        }

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
                            id: wifiIfacePicker
                            model: net.wifiCards
                            onActivated: net.setWifiIface(currentIndex)
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
                            id: apPicker
                            model: net.wifiAPs
                            onActivated: net.setWifiAP(currentIndex)
                        }
                    }
                    Column {
                        Button { text: qsTr('Refresh'); onClicked: net.scanWifi() }
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
                            passwordCharacter: "*"
                            echoMode: TextInput.Password
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
                    text: qsTr('View script && Apply')
                    highlighted: true
                }
            }
        }
    }
}