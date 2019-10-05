/*  Chaotic Installer Mirrors Sorting Screen

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

        DelegateModel {
            id: mirrorsDelg
            model: [ "Mirror 1", "Mirror 2", "Mirror 3" ]
            delegate: MouseArea {
                id: dragArea

                anchors { left: parent.left; right: parent.right }
                height: content.height

                property bool held: false
                drag.target: held ? content : undefined
                drag.axis: Drag.YAxis
                pressAndHoldInterval: 200
                onPressAndHold: held = true
                onReleased: held = false
            
                Rectangle {
                    id:content
                    Drag.active: dragArea.held
                    Drag.source: dragArea
                    height: 40
                    width: parent.width
                    
                    CheckBox { checked: true; text: modelData }
                }

                DropArea {
                    anchors { fill: parent; margins: 10 }

                    onEntered: mirrorsDelg.items.move(
                        drag.source.DelegateModel.itemsIndex,
                        dragArea.DelegateModel.itemsIndex)
                }
            }
        }

        Row {
            id: mirrorsHeader
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

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button {
                        text: qsTr('Benchmark and sort')
                    }
                }
           }
        }

        Row {
            id: mirrorListView
            anchors.top: mirrorsHeader.bottom
            anchors.bottom: mirrorsFooter.top
            anchors.left: parent.left
            anchors.right: parent.right
            ScrollView {
                anchors.fill:parent
                clip: true
                
                contentWidth: mirrorList.width
                contentHeight: mirrorList.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    parent: mirrorListView
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                ListView {
                    id: mirrorList
                    width: parent.width
                    model: mirrorsDelg
                }
            }
        }

        Row {
            id: mirrorsFooter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
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