import QtQuick 2.0
import Sailfish.Silica 1.0
import "../pages"


ListItem {
    id: weaponItem
    width: listView.width
    Label {
        text: name    
    }

    Image {
        source: image
        anchors.right: parent.right
        anchors.rightMargin: Theme.paddingMedium
        height: parent.height - 3
        width: parent.height - 3
    }

    onClicked: pageStack.push( weaponPage, { name: name, classe: classe, effect: effect, type: type, image: image })
    Component {
        id: weaponPage
        WeaponPage {}
    }

    menu: ContextMenu {

        MenuItem {
            text: "Delete Weapon"
            onClicked: remorse.remorseDelete()

            RemorseItem {
                id: remorse
                function remorseDelete() {
                    var idx = index
                    remorse.execute(weaponItem, "Deleting Weapon", function() { listView.model.removeRow(idx) }, 2000 )
                }
            }
        }
    }
}
