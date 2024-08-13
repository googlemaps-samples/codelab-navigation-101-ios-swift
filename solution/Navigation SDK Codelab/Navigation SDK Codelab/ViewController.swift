// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

import UIKit

import GoogleNavigation


class ViewController: UIViewController,
                      GMSNavigatorListener {

    var locationManager: CLLocationManager!
    var mapView: GMSMapView!
    
    override func loadView(){
        //Request permission to access device location
        locationManager = CLLocationManager()
        locationManager.requestAlwaysAuthorization()
        
        // Request authorization for alert notifications which deliver guidance instructions
        // in the background.
        UNUserNotificationCenter.current().requestAuthorization(options: [.alert]) {
          granted, error in
          // Handle denied authorization to display notifications.
          if !granted || error != nil {
              print("User rejected request to display notifications.")
              
          }
        }
        
        //let camera = GMSCameraPosition.camera(withLatitude: 51.483174, longitude: -0.177369, zoom: 14)
        //51.5041679608332, -0.13502310190065148
        let camera = GMSCameraPosition.camera(withLatitude: 51.5041679, longitude: -0.135023, zoom: 14)
        let options = GMSMapViewOptions()
        options.camera = camera
        options.frame = .zero
                
        mapView = GMSMapView(options: options)
        
        // Add a listeners for GMSNavigator.
        mapView.navigator?.add(self)
        
        // Show the terms and conditions.
        let companyName = "Navigation SDK Codelab"
        GMSNavigationServices.showTermsAndConditionsDialogIfNeeded(withCompanyName: companyName) { termsAccepted in
            if termsAccepted {
                // Enable navigation if the user accepts the terms.
                self.mapView.isNavigationEnabled = true
                // Request authorization for alert notifications which deliver guidance instructions
                // in the background.
            } else {
                // Handle the case when the user rejects the terms and conditions.
            }
        }
        view = mapView

        makeButton()

    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    // Listener to handle arrival events.
    func navigator(_ navigator: GMSNavigator, didArriveAt waypoint: GMSNavigationWaypoint) {
      print("You have arrived at: \(waypoint.title)")
    }

    // Listener for route change events.
    func navigatorDidChangeRoute(_ navigator: GMSNavigator) {
      print("The route has changed.")
    }

    @objc func startNav(){
        var destinations = [GMSNavigationWaypoint]()
        destinations.append(
          GMSNavigationWaypoint.init(
            placeID: "ChIJH-tBOc4EdkgRJ8aJ8P1CUxo",
            title: "Trafalgar Square")!)
        mapView.navigator?.setDestinations(
          destinations
        ) { routeStatus in
          guard routeStatus == .OK else {
            print("Handle route statuses that are not OK.")
            switch routeStatus {
                case .locationUnavailable:
                    print("Location unavailable.") //check permissions
                case .noRouteFound:
                    print("No route found.") //check start location and destination
                case .waypointError:
                    print("Waypoint error") //check Place ID
                default:
                    print("Not sure what happened")
            }

            return
          }
          //If routeStats is OK, start guidance.
          self.mapView.navigator?.isGuidanceActive = true
          //start simulating driving along the route. 
          self.mapView.locationSimulator?.simulateLocationsAlongExistingRoute()
          self.mapView.cameraMode = .following
        }

    }
    
    // Add a button to the view.
    func makeButton() {
      // A button to start navigation.
      let navButton = UIButton(frame: CGRect(x: 5, y: 150, width: 200, height: 35))
      navButton.backgroundColor = .blue
      navButton.alpha = 0.5
      navButton.setTitle("Start navigation", for: .normal)
      navButton.addTarget(self, action: #selector(startNav), for: .touchUpInside)
      self.mapView.addSubview(navButton)
    }


}

