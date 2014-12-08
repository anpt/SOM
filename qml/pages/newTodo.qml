import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    SilicaFlickable {
        anchors.fill: parent


    Column{
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
            property alias filename : filename;
            property string filename: "test.org"
            text: "Save"
            onClicked: {
                filehandler.newTodo(newTodo.text,filename,newDate.text)
                filehandler.listHeaders(filename)


            }
        }
    }

    }
}
