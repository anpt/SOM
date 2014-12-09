import QtQuick 2.0
import Sailfish.Silica 1.0
import "file.js" as FileJS;
Page{
    id: page
    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height
        Column{
            id: column

            width: page.width
            spacing: Theme.paddingSmall
            anchors.fill: parent
            PageHeader {
                title: qsTr("SOM")
            }
            Label {
                x: Theme.paddingLarge
                text: qsTr("Change org file")
                color: Theme.secondaryHighlightColor
                font.pixelSize: Theme.fontSizeExtraLarge
            }
            SilicaListView{
                y: 200
                id: listView
                width: page.width
                height: page.height
                model: ListModel{
                    ListElement{ filename: "notes.org"}
                }

                delegate: BackgroundItem{
                    id: headers

                    width: ListView.view.width;
                    height: Theme.itemSizeSmall
                    Label{ text: filename}

                    onClicked: {

                        FileJS.sharedFile = filename

                        filehandler.listHeaders(FileJS.sharedFile);
                    }

                }

            }
        }
    }
}
