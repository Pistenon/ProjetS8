import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 600
    height: 600
    color: "#faf8ef"
    title: qsTr("2048")

    Rectangle {
        id: rectangle
        x: 100
        y: 100
        width: 400
        height: 400
        color: "#b9ada1"


        Rectangle {
            id: zone00
            x: 10
            y: 10
            width:80
            height:80
            color:"#cac0b4"


            Text {
                id: texte00
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case00
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte00.text){
                        case "":
                            zone00.color="#cac0b4";
                            break;
                        case "2":
                            zone00.color="#ede4db";
                            break;
                        case "4":
                            zone00.color="#ebdfc9";
                            break;
                        case "8":
                            zone00.color="#e9b280";
                            break;
                        case "16":
                            zone00.color="#f59563";
                            break;
                        case "32":
                            zone00.color="#e68469";
                            break;
                        case "64":
                            zone00.color="#e46b4c";
                            break;
                        case "128":
                            zone00.color="#eacc79";
                            break;
                        case "256":
                            zone00.color="#ecc961";
                            break;
                        case "512":
                            zone00.color="#e9c55b";
                            break;
                        case "1024":
                            zone00.color="#ecc440";
                            break;
                        case "2048":
                            zone00.color="#e7bf433";
                            break;
                        default:
                            zone00.color="#cac0b4";
                            break;
                    }
                }
            }



        }

        Rectangle {
            id: zone01
            x: 110
            y: 10
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte01
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case01
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte01.text){
                        case "":
                            zone01.color="#cac0b4";
                            break;
                        case "2":
                            zone01.color="#ede4db";
                            break;
                        case "4":
                            zone01.color="#ebdfc9";
                            break;
                        case "8":
                            zone01.color="#e9b280";
                            break;
                        case "16":
                            zone01.color="#f59563";
                            break;
                        case "32":
                            zone01.color="#e68469";
                            break;
                        case "64":
                            zone01.color="#e46b4c";
                            break;
                        case "128":
                            zone01.color="#eacc79";
                            break;
                        case "256":
                            zone01.color="#ecc961";
                            break;
                        case "512":
                            zone01.color="#e9c55b";
                            break;
                        case "1024":
                            zone01.color="#ecc440";
                            break;
                        case "2048":
                            zone01.color="#e7bf433";
                            break;
                        default:
                            zone01.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone02
            x: 210
            y: 10
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte02
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case02
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte02.text){
                        case "":
                            zone02.color="#cac0b4";
                            break;
                        case "2":
                            zone02.color="#ede4db";
                            break;
                        case "4":
                            zone02.color="#ebdfc9";
                            break;
                        case "8":
                            zone02.color="#e9b280";
                            break;
                        case "16":
                            zone02.color="#f59563";
                            break;
                        case "32":
                            zone02.color="#e68469";
                            break;
                        case "64":
                            zone02.color="#e46b4c";
                            break;
                        case "128":
                            zone02.color="#eacc79";
                            break;
                        case "256":
                            zone02.color="#ecc961";
                            break;
                        case "512":
                            zone02.color="#e9c55b";
                            break;
                        case "1024":
                            zone02.color="#ecc440";
                            break;
                        case "2048":
                            zone02.color="#e7bf433";
                            break;
                        default:
                            zone02.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone03
            x: 310
            y: 10
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte03
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case03
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte03.text){
                        case "":
                            zone03.color="#cac0b4";
                            break;
                        case "2":
                            zone03.color="#ede4db";
                            break;
                        case "4":
                            zone03.color="#ebdfc9";
                            break;
                        case "8":
                            zone03.color="#e9b280";
                            break;
                        case "16":
                            zone03.color="#f59563";
                            break;
                        case "32":
                            zone03.color="#e68469";
                            break;
                        case "64":
                            zone03.color="#e46b4c";
                            break;
                        case "128":
                            zone03.color="#eacc79";
                            break;
                        case "256":
                            zone03.color="#ecc961";
                            break;
                        case "512":
                            zone03.color="#e9c55b";
                            break;
                        case "1024":
                            zone03.color="#ecc440";
                            break;
                        case "2048":
                            zone03.color="#e7bf433";
                            break;
                        default:
                            zone03.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone10
            x: 10
            y: 110
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte10
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case10
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte10.text){
                        case "":
                            zone10.color="#cac0b4";
                            break;
                        case "2":
                            zone10.color="#ede4db";
                            break;
                        case "4":
                            zone10.color="#ebdfc9";
                            break;
                        case "8":
                            zone10.color="#e9b280";
                            break;
                        case "16":
                            zone10.color="#f59563";
                            break;
                        case "32":
                            zone10.color="#e68469";
                            break;
                        case "64":
                            zone10.color="#e46b4c";
                            break;
                        case "128":
                            zone10.color="#eacc79";
                            break;
                        case "256":
                            zone10.color="#ecc961";
                            break;
                        case "512":
                            zone10.color="#e9c55b";
                            break;
                        case "1024":
                            zone10.color="#ecc440";
                            break;
                        case "2048":
                            zone10.color="#e7bf433";
                            break;
                        default:
                            zone10.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone11
            x: 110
            y: 110
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte11
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case11
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte11.text){
                        case "":
                            zone11.color="#cac0b4";
                            break;
                        case "2":
                            zone11.color="#ede4db";
                            break;
                        case "4":
                            zone11.color="#ebdfc9";
                            break;
                        case "8":
                            zone11.color="#e9b280";
                            break;
                        case "16":
                            zone11.color="#f59563";
                            break;
                        case "32":
                            zone11.color="#e68469";
                            break;
                        case "64":
                            zone11.color="#e46b4c";
                            break;
                        case "128":
                            zone11.color="#eacc79";
                            break;
                        case "256":
                            zone11.color="#ecc961";
                            break;
                        case "512":
                            zone11.color="#e9c55b";
                            break;
                        case "1024":
                            zone11.color="#ecc440";
                            break;
                        case "2048":
                            zone11.color="#e7bf433";
                            break;
                        default:
                            zone11.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone12
            x: 210
            y: 110
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte12
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case12
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte12.text){
                        case "":
                            zone12.color="#cac0b4";
                            break;
                        case "2":
                            zone12.color="#ede4db";
                            break;
                        case "4":
                            zone12.color="#ebdfc9";
                            break;
                        case "8":
                            zone12.color="#e9b280";
                            break;
                        case "16":
                            zone12.color="#f59563";
                            break;
                        case "32":
                            zone12.color="#e68469";
                            break;
                        case "64":
                            zone12.color="#e46b4c";
                            break;
                        case "128":
                            zone12.color="#eacc79";
                            break;
                        case "256":
                            zone12.color="#ecc961";
                            break;
                        case "512":
                            zone12.color="#e9c55b";
                            break;
                        case "1024":
                            zone12.color="#ecc440";
                            break;
                        case "2048":
                            zone12.color="#e7bf433";
                            break;
                        default:
                            zone12.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone13
            x: 310
            y: 110
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte13
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case13
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte13.text){
                        case "":
                            zone13.color="#cac0b4";
                            break;
                        case "2":
                            zone13.color="#ede4db";
                            break;
                        case "4":
                            zone13.color="#ebdfc9";
                            break;
                        case "8":
                            zone13.color="#e9b280";
                            break;
                        case "16":
                            zone13.color="#f59563";
                            break;
                        case "32":
                            zone13.color="#e68469";
                            break;
                        case "64":
                            zone13.color="#e46b4c";
                            break;
                        case "128":
                            zone13.color="#eacc79";
                            break;
                        case "256":
                            zone13.color="#ecc961";
                            break;
                        case "512":
                            zone13.color="#e9c55b";
                            break;
                        case "1024":
                            zone13.color="#ecc440";
                            break;
                        case "2048":
                            zone13.color="#e7bf433";
                            break;
                        default:
                            zone13.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone20
            x: 10
            y: 210
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte20
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case20
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte20.text){
                        case "":
                            zone20.color="#cac0b4";
                            break;
                        case "2":
                            zone20.color="#ede4db";
                            break;
                        case "4":
                            zone20.color="#ebdfc9";
                            break;
                        case "8":
                            zone20.color="#e9b280";
                            break;
                        case "16":
                            zone20.color="#f59563";
                            break;
                        case "32":
                            zone20.color="#e68469";
                            break;
                        case "64":
                            zone20.color="#e46b4c";
                            break;
                        case "128":
                            zone20.color="#eacc79";
                            break;
                        case "256":
                            zone20.color="#ecc961";
                            break;
                        case "512":
                            zone20.color="#e9c55b";
                            break;
                        case "1024":
                            zone20.color="#ecc440";
                            break;
                        case "2048":
                            zone20.color="#e7bf433";
                            break;
                        default:
                            zone20.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone21
            x: 110
            y: 210
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte21
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case21
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte21.text){
                        case "":
                            zone21.color="#cac0b4";
                            break;
                        case "2":
                            zone21.color="#ede4db";
                            break;
                        case "4":
                            zone21.color="#ebdfc9";
                            break;
                        case "8":
                            zone21.color="#e9b280";
                            break;
                        case "16":
                            zone21.color="#f59563";
                            break;
                        case "32":
                            zone21.color="#e68469";
                            break;
                        case "64":
                            zone21.color="#e46b4c";
                            break;
                        case "128":
                            zone21.color="#eacc79";
                            break;
                        case "256":
                            zone21.color="#ecc961";
                            break;
                        case "512":
                            zone21.color="#e9c55b";
                            break;
                        case "1024":
                            zone21.color="#ecc440";
                            break;
                        case "2048":
                            zone21.color="#e7bf433";
                            break;
                        default:
                            zone21.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone22
            x: 210
            y: 210
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte22
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case22
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte22.text){
                        case "":
                            zone22.color="#cac0b4";
                            break;
                        case "2":
                            zone22.color="#ede4db";
                            break;
                        case "4":
                            zone22.color="#ebdfc9";
                            break;
                        case "8":
                            zone22.color="#e9b280";
                            break;
                        case "16":
                            zone22.color="#f59563";
                            break;
                        case "32":
                            zone22.color="#e68469";
                            break;
                        case "64":
                            zone22.color="#e46b4c";
                            break;
                        case "128":
                            zone22.color="#eacc79";
                            break;
                        case "256":
                            zone22.color="#ecc961";
                            break;
                        case "512":
                            zone22.color="#e9c55b";
                            break;
                        case "1024":
                            zone22.color="#ecc440";
                            break;
                        case "2048":
                            zone22.color="#e7bf433";
                            break;
                        default:
                            zone22.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone23
            x: 310
            y: 210
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte23
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case23
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte23.text){
                        case "":
                            zone23.color="#cac0b4";
                            break;
                        case "2":
                            zone23.color="#ede4db";
                            break;
                        case "4":
                            zone23.color="#ebdfc9";
                            break;
                        case "8":
                            zone23.color="#e9b280";
                            break;
                        case "16":
                            zone23.color="#f59563";
                            break;
                        case "32":
                            zone23.color="#e68469";
                            break;
                        case "64":
                            zone23.color="#e46b4c";
                            break;
                        case "128":
                            zone23.color="#eacc79";
                            break;
                        case "256":
                            zone23.color="#ecc961";
                            break;
                        case "512":
                            zone23.color="#e9c55b";
                            break;
                        case "1024":
                            zone23.color="#ecc440";
                            break;
                        case "2048":
                            zone23.color="#e7bf433";
                            break;
                        default:
                            zone23.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone30
            x: 10
            y: 310
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte30
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case30
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte30.text){
                        case "":
                            zone30.color="#cac0b4";
                            break;
                        case "2":
                            zone30.color="#ede4db";
                            break;
                        case "4":
                            zone30.color="#ebdfc9";
                            break;
                        case "8":
                            zone30.color="#e9b280";
                            break;
                        case "16":
                            zone30.color="#f59563";
                            break;
                        case "32":
                            zone30.color="#e68469";
                            break;
                        case "64":
                            zone30.color="#e46b4c";
                            break;
                        case "128":
                            zone30.color="#eacc79";
                            break;
                        case "256":
                            zone30.color="#ecc961";
                            break;
                        case "512":
                            zone30.color="#e9c55b";
                            break;
                        case "1024":
                            zone30.color="#ecc440";
                            break;
                        case "2048":
                            zone30.color="#e7bf433";
                            break;
                        default:
                            zone30.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone31
            x: 110
            y: 310
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte31
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case31
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte31.text){
                        case "":
                            zone31.color="#cac0b4";
                            break;
                        case "2":
                            zone31.color="#ede4db";
                            break;
                        case "4":
                            zone31.color="#ebdfc9";
                            break;
                        case "8":
                            zone31.color="#e9b280";
                            break;
                        case "16":
                            zone31.color="#f59563";
                            break;
                        case "32":
                            zone31.color="#e68469";
                            break;
                        case "64":
                            zone31.color="#e46b4c";
                            break;
                        case "128":
                            zone31.color="#eacc79";
                            break;
                        case "256":
                            zone31.color="#ecc961";
                            break;
                        case "512":
                            zone31.color="#e9c55b";
                            break;
                        case "1024":
                            zone31.color="#ecc440";
                            break;
                        case "2048":
                            zone31.color="#e7bf433";
                            break;
                        default:
                            zone31.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone32
            x: 210
            y: 310
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte32
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case32
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte32.text){
                        case "":
                            zone32.color="#cac0b4";
                            break;
                        case "2":
                            zone32.color="#ede4db";
                            break;
                        case "4":
                            zone32.color="#ebdfc9";
                            break;
                        case "8":
                            zone32.color="#e9b280";
                            break;
                        case "16":
                            zone32.color="#f59563";
                            break;
                        case "32":
                            zone32.color="#e68469";
                            break;
                        case "64":
                            zone32.color="#e46b4c";
                            break;
                        case "128":
                            zone32.color="#eacc79";
                            break;
                        case "256":
                            zone32.color="#ecc961";
                            break;
                        case "512":
                            zone32.color="#e9c55b";
                            break;
                        case "1024":
                            zone32.color="#ecc440";
                            break;
                        case "2048":
                            zone32.color="#e7bf433";
                            break;
                        default:
                            zone32.color="#cac0b4";
                            break;
                    }
                }
            }
        }

        Rectangle {
            id: zone33
            x: 310
            y: 310
            width:80
            height:80
            color:"#cac0b4"

            Text {
                id: texte33
                width: 80
                height: 80
                color: "#5b3902"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 40
                text: jeu.case33
                onTextChanged: { //Changement de couleurs pour une cases
                    switch(texte33.text){
                        case "":
                            zone33.color="#cac0b4";
                            break;
                        case "2":
                            zone33.color="#ede4db";
                            break;
                        case "4":
                            zone33.color="#ebdfc9";
                            break;
                        case "8":
                            zone33.color="#e9b280";
                            break;
                        case "16":
                            zone33.color="#f59563";
                            break;
                        case "32":
                            zone33.color="#e68469";
                            break;
                        case "64":
                            zone33.color="#e46b4c";
                            break;
                        case "128":
                            zone33.color="#eacc79";
                            break;
                        case "256":
                            zone33.color="#ecc961";
                            break;
                        case "512":
                            zone33.color="#e9c55b";
                            break;
                        case "1024":
                            zone33.color="#ecc440";
                            break;
                        case "2048":
                            zone33.color="#e7bf433";
                            break;
                        default:
                            zone33.color="#cac0b4";
                            break;
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle1
        x: 200
        y: 523
        width: 200
        height: 50
        color: "#baae9f"
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
            color: "#ecded3"
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

    Text {
        id: titre
        x: 96
        y: 7
        width: 164
        height: 76
        color: "#796c67"
        text: qsTr("2048")
        font.bold: true
        font.pixelSize: 60
    }

    Rectangle {
        id: score
        x: 266
        y: 19
        width: 112
        height: 64
        color: "#bbada0"

        Text {
            id: scoreText
            x: 0
            y: 0
            width: 112
            height: 22
            text: qsTr("SCORE")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color:"#e6d8cd"
            font.bold: true
            font.family: "Verdana"
            font.pixelSize: 16
        }

        Text {
            id: scoreNombre
            x: 0
            y: 16
            width: 112
            height: 48
            color:"#fcfaf8"
            text: jeu.score
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }
    }

    Rectangle {
        id: bestScore
        x: 384
        y: 19
        width: 116
        height: 64
        color: "#bbada0"
        Text {
            id: bestScoreText
            x: 0
            y: 0
            width: 116
            height: 22
            color:"#e6d8cd"
            text: qsTr("BEST")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.family: "Verdana"
            font.pixelSize: 16
        }

        Text {
            id: bestScoreNombre
            x: 0
            y: 14
            width: 116
            height: 50
            color:"#fcfaf8"
            text: jeu.bestScore
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pixelSize: 20
        }
    }
}
