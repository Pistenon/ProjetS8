import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 600
    height: 600
    color: "#ffffff"
    title: qsTr("2048")

    Rectangle {
        id: rectangle
        x: 100
        y: 100
        width: 400
        height: 400
        color: "#b9b7c4"

        Case {
            id: zone00
            x: 10
            y: 10
        }

        Case {
            id: zone01
            x: 110
            y: 10
        }

        Case {
            id: zone02
            x: 210
            y: 10
        }

        Case {
            id: zone03
            x: 310
            y: 10
        }

        Case {
            id: zone10
            x: 10
            y: 110
        }

        Case {
            id: zone11
            x: 110
            y: 110
        }

        Case {
            id: zone12
            x: 210
            y: 110
        }

        Case {
            id: zone13
            x: 310
            y: 110
        }

        Case {
            id: zone20
            x: 10
            y: 210
        }

        Case {
            id: zone21
            x: 110
            y: 210
        }

        Case {
            id: zone22
            x: 210
            y: 210
        }

        Case {
            id: zone23
            x: 310
            y: 210
        }

        Case {
            id: zone30
            x: 10
            y: 310
        }

        Case {
            id: zone31
            x: 110
            y: 310
        }

        Case {
            id: zone32
            x: 210
            y: 310
        }

        Case {
            id: zone33
            x: 310
            y: 310
        }
    }

    Rectangle {
        id: rectangle1
        x: 200
        y: 523
        width: 200
        height: 50
        color: "#b8b8b2"
        focus: true

        TextInput {
            id: nouvellePartie
            x: 0
            y: 0
            width: 200
            height: 50
            color: "#ffffff"
            text: "Nouvelle Partie"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Verdana"
            font.pixelSize: 25
        }

        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 200
            height: 50
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {}
        }
    }
}
