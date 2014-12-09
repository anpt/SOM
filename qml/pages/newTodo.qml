import QtQuick 2.0
import Sailfish.Silica 1.0
import  "file.js" as FileJS
Page {
    id: page
    SilicaFlickable {
        anchors.fill: parent
        PageHeader {
            title: qsTr("New Todo")
        }

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
            text: qsTr("New Todo")
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }

        TextField {
            id: newTodo
            width: page.width
            height: Theme.smallItemSize
            placeholderText: "Enter New Todo"
            label: "TODO"
        }
        TextField {
            id: newDate
            width: page.width
            height: Theme.smallItemSize
            placeholderText: "Deadline"
            label: "TODO"
            inputMethodHints : Qt.ImhDate
        }
        Button {

            property string filename: FileJS.sharedFile
            text: "Save"
            onClicked: {
                filehandler.newTodo(newTodo.text,filename,newDate.text)
                filehandler.listHeaders(filename)


            }
        }
    }

    }
}
