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
                text: qsTr('Pedro has no ideia what he\'s doing')
            }
        }
        Row {
            anchors.top: pickLangTitleRow.bottom
            anchors.bottom: pickLangActionRow.top
            width: parent.width
            
            Flickable {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: 480
                clip: true
                flickableDirection: Flickable.VerticalFlick
                
                ScrollBar.vertical: ScrollBar{ policy: ScrollBar.AlwaysOn }
                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    RadioButton {text: qsTr('English')} 
                    RadioButton {text: qsTr('Portuguese')} 
                    RadioButton {text: qsTr('Spanish')} 
                    RadioButton {text: qsTr('French')} 
                    RadioButton {text: qsTr('Italian')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')}
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')} 
                    RadioButton {text: qsTr('????????')}
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
                    text: qsTr('That\'s what I want')
                }
            }
        }
    }
}