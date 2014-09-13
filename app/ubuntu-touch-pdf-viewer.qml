import QtQuick 2.0
import Ubuntu.Components 1.1
import Ubuntu.Content 0.1

import PDFViewer 1.0

/*!
    \brief MainView with Tabs element.
           First Tab has a single Label and
           second Tab has a single ToolbarAction.
*/

MainView {
    id: root
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "com.ubuntu.developer.sturmflut.ubuntu-touch-pdf-viewer"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(75)

    property var activeTransfer

    ContentPeer {
        id: pdfSourceSingle
        contentType: ContentType.Documents
        handler: ContentHandler.Source
        selectionType: ContentTransfer.Single
    }
    ContentTransferHint {
        id: transferHint
        anchors.fill: parent
        activeTransfer: root.activeTransfer
        z: 100
    }
    Connections {
        target: root.activeTransfer

        onStateChanged: {
            console.log(root.activeTransfer.items)
        }
    }



    Column{
        anchors.fill: parent
        Row {
            id: buttonRow
            anchors.left: parent.left
            anchors.right: parent.right

            Button {
                id: openButton

                text: i18n.tr("Open")

                onClicked: {
                    root.activeTransfer = pdfSourceSingle.request()
                }
            }

            Button {
                id: backButton

                text: "<"

                onClicked: {
                    pdfComponent.previousPage();

                    pageNumberLabel.text = pdfComponent.pageNumber + " / " + pdfComponent.numberOfPages
                }
            }

            Label {
                id: pageNumberLabel
                width: buttonRow.width - openButton.width - forwardButton.width - backButton.width
                text: "1"
            }

            Button {
                id: forwardButton

                text: ">"

                onClicked: {
                    pdfComponent.nextPage();

                    pageNumberLabel.text = pdfComponent.pageNumber + " / " + pdfComponent.numberOfPages
                }
            }
        }

        PDFComponent {
            id: pdfComponent
            width: parent.width
            height: parent.height - buttonRow.height

            Component.onCompleted:
            {
                pageNumberLabel.text = pdfComponent.pageNumber + " / " + pdfComponent.numberOfPages
            }
        }
    }
}

