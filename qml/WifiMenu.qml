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

            onCardsChanged: {
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
                            echoMode: TextInput.PasswordEchoOnEdit
                            onEditingFinished: net.setWifiPassword(text)
                            text: net.wifiPassword
                        }
                    }
                }

                Row {
                    Button {
                        text: qsTr('Generate profile')
                        onClicked: net.genWifiProfile();
                    }
                }

                Row {
                    id: wifiProfileTextView
                    width: 480
                    height: 90
                    ScrollView {
                        anchors.top: parent.top
                        width: parent.width
                        height: parent.height
                        clip: true

                        contentWidth: wifiProfileText.width
                        contentHeight: wifiProfileText.height
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOn;
                            parent: wifiProfileTextView
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.bottom: parent.bottom
                        }

                        TextArea {
                            id: wifiProfileText
                            text: net.wifiProfile
                            width: parent.width 
                            onEditingFinished: net.setWifiProfile(text)
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
                    text: qsTr('Apply')
                    highlighted: true
                    onClicked: {
                        net.applyWifiProfile();
                        contentStack.pop();
                    }
                }
            }
        }
    }
}