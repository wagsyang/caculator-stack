import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
//import model

Window {
    id: mainwindow
    width: 640
    height: 480
    visible: true
    title: qsTr("caculator-stack")

    ColumnLayout{
        spacing: 0
        TextField {
            id: expressionField
            color: "white"
            font.pointSize: 20
            maximumLength: 35
            width: mainwindow.width
            height: 100
            placeholderText: qsTr("please input expression:")
            placeholderTextColor: "grey"
            text: ""
            cursorVisible: true
            focus: true
            background: Rectangle {
                width: mainwindow.width
                color: "#293846"
            }
            onAccepted: {
                // TODO: send expression to model after Return/Enter pressed
                // model.caculateExpression(expressionField.text){}
            }
        }
        TextField {
            id: resultField
            color: "white"
            font.pointSize: 20
            maximumLength: 35
            Layout.fillWidth: true
            width: mainwindow.width
            height: 100
            text: ""
            activeFocusOnPress: false
            background: Rectangle {
                width: mainwindow.width
                color: "#293846"
            }
        }
    }

    Button {
        text: "caculate"
        font.pointSize: 20
        width: 300
        height: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 150   
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: function(){
            // TODO:slot in model(mvc)
            // model.caculateExpression(expressionField.text){}
        }
    }

    Timer {
        id: cleanTimer
        interval: 2000
        onTriggered: {
            resultField.color="white"
            resultField.text=""
        }
    }

    Connections {
        target: model

        function onInfoExpressionInvalidate(){
            resultField.color="red"
            resultField.text="warning: expression is invalidate!!!"
            cleanTimer.start()
        }

        function onShowCaculateResult(result){
            resultField.text=result
        }
    }
}
