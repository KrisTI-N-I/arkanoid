import QtQuick 2.0

Rectangle {
    width: 30
    height: 30
    radius: width*0.5
    border.width: 2

    color: "#F28705"

    function setPos(xPos, yPos) {
        x = xPos
        y = yPos
    }
}
