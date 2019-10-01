/*  Chaotic Installer Language Picker Screen

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
            id: pickLangTitleRow
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            
            Text {
                text: qsTr('Select your install language:')
            }
        }
        Row {
            anchors.top: pickLangTitleRow.bottom
            anchors.bottom: pickLangActionRow.top
            width: parent.width
            
            //Flickable {
            ScrollView {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                //width: 480
                height: 480
                clip: true
                
                contentWidth: pickLangList.width
                contentHeight: pickLangList.height
                
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOn;
                    parent: parent.parent
                    anchors.top: parent.top
                    anchors.left: parent.right
                    anchors.bottom: parent.bottom
                }

                Column {
                    //width: parent.width
                    id: pickLangList

                    RadioButton {text: qsTr('English'); checked: true} 
                    RadioButton {text: qsTr('Bulgarian')}
                    RadioButton {text: qsTr('Dutch')}
                    RadioButton {text: qsTr('French')}
                    RadioButton {text: qsTr('German')}
                    RadioButton {text: qsTr('Greek')}
                    RadioButton {text: qsTr('Hungarian')}
                    RadioButton {text: qsTr('Indonesian')}
                    RadioButton {text: qsTr('Italian')}
                    RadioButton {text: qsTr('Latvian')}
                    RadioButton {text: qsTr('Lithuanian')}
                    RadioButton {text: qsTr('Polish')}
                    RadioButton {text: qsTr('Portuguese')}
                    RadioButton {text: qsTr('Portuguese (Brazilian)')}
                    RadioButton {text: qsTr('Romanian')}
                    RadioButton {text: qsTr('Russian')}
                    RadioButton {text: qsTr('Spanish')}
                    RadioButton {text: qsTr('Swedish')}
                }
            }
        }
        
        Row {
            id: pickLangActionRow
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                Button {
                    text: qsTr('Confirm')
                }
            }
        }
    }
}