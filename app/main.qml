import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.2

Window {
    id: main
    width: 640
    height: 640
    minimumWidth: 640
    minimumHeight: 640
    maximumWidth: 640
    maximumHeight: 640
    visible: true

    title: qsTr("Arkanoid Qt")

    function newGame() {
        game.setFieldSize(main.width, main.height)
        game.setPanelSize(panel.width, panel.height)
        game.setBallSize(ball.width, ball.height)
        game.newGame()
        console.log("new game")
    }

    function resetField() {
        panel.x = main.width / 2 - panel.width / 2
        ball.x = main.width / 2 - ball.width / 2
        ball.y = main.height / 2 - ball.height / 2
        game.setBallPos(ball.x, ball.y)
        game.setPanelPos(panel.x, panel.y)
    }

    Image {
        id: background
        anchors.fill: parent
        source: "images/background.png"
        sourceSize.height: 400
        sourceSize.width: 400
        fillMode: Image.Tile
        visible: true
        opacity: 0.3
    }

    GridLayout {
        id: gridLayout
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        anchors.topMargin: 2

        columns: 10
        rows: 2

        columnSpacing: 2
        rowSpacing: 2

        Repeater {
            id: blocks

            model: 20

            Block {

            }

            Component.onCompleted: {
                var xPoses = []
                var yPoses = []
                var w = 60
                var h = 60

                for(var i = 0; i < blocks.model; i++)
                {
                    xPoses.push(blocks.itemAt(i).x)
                    yPoses.push(blocks.itemAt(i).y)
                }

                game.setBlocks(xPoses, yPoses, w, h)
            }
        }
    }

    Panel {
        id: panel
        x: main.width / 2 - width / 2
        y: 600

        onMoved: {
            game.setPanelPos(newX, newY)
        }
    }

    Ball {
        id: ball
        x: main.width / 2 - width / 2
        y: main.height / 2 - height / 2
    }

    Item {
        id: keyHandler
        focus: true
        anchors.fill: parent

        Keys.onRightPressed: {
            panel.move(1)
        }

        Keys.onLeftPressed: {
            panel.move(-1)
        }
    }

    Dialog {
        id: winDialog
        title: "Win!"
        Text {
            text: qsTr("You win ^_^")
        }
        standardButtons: Dialog.Ok | Dialog.Close

        onAccepted: {
            newGame()
        }

        onRejected: {
            Qt.quit()
        }
    }

    Dialog {
        id: loseDialog
        title: "Lose :("
        Text {
            text: qsTr("You lose")
        }
        standardButtons: Dialog.Ok | Dialog.Close

        onAccepted: {
            newGame()
        }

        onRejected: {
            Qt.quit()
        }
    }

    Connections {
        target: game

        onUpdateGame: {
            ball.setPos(ballX, ballY)

            for(var i = 0; i < blocksState.length; i++) {
                blocks.itemAt(i).notBroken = blocksState[i]
            }
        }

        onResetField: {
            resetField()
        }

        onWinGame: {
            winDialog.open()
        }

        onLoseGame: {
            loseDialog.open()
        }
    }

    Component.onCompleted: {
        newGame()
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
