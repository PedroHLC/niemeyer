/*  Niemeyer Packages Select Screen

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
		// TODO
        RowLayout {
            spacing: 80
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.topMargin: 20
            Layout.bottomMargin: 20

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
                    onClicked: contentStack.push(scriptsReviewRun)
                }
            }
        }
    }
}