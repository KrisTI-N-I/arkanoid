import QtQuick 2.0


Rectangle {
    width: 60
    height: 60
    radius: 10
    border.width: 2
    color: "#FF0000"
    opacity: notBroken ? 1 : 0

    property bool notBroken: false

    function randomColor() {
        var colors = ["#F10368", "#5EDC0E", "#EEE502", "#02D099", "#F28705"]
        color = colors[Math.floor(colors.length*Math.random())]
    }

    Component.onCompleted: {
        randomColor()
    }
}

