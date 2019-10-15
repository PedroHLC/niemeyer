/*  Chaotic Installer Disks Wizard Container

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.11

Component {
    ColumnLayout {
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        spacing: 20

        Text {
            Layout.topMargin: 20
            text: qsTr("Current situation:")
            Layout.leftMargin: 20
            Layout.rightMargin: 20
        }

        Rectangle {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: -20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            Layout.preferredHeight: 90
            border.color: "lightgray"
            border.width: 1
            
            ScrollView {
                anchors.fill: parent
                clip: true

                contentWidth: partedContent.width
                contentHeight: partedContent.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                TextArea {
                    id: partedContent
                    text: disks.partedListOutput
                    readOnly: true 
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            Layout.fillHeight: false
            Layout.preferredHeight: disksTasksTabs.height
            Layout.fillWidth: true
            border.color: "lightgray"
            border.width: 1
            clip: true

            ColumnLayout {
                id: disksTasksTabs
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 1
                spacing: 10
                
                TabBar {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    Layout.fillWidth: true
                    id: bar
                    TabButton {
                        text: qsTr("Remove")
                    }
                    TabButton {
                        text: qsTr("Tables")
                    }
                    TabButton {
                        text: qsTr("Shrink")
                    }
                    TabButton {
                        text: qsTr("Move")
                    }
                    TabButton {
                        text: qsTr("Grow")
                    }
                    TabButton {
                        text: qsTr("Create")
                    }
                    TabButton {
                        text: qsTr("Flags")
                    }
                    TabButton {
                        text: qsTr("Format")
                    }
                }
                
                StackLayout {
                    currentIndex: bar.currentIndex
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    Layout.bottomMargin: 10
                    Layout.preferredHeight: 40
                    Item { // Remove
                        RowLayout {
                            anchors.fill: parent
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: "select partition: "
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: removePartition
                                model: ["sda1", "sda2", "sda3"] // disks.partitions
                            }
                            Column {
                                Layout.fillWidth: true
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskDelete(removePartition.currentIndex)
                            }
                        }
                    } 
                    Item { // Tables
                        RowLayout {
                            anchors.fill: parent
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: tablesAction
                                model: ["Recreate", "Convert"]
                                Layout.preferredWidth: 120
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: " device "
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: tablesDevice
                                model: ["sda", "sdb"] // disks.devices
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: " in "
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: tablesType
                                model: ["GPT", "DOS"]
                                Layout.preferredWidth: 80
                            }
                            Column {
                                Layout.fillWidth: true
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskTables(tablesAction.currentIndex, tablesDevice.currentIndex, tablesType.currentIndex)
                            }
                        }
                    }
                }
            }
        }

        Text {
            text: qsTr("Tasks to apply:")
            Layout.leftMargin: 20
            Layout.rightMargin: 20
        }

        RowLayout {
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.topMargin: -20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            Layout.preferredHeight: 80
            
            ScrollView {
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true

                contentWidth: width
                contentHeight: tasksContent.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                ColumnLayout {
                    width: parent.width
                    id: tasksContent
                    spacing: 1
                    
                    Repeater {
                        model: ["parted /dev/sda mktable GPT", "parted mkpart 61 0 91235", "mkfs.ext4 /dev/sda1" ]//disks.tasks

                        TextField {
                            anchors.topMargin: 0
                            Layout.fillWidth: true
                            text: modelData
                            //onEditingFinished: disks.setTask(index, text)
                        }
                    }
                }
            }

            ColumnLayout {
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.fillWidth: false
                spacing: 1
                Button {
                    text: qsTr("Reset")
                }
                Button {
                    text: qsTr("Apply")
                }
            }

        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.bottomMargin: 20
            spacing: 80

            Column {
                Button {
                    text: qsTr("Back")
                    onClicked: contentStack.pop()
                }
            }

            Column {
                Button {
                    text: qsTr("Next (Mountpoints)")
                    highlighted: true
                    onClicked: contentStack.push(fsTab)
                }
            }
        }
    }
}