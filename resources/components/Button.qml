import QtQuick 2.0

Item {
    id: root

    signal clicked
    property bool isEnabled: true
    property bool isChecked: false
    property bool checkable: true
    property bool uncheckable: false
    required property url iconSource

    onIsEnabledChanged: rect.color = isEnabled ? rect.disable_color : rect.checked_color()
    onIsCheckedChanged: if(!rect.hovered) rect.color = rect.checked_color()

    Rectangle{
        anchors.fill: parent
        id: rect

        property bool hovered: false

        readonly property string disable_color: "gray"
        readonly property string hover_color: "blue"

        onHoveredChanged: {
            if (isEnabled)
                color = hovered ? hover_color : checked_color()
        }

        Component.onCompleted: {
            color = !isEnabled ? disable_color :
                                 hovered ? hover_color : checked_color()
        }

        function checked_color(){
                return isChecked ? "green" : "red"
            }
    }

    Image {
        anchors.centerIn: parent
        source: iconSource
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            root.clicked()
            if (rect.hovered && checkable)
                if(!isChecked)
                    isChecked = true
                else if(!uncheckable)
                    isChecked = false
        }

        onEntered: rect.hovered = true
        onExited: rect.hovered = false
        }
}
