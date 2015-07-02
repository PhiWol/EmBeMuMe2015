import bb.cascades 1.4
import bb.cascades.pickers 1.0

Page { 
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        Button {
            text: qsTr("Create new presentation")
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                _application.getPresentationControl().clear();
                var page = presentationEditPage.createObject();
                hostNavigationPane.push(page);
            }
        }
        Button {
            text: qsTr("Choose an existing presentation")
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                folderPicker.open();
            }
        }
        attachedObjects: [
            ComponentDefinition {
                id: presentationEditPage
                source: "PresentationEditPage.qml"
            },
            FilePicker {
                id: folderPicker
                type : FileType.Other
                mode: FilePickerMode.Picker
                title : qsTr("Select a presentation")
                onFileSelected : {
                    _application.getPresentationControl().load(selectedFiles[0]);
                    var page = presentationEditPage.createObject();
                    hostNavigationPane.push(page);
                }
            }
        ]
        topPadding: ui.du(2.5)
        leftPadding: ui.du(2.5)
        rightPadding: ui.du(2.5)
    }
}