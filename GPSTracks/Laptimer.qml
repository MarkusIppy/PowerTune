import QtQuick 2.8
import QtLocation 5.8
import QtPositioning 5.8

Item {
    id: mapItem
    anchors.fill: parent
    Rectangle{
        anchors.fill: parent
        Plugin {
            id: mapPlugin
            name: "osm"
            //Offline directory for Map Tiles
            PluginParameter {
                name: 'osm.mapping.offline.directory'
                value: ':/GPSTracks/'
            }
            //Disable to Fetch Map Data from the Server
                       PluginParameter {
                          name: "osm.mapping.providersrepository.disabled"
                          value: true
                       }
                       PluginParameter {
                          name: "osm.mapping.providersrepository.address"
                          value: 'qrc:/GPSTracks/'
                       }


        }

        Map {
            id: map
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(-34.840764,149.686800) //
            //center: QtPositioning.coordinate(40.57500,-112.37472) //Utah Motorsport Park
            //center: QtPositioning.coordinate(-26.074278, 28.752637)// Redstar Raceway South Africa
            zoomLevel: 16

            activeMapType: map.supportedMapTypes[1]
            copyrightsVisible : false
            gesture.enabled: false
            tilt: 0
            color: "black"


            // Draw a small red circle for current Vehicle Location
            MapQuickItem {
                id: marker
                anchorPoint.x: 10
                anchorPoint.y: 10
                width: 15
                coordinate: QtPositioning.coordinate(Dashboard.gpsLatitude,Dashboard.gpsLongitude)
                //coordinate: QtPositioning.coordinate(-34.840764,149.686800)
                sourceItem: Rectangle {
                    id: image
                    width:20
                    height: width
                    radius: width*0.5
                    color: "red"
                }
            }
        }
    }
}
