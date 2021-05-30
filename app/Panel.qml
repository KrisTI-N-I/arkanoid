import QtQuick 2.0

Rectangle {
    width: 120
    height: 20
    radius: 10
    border.width: 2

    property int shiftX: 20

    color: "#02D099"

    signal moved(int newX, int newY)

    function move(direction) {
        if(direction > 0) {
            moveRight()
        } else {
            moveLeft()
        }

        moved(x, y)
    }

    function moveRight() {
        if(x + width + shiftX <= parent.width) {
            x += 20
        }
    }

    function moveLeft() {
        if(x + - shiftX >= 0) {
            x -= 20
        }
    }
}
