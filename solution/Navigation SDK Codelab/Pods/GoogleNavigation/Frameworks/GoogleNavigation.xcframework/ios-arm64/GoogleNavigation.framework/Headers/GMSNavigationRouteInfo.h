//
//  GMSNavigationRouteInfo.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>

#import "GMSNavigationTypes.h"

@class GMSNavigationTimeAndDistance;

NS_ASSUME_NONNULL_BEGIN

/**
 * An immutable class that encapsulates ETA and distance information for both the default best
 * route, and the shortest route, to a specific waypoint.
 */
@interface GMSNavigationRouteInfo : NSObject

- (null_unspecified instancetype)init NS_UNAVAILABLE;

/**
 * Returns the ETA and distance information for the main route if navigating with the given routing
 * strategy.
 */
- (GMSNavigationTimeAndDistance *_Nullable)timeAndDistanceForRoutingStrategy:
    (GMSNavigationRoutingStrategy)routingStrategy;

@end

NS_ASSUME_NONNULL_END
