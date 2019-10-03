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
            id: networkUpTitleRow
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: qsTr('Set your network!')
            }
        }

        Row {
            anchors.topMargin: 20
            anchors.top: networkUpTitleRow.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: qsTr('You\'re currently: ' + 'OFFLINE')
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
                Button {
                    text: qsTr('Next')
                    highlighted: true
                }
            }
        }
    }
}