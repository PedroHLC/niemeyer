/*  Chaotic Installer Ethernet Config Screen

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

            onCardsChanged: {
                ethIfacePicker.currentIndex = 0;
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
                            id: ethIfacePicker
                            model: net.cards
                            onActivated: net.setEthIface(currentIndex)
                        }
                    }
                }

                Row {
                    Button {
                        text: qsTr('Generate profile')
                        onClicked: net.genEthProfile();
                    }
                }

                Row {
                    id: ethProfileTextView
                    width: 480
                    height: 240
                    ScrollView {
                        anchors.top: parent.top
                        width: parent.width
                        height: parent.height
                        clip: true

                        contentWidth: ethProfileText.width
                        contentHeight: ethProfileText.height
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOn;
                            parent: ethProfileTextView
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.bottom: parent.bottom
                        }

                        TextArea {
                            id: ethProfileText
                            text: net.ethProfile
                            width: parent.width 
                            onEditingFinished: net.setEthProfile(text)
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
                        net.applyEthProfile();
                        contentStack.pop();
                    }
                }
            }
        }
    }
}