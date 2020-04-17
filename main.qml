import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2

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
        Keys.onPressed: {
            switch (event.key) {
                case Qt.Key_Up:
                    jeu.move_up();
                    break;
                case Qt.Key_Down:
                    jeu.move_down();
                    break;
                case Qt.Key_Left:
                    jeu.move_left();
                    break;
                case Qt.Key_Right:
                    jeu.move_right();
                    break;
            }
        }



        Rectangle {
            id: zone00
            x: 10
            y: 10
            width:80
            height:80
            color:"#e6e08c"


            Text {
                id: texte00
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case00
            }
        }

        Rectangle {
            id: zone01
            x: 110
            y: 10
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte01
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case01
            }
        }

        Rectangle {
            id: zone02
            x: 210
            y: 10
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte02
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case02
            }
        }

        Rectangle {
            id: zone03
            x: 310
            y: 10
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte03
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case03
            }
        }

        Rectangle {
            id: zone10
            x: 10
            y: 110
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte10
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case10
            }
        }

        Rectangle {
            id: zone11
            x: 110
            y: 110
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte11
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case11
            }
        }

        Rectangle {
            id: zone12
            x: 210
            y: 110
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte12
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case12
            }
        }

        Rectangle {
            id: zone13
            x: 310
            y: 110
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte13
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case13
            }
        }

        Rectangle {
            id: zone20
            x: 10
            y: 210
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte20
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case20
            }
        }

        Rectangle {
            id: zone21
            x: 110
            y: 210
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte21
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case21
            }
        }

        Rectangle {
            id: zone22
            x: 210
            y: 210
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte22
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case22
            }
        }

        Rectangle {
            id: zone23
            x: 310
            y: 210
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte23
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case23
            }
        }

        Rectangle {
            id: zone30
            x: 10
            y: 310
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte30
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case30
            }
        }

        Rectangle {
            id: zone31
            x: 110
            y: 310
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte31
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case31
            }
        }

        Rectangle {
            id: zone32
            x: 210
            y: 310
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte32
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case32
            }
        }

        Rectangle {
            id: zone33
            x: 310
            y: 310
            width:80
            height:80
            color:"#e6e08c"

            Text {
                id: texte33
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case33
            }
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
        Keys.onPressed: {
            switch (event.key) {
                case Qt.Key_Up:
                    jeu.move_up();
                    break;
                case Qt.Key_Down:
                    jeu.move_down();
                    break;
                case Qt.Key_Left:
                    jeu.move_left();
                    break;
                case Qt.Key_Right:
                    jeu.move_right();
                    break;
            }
        }


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
            onClicked: jeu.nouvellePartie()
        }
    }
}
