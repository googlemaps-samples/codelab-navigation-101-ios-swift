//
//  GMSLocationSimulator.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

#import "GMSNavigator.h"

@class GMSNavigationLicensePlateRestriction;
@class GMSNavigationRoutingOptions;

NS_ASSUME_NONNULL_BEGIN

/** A class you can use to simulate a device location for testing purposes.  */
@interface GMSLocationSimulator : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Starts simulating travel along the route currently set on the GMSNavigator. If the GMSNavigator
 * does not have a route, this does nothing.
 */
- (void)simulateLocationsAlongExistingRoute;

/**
 * Calculates a route to the given waypoints and simulates travel along this route. The new route
 * will use the travel mode that is set on the GMSMapView.
 *
 * Travel will be started just before the callback is called with GMSRouteStatusOK. If the callback
 * returns any value other than GMSRouteStatusOK, no simulation will start. If any other simulator
 * methods are called before the route is generated, route generation will be canceled and the
 * callback will be called with GMSRouteStatusCanceled.
 *
 * @param destinations The list of destinations for the route that will be simulated.
 * @param callback A block that will be called when the route becomes available or fails.
 */
- (void)simulateAlongNewRouteToDestinations:(NSArray<GMSNavigationWaypoint *> *)destinations
                                   callback:(GMSRouteStatusCallback)callback;

/**
 * Calculates a route to the given waypoints, and simulates travel along this route. The new route
 * will use the travel mode which is set on the GMSMapView.
 *
 * Travel starts right before the callback is invoked with GMSRouteStatusOK. If the callback
 * returns a value other than GMSRouteStatusOK, then no simulation starts. If any other simulator
 * methods are called before the route is generated, then route generation will be canceled, and the
 * callback will be called with GMSRouteStatusCanceled.
 *
 * @param destinations The list of destinations for the route that will be simulated.
 * @param routingOptions The routing logic that will determine the returned route.
 * @param callback A block that will be called when the route becomes available or fails.
 */
- (void)simulateAlongNewRouteToDestinations:(NSArray<GMSNavigationWaypoint *> *)destinations
                             routingOptions:(GMSNavigationRoutingOptions *)routingOptions
                                   callback:(GMSRouteStatusCallback)callback;

/** Starts simulating the device location at a fixed coordinate. */
- (void)simulateLocationAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Stops simulating the device location if it is currently being simulated. */
- (void)stopSimulation;

/** Diplays a navigation prompt with fake data for testing purposes. */
- (void)simulateNavigationPrompt;

/** Displays a dummy traffic prompt for testing purposes. */
- (void)simulateTrafficIncidentReport;

/**
 * Whether the simulation is currently paused. If this is set to YES whilst simulating along a
 * route, then location updates will still be sent periodically, but the location will stop
 * advancing along the route.
 */
@property(nonatomic, assign, getter=isPaused) BOOL paused;

/**
 * Whether to avoid highways when simulating travel to destinations with the
 * |simulateAlongNewRouteToDestinations:callback:| method. Defaults to NO.
 */
@property(nonatomic, assign) BOOL avoidsHighways;

/**
 * Whether to avoid toll roads when simulating travel to destinations with the
 * |simulateAlongNewRouteToDestinations:callback:| method. Defaults to NO.
 */
@property(nonatomic, assign) BOOL avoidsTolls;

/**
 * Whether to avoid ferries when simulating travel to destinations with the
 * |simulateAlongNewRouteToDestinations:callback:| method. Defaults to YES.
 */
@property(nonatomic, assign) BOOL avoidsFerries;

/**
 * The speed multiplier to use when simulating travel along a route. The value of this property must
 * be positive. Attempting to set a non-positive value will have no effect. The default value is
 * 1.0.
 */
@property(nonatomic, assign) float speedMultiplier;

/** Whether the simulated location should jitter randomly. */
@property(nonatomic, assign, getter=isLocationJitteringEnabled) BOOL locationJitteringEnabled;

/**
 * Set license plate restriction with current vehicle's last digit of license plate and country
 * code. This allows us to route around certain types of road restrictions which are based on
 * license plate number. This will only apply to simulateAlongNewRouteToDestinations calls made
 * after this value is set.
 *
 * Set to nil if there is no license plate restriction. Default to nil.
 */
@property(nonatomic, nullable) GMSNavigationLicensePlateRestriction *licensePlateRestriction;

@end

NS_ASSUME_NONNULL_END
