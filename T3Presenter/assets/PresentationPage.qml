import bb.cascades 1.4

Page {
    Container {
        layout: DockLayout {}
        touchPropagationMode: TouchPropagationMode.None
        ImageView {
            id: imageView
            verticalAlignment: VerticalAlignment.Fill
            horizontalAlignment: HorizontalAlignment.Fill
            imageSource: "file://"+_application.getPresentationControl().getCurrentPage()
            function update() {
                if(!_application.getPresentationControl().isEmpty()) {
                    imageView.imageSource = "file://"+_application.getPresentationControl().getCurrentPage();
                }
            }
            onCreationCompleted: {
                _application.getPresentationControl().currentPageChanged.connect(imageView.update);
            }
        }
    }
    actions: [
        ActionItem {
            id: previousPageActionItem
            title: "Previous Page"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                var x = _application.getPresentationControl().getCurrentPageNumber();
                if(x-1 < 0) {
                    _application.getPresentationControl().setCurrentPageNumber(_application.getPresentationControl().getNumberOfPages()-1);
                }else {
                    _application.getPresentationControl().setCurrentPageNumber(x-1);
                }
                console.log(_application.getPresentationControl().getCurrentPageNumber());
            }
        },
        ActionItem {
            id: nextPageActionItem
            title: "Next Page"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                var x = _application.getPresentationControl().getCurrentPageNumber();
                if(x+1 >= _application.getPresentationControl().getNumberOfPages()) {
                    _application.getPresentationControl().setCurrentPageNumber(0);
                }else {
                    _application.getPresentationControl().setCurrentPageNumber(x+1);
                }
                console.log(_application.getPresentationControl().getCurrentPageNumber());
            }
        }
    ]
    actionBarAutoHideBehavior: ActionBarAutoHideBehavior.Default
}
