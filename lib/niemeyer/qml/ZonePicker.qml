/*  Niemeyer Timezone Picking Screen

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.3

Component {
	ColumnLayout {
        RowLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            Text {
                text: qsTr("Select system's clock timezone:")
            }
        }

		RowLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlighVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            ScrollView {
                anchors.fill: parent
                clip: true
                
                contentWidth: zoneList.width
                contentHeight: zoneList.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    parent: zoneListView
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                ListView {
                    id: zoneList
                    width: parent.width
                    model: zones.paths
                    delegate: RadioButton {
                        text: modelData
                        onClicked: zones.selectedIndex = index
                    }
                }
            } 
        }
        RowLayout {
            spacing: 80
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.topMargin: 20
            Layout.bottomMargin: 20
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            
            Column {
                Button {
                    text: qsTr("Back")
                    onClicked: contentStack.pop()
                }
            }

            Column {
                Button {
                    text: qsTr("Next")
                    highlighted: true
                    onClicked: contentStack.push(pkgSelect)
                }
            }
        }
    }
}