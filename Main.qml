import QtQuick 2.0
import QtQuick.Window 2.2
import components as My

Window {
    width: 200
    height: 200
    visible: true
My.Button{
    anchors.centerIn: parent
    width: 50
    height: 50
    iconSource: "qrc:/qt/qml/main/resources/images/qt.png"
    onClicked: console.log("click on button")
}
}
