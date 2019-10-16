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
                        text: qsTr("Resize")
                    }
                    TabButton {
                        text: qsTr("Move")
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
                                text: qsTr("Select partition: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: removePartition
                                model: disks.partitions
                                Layout.preferredWidth: 80
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
                                model: [qsTr("Recreate"), qsTr("Convert")]
                                Layout.preferredWidth: 120
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr(" device ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: tablesDevice
                                model: disks.devices
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr(" in ")
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
                                onClicked: disks.taskTables(tablesAction.currentIndex, tablesDevice.currentIndex, tablesType.currentText)
                            }
                        }
                    }
                    Item { // Resize
                        RowLayout {
                            anchors.fill: parent
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("Select partition: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: resizeEXTPartition
                                model: disks.extPartitions
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("and new end: ")
                            }
                            TextField {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: resizeEXTNewEnd
                                placeholderText: "0MB"
                                Layout.preferredWidth: 120
                            }
                            Column {
                                Layout.fillWidth: true
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskResize(resizeEXTPartition.currentIndex, resizeEXTNewEnd.text)
                            }
                        }
                    }
                    Item { // Move
                        RowLayout {
                            anchors.fill: parent
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("Select partition: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: movePartition
                                model: disks.partitions
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("and relocation: ")
                            }
                            TextField {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: moveNewEnd
                                placeholderText: "-/+7214MB"
                                Layout.preferredWidth: 120
                            }
                            Column {
                                Layout.fillWidth: true
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskMove(movePartition.currentIndex, moveNewEnd.text)
                            }
                        }
                    }
                    Item { // Create
                        RowLayout {
                            anchors.fill: parent
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: createDev
                                model: disks.devices
                                Layout.preferredWidth: 80
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: createType
                                model: ["primary", "extended", "logical"]
                                Layout.preferredWidth: 110
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: createFS
                                model: ["", "ext2", "fat32", "fat16", "HFS", "linux-swap", "NTFS", "reiserfs", "ufs"]
                                Layout.preferredWidth: 120
                            }
                            TextField {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: createBegin
                                placeholderText: "1000MB"
                                Layout.fillWidth: true
                                Layout.preferredWidth: 70
                            }
                            TextField {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: createEnd
                                placeholderText: "9000MB"
                                Layout.fillWidth: true
                                Layout.preferredWidth: 70
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskCreate(createDev.currentIndex, createType.text, createFS.text, createBegin.text, createEnd.text)
                            }
                        }
                    }
                    Item { // Flag
                        RowLayout {
                            anchors.fill: parent
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("Select partition: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: flagMinor
                                model: disks.partitions
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr(" and flag: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: flagFlag
                                model: ["boot", "lba", "root", "swap", "hidden", "raid", "LVM"]
                                Layout.preferredWidth: 120
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: flagState
                                model: ["off", "on"]
                                Layout.preferredWidth: 80
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskFlag(flagMinor.currentIndex, flagFlag.text, flagState.currentIndex == 1)
                            }
                        }
                    }
                    Item { // Format
                        RowLayout {
                            anchors.fill: parent
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr("Select partition: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: formatPartition
                                model: disks.partitions
                                Layout.preferredWidth: 80
                            }
                            Text {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                text: qsTr(" and new type: ")
                            }
                            ComboBox {
                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                id: formatTarget
                                model: ["BtrFS", "ExFAT", "EXT4", "FAT32", "NTFS", "F2FS"]
                                Layout.preferredWidth: 120
                            }
                            Column {
                                Layout.fillWidth: true
                            }
                            Button {
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                text: qsTr("Add Task")
                                onClicked: disks.taskFormat(formatPartition.currentIndex, formatTarget.currentIndex)
                            }
                        }
                    }
                }
            }
        }

        Text {
            text: qsTr("Tasks to apply: (Leave empty to delete)")
            Layout.leftMargin: 20
            Layout.rightMargin: 20
        }

        RowLayout {
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
                        model: disks.tasks

                        TextField {
                            anchors.topMargin: 0
                            Layout.fillWidth: true
                            Layout.rightMargin: 10
                            text: modelData
                            onEditingFinished: disks.setTask(index, text)
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
                    onClicked: disks.cleanTasks()
                }
                Button {
                    enabled: disks.tasks.size() >= 1
                    text: qsTr("Apply")
                    highlighted: true
                    onClicked: {
                        if(disks.genFinalScript())
                            contentStack.push(terminalRun, {command: "/tmp/partitionate.sh"});
                    }
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