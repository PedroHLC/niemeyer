import QtQuick 2.0

import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.3

Component {
    ColumnLayout {
        spacing: 0
        RowLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true

            Column {
                RowLayout {
                    spacing: 50

                    Column {
                        spacing: 15

                        Row {
                            GroupBox {
                                title: qsTr("User settings")

                                Column {
                                    spacing: 10

                                    Row {
                                        Column {
                                            Row {
                                                Text {
                                                    text: qsTr("Name")
                                                }
                                            }

                                            Row {
                                                TextField {
                                                    onEditingFinished: {
                                                        user.setUserName(text);
                                                        user.validateFields();
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    Row {
                                        Column {
                                            Row {
                                                Text {
                                                    text: qsTr("Password")
                                                }
                                            }

                                            Row {
                                                TextField {
                                                    echoMode: TextInput.PasswordEchoOnEdit
                                                    onEditingFinished: {
                                                        user.setUserPassword(text);
                                                        user.validateFields();
                                                    }
                                                    passwordCharacter: "*"
                                                }
                                            }
                                        }
                                    }

                                    Row {
                                        Column {
                                            Row {
                                                Text {
                                                    text: qsTr("Confirm Password")
                                                }
                                            }

                                            Row {
                                                TextField {
                                                    echoMode: TextInput.Password
                                                    onEditingFinished: {
                                                        user.setUserPasswordConfirm(text);
                                                        user.validateFields();
                                                    }
                                                    passwordCharacter: "*"
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    Column {
                        Layout.fillHeight: true
                        spacing: 15

                        Row {
                            GroupBox {
                                title: qsTr("Root settings")

                                Column {
                                    spacing: 10

                                    Row {
                                        Column {
                                            Row {
                                                Text {
                                                    text: qsTr("Password")
                                                }
                                            }

                                            Row {
                                                TextField {
                                                    echoMode: TextInput.Password
                                                    onEditingFinished: {
                                                        user.setRootPassword(text);
                                                        user.validateFields();
                                                    }
                                                    passwordCharacter: "*"
                                                }
                                            }
                                        }
                                    }

                                    Row {
                                        Column {
                                            Row {
                                                Text {
                                                    text: qsTr("Confirm Password")
                                                }
                                            }

                                            Row {
                                                TextField {
                                                    echoMode: TextInput.Password
                                                    onEditingFinished: {
                                                        user.setRootPasswordConfirm(text);
                                                        user.validateFields();
                                                    }
                                                    passwordCharacter: "*"
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        Layout.fillWidth: true
                    }
                }
            }

        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            Column {
                Text {
                    text: qsTr("Hostname:")
                }
            }

            Column {
                TextField {
                    onEditingFinished: {
                        user.setHostName(text);
                        user.validateFields();
                    }
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.topMargin: 20

            Column {
                Layout.minimumHeight: 20
                Layout.minimumWidth: 100

                Text {
                    color: "#cf0606"
                    text: user.error
                }
            }
        }

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
                    enabled: user.isValid
                    highlighted: user.isValid
                    onClicked: contentStack.push(zonePicker)
                }
            }
        }



    }
}
