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
            model: allMirrors
            delegate: MouseArea {
                anchors { left: parent.left; right: parent.right }
                height: mainContent.height

                id: draggable
                property bool held: false
                property real lastY
                drag.target: held ? draggable : undefined
                drag.axis: Drag.YAxis
                pressAndHoldInterval: 150
                onPressAndHold: if(!held) {
                    lastY = y
                    held = true
                }
                onReleased: {
                    held = false
                    backAnimY.from = draggable.y
                    backAnimY.to = lastY
                    backAnim.start()
                }
                z: held ? 2 : 1
                    
                Drag.active: held
                Drag.source: draggable

                Row {
                    id: mainContent
                    spacing: 20

                    anchors.leftMargin: 20
                    Text {
                        text: "⇅"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    CheckBox {
                        text: modelData.url
                        checked: modelData.enabled
                    }
                }

                DropArea {
                    anchors.fill: parent
                    onEntered: {
                        var entering = drag.source
                        var over = draggable
                        if (over != entering) {
                            entering.lastY = over.y
                            mirrorsDelg.items.move(entering.DelegateModel.itemsIndex, over.DelegateModel.itemsIndex)
                        }
                    }
                }

                ParallelAnimation {
                    id: backAnim
                    SpringAnimation { id: backAnimY; target: draggable; property: "y"; duration: 500; spring: 2; damping: 0.2 }
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