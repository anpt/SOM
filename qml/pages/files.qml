import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
   id: page
    SilicaFlickable {
        anchors.fill: parent
        SilicaListView{
            VerticalScrollDecorator{}
            width: parent.width;
            model: ListModel{
                ListElement{ file: "myfile.org"}
            }
            delegate: BackgroundItem{
                width: ListView.view.width;
                height: Theme.itemSizeSmall
                Label{ text: file}
            }
        }
    }
}
