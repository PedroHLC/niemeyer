/*  Chaotic Installer Network Config Screen

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
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr('Set your network!')
                    }
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr('You\'re currently: %1'.arg(net.available ? qsTr('ONLINE') : qsTr('OFFLINE')))
                    } 
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    visible: net.wifiCardExists

                    Button {
                        text: qsTr('Select Wireless AP')
                        onClicked: contentStack.push(wifiMenu)
                    }
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button {
                        text: qsTr('Configure Ethernet')
                        onClicked: contentStack.push(ethMenu)
                    }
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr('* In both options you\'ll find a form that will be used for generating a netctl profile,\nthis profile can be manually edited before starting it.')
                    } 
                }
            }
        }

        Row {
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
                visible: net.available
                Button {
                    text: qsTr('Next')
                    highlighted: true
                    onClicked: contentStack.push(mirrorsSort)
                }
            }

            Column {
                visible: !net.available
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    text: qsTr('Network required')
                }
            }
        }
    }
}