import QtQuick 2.0
import Sailfish.Silica 1.0
import WeaponModel 1.0
import "../delegates"

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader { title: qsTr("Armes Exotiques")   }

        model: WeaponModel { weaponList: weapons }
        delegate: DelegateWeapon { }
        VerticalScrollDecorator {}
    }
}
