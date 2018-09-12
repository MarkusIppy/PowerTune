import QtQuick 2.8
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0
import Qt.labs.settings 1.0
import QtQuick.Layouts 1.1


Rectangle {
    id: gpswindow
    width: parent.width
    height: parent.height
    color: "black"
    Rectangle {
        id: mapwindow
        width: parent.width / 2
        height: parent.height

        Loader {
            id: trackloader
            anchors.fill: parent
            source: "qrc:/GPSTracks/Laptimer.qml"

        }
    }
    Grid {
        rows: 10
        columns: 2
        spacing: 5
        anchors.left: mapwindow.right

        Text { text: "Time: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsTime
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "GPS Speed: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsSpeed
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "ECU Speed: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: Dashboard.speed
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "Altitude: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsAltitude
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "Latitude: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsLatitude
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "Longitude: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsLongitude
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: "Visible Satelites: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text { text: Dashboard.gpsVisibleSatelites
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: "Current Lap Time: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: Dashboard.gpsVisibleSatelites
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: "Fastest Lap Time: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: Dashboard.gpsVisibleSatelites
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: "Current Lap No: "
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
        Text {
            text: Dashboard.gpsVisibleSatelites
            font.pixelSize: gpswindow.width /35
            font.bold: true
            font.family: "Eurostile"
            color: "white"
        }
    }
}

