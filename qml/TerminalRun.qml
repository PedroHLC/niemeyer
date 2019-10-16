/*  Chaotic Installer Scripts Reviewing & Run Screen

    I like to write this by hand, do whatever you want, but keep diff clean to read, so I
    can keep writing it manually.

    Also, consider this file copyright-free.
*/

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.3
import QMLTermWidget 1.0

Component {
    QMLTermWidget {
        id: terminal
        anchors.fill: parent
        property string command
        session: QMLTermSession{
            initialWorkingDirectory: "$HOME" 
            shellProgram: terminal.command
        }
        QMLTermScrollbar {
            terminal: terminal
            width: 20
            Rectangle {
                opacity: 0.4
                anchors.margins: 5
                radius: width * 0.5
                anchors.fill: parent
            }
        }
        Component.onCompleted: {
            session.startShellProgram(); 
            terminal.forceActiveFocus();
        }
    } 
}