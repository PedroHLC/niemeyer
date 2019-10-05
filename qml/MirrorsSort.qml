/*  Chaotic Installer Mirrors Sorting Screen

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
                        text: qsTr('Sort pacman mirrors:')
                    }
                }
           }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            spacing: 80

            Column {
                Button {
                    text: qsTr('Cancel')
                    onClicked: contentStack.pop()
                }
            }
        }
    }
}