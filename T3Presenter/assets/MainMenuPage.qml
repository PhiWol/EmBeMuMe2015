import bb.cascades 1.4

TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: qsTr("Host a Presentation")
        NavigationPane {
            id: hostNavigationPane
            firstPage: HostPresentationPage {}
            //onPopTransitionEnded: { page.destroy(); }
        }
    }
    Tab {
        title: qsTr("Join a Presentation")
        NavigationPane {
            id: joinPane
            firstPage: JoinPresentationPage {}
        }
    }
}