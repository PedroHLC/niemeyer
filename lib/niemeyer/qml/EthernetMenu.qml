/*  Niemeyer Ethernet Config Screen

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.13

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

                RowLayout {
                    width: parent.width
                    spacing: 20
                    
                    Text {
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter 
                        text: qsTr('Select adapter: ')
                    }
                    
                    ComboBox {
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                        id: ethIfacePicker
                        model: net.cards
                        onActivated: net.setEthIface(currentIndex)
                    }

                    Column {
                        Layout.fillWidth: true
                    }

                    Button {
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        text: qsTr('Generate profile')
                        highlighted: true
                        onClicked: net.genEthProfile();
                    }
                }

                Rectangle {
                    id: ethProfileTextView
                    width: 480
                    height: 220
                    border.width: 1
                    border.color: "lightgray"
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