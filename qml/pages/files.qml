import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
   id: page
    SilicaFlickable {
        anchors.fill: parent
        SilicaListView{
                anchors.centerIn: parent
                 width: 480;
                model: ListModel{
                    ListElement{ file: "myfile.org"}
                }
            delegate: Item{
                        width: ListView.view.width;
                        height: Theme.itemSizeSmall
                     Label{ text: file}

            }
       }
    }
}
