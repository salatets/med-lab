import QtQuick 2.0
import QtQuick.Window 2.2
import components as My  // todo use import

Window {
    width: 200
    height: 200
    visible: true
My.Button{
    width: 50
    height: 50
    onClicked: console.log("click on button")
    anchors.centerIn: parent
    iconSource: "qrc:/qt.png"
}
}
