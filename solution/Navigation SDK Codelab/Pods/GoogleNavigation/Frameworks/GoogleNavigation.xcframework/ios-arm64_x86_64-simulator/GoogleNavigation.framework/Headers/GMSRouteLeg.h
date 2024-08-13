//
//  GMSRouteLeg.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

@class GMSNavigationWaypoint;
@class GMSPath;

NS_ASSUME_NONNULL_BEGIN

/**
 * An immutable class which represents a single leg of a journey, either from the device's current
 * position to the first destination, or from one destination to a subsequent destination.
 */
@interface GMSRouteLeg : NSObject

/** The destination waypoint associated with this leg of the route. */
@property(nonatomic, readonly, nullable) GMSNavigationWaypoint *destinationWaypoint;

/**
 * The final coordinate in this leg. Note that this will in general not be the same location as the
 * destination waypoint, unless the waypoint is positioned directly on a road.
 */
@property(nonatomic, readonly) CLLocationCoordinate2D destinationCoordinate;

/** The path containing the coordinates which make up this route leg. */
@property(nonatomic, readonly, nullable) GMSPath *path;

- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
