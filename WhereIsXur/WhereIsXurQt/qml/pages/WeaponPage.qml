import QtQuick 2.0
import Sailfish.Silica 1.0
import WeaponModel 1.0

Page {
    property var name
    property var classe
    property var type
    property var effect
    property var image

    function oui(){
        var color = "white"
        if(type === "néant") {
            color = "violet"
        }
        if(type === "solaire") {
            color = "orange"
        }
        if(type === "éléctrique") {
            color = "skyblue"
        }
        return color
    }

    PageHeader {
        title: name
        id: header
    }

    Column {
        y: 150
        width: parent.width

        Image {
            y: 200
            height: 150
            width: 150
            source: image
            anchors.right: parent.right
            anchors.rightMargin: Theme.paddingMedium
        }

        Label {
            y : 400
            text: "Classe : " + classe
            width: parent.width
            anchors.leftMargin: 30
        }
        Label {
            y : 500
            color: oui()
            text: "Type : " + type
            width: parent.width
            anchors.leftMargin: 30
        }
        Label {
            y : 600
            text: "Effet : "
            width: parent.width
            anchors.leftMargin: 30
        }
        Label {
            y: 650
            height: 75
            text: effect
            width: parent.width
            wrapMode: Label.WordWrap
            anchors.leftMargin: 30
        }
    }
}
