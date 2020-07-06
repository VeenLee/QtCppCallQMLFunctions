import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 37
        y: 31
        width: 89
        height: 32
        color: "#bf7373"

        MouseArea {
            signal send2Slot2()
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent
            onClicked: {
                myClass.testSlot2()
            }
        }
    }

    Text {
        id: txtBox
        x: 37
        y: 69
        width: 89
        height: 35
        text: qsTr("")
        font.pixelSize: 12
    }

    function disp(strInfo)
    {
        txtBox.text = strInfo
    }
}

/*##^##
Designer {
    D{i:2;anchors_height:24;anchors_width:59;anchors_x:22;anchors_y:8}
}
##^##*/
