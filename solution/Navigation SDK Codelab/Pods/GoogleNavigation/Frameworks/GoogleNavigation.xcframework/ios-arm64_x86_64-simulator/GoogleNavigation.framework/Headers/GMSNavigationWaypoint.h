//
//  GMSNavigationWaypoint.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>

@class GMSNavigationMutableWaypoint;

NS_ASSUME_NONNULL_BEGIN

/**
 * An immutable waypoint class, used to specify navigation destinations. It may be initialized from
 * a CLLocationCoordinate2D or a Google Place ID.
 */
@interface GMSNavigationWaypoint : NSObject <NSCopying, NSMutableCopying>

/* The name of the waypoint. */
@property(nonatomic, readonly) NSString *title;

/**
 * The coordinates of the waypoint. This is kCLLocationCoordinate2DInvalid if this waypoint was
 * initialized from a Place ID.
 */
@property(nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 * The Place ID of this waypoint. This is nil if this waypoint was initialized from coordinates.
 */
@property(nonatomic, readonly, copy, nullable) NSString *placeID;

/**
 * Whether it is preferred to route the driver to the same side of the
 * road. The route will arrive on the preferred side of the road unless there is a significant
 * delay caused by a road closure or slow-moving traffic. Default to NO.
 */
@property(nonatomic, readonly) BOOL preferSameSideOfRoad;

/**
 * An angle used to express the direction of traffic on the side of the road that the vehicle
 * should arrive on. Consequently, it is not useful for one-way streets.
 * Units expressed in degrees [0, 360], where 0 means North and angles increase clockwise.
 * Default and unset value is -1.
 */
@property(nonatomic, readonly) int32_t preferredHeading;

/**
 * Indicates that the waypoint is meant for vehicles to stop at, where the intention is to either
 * pickup or drop-off. When you set this value, waypoints on roads that are unsuitable for pickup
 * and drop-off may be adjusted to a more suitable location. This option works only for DRIVE and
 * TWO_WHEELER travel modes. Default to NO.
 */
@property(nonatomic, readonly) BOOL vehicleStopover;

/**
 * Initializes this GMSNavigationWaypoint to represent a location specified by 2D coordinates.
 *
 * @param location The location of this waypoint.
 * @param title A string representing the name of the waypoint.
 * @return An instance of @c GMSNavigationWaypoint, or nil if the location is not valid.
 */
- (nullable instancetype)initWithLocation:(CLLocationCoordinate2D)location
                                    title:(NSString *)title NS_DESIGNATED_INITIALIZER;

/**
 * Initializes this GMSNavigationWaypoint to represent a location specified by a Place ID.
 *
 * @param placeID The Google Place ID for this waypoint.
 * @param title A string representing the name of the waypoint.
 * @return An instance of @c GMSNavigationWaypoint, or nil if the Place ID string is nil or empty.
 */
- (nullable instancetype)initWithPlaceID:(NSString *)placeID
                                   title:(NSString *)title NS_DESIGNATED_INITIALIZER;

/**
 * Initializes GMSNavigationWaypoint to represent a location specified by 2D coordinates and side
 * of road preferences.
 *
 * @param location The latitude and longitude of the waypoint.
 * @param title A string representing the name of the waypoint.
 * @param preferSameSideOfRoad Whether it is preferred to route the driver to the same side of the
 *     road. The route will arrive on the preferred side of the road unless there is a significant
 *     delay caused by a road closure or slow-moving traffic.
 * @return An instance of @c GMSNavigationWaypoint, or nil if the location is not valid.
 */
- (nullable instancetype)initWithLocation:(CLLocationCoordinate2D)location
                                    title:(NSString *)title
                     preferSameSideOfRoad:(BOOL)preferSameSideOfRoad;

/**
 * Initializes GMSNavigationWaypoint to represent a location specified by 2D coordinates and side
 * of road preferences.
 *
 * @param location The latitude and longitude of the waypoint.
 * @param title A string representing the name of the waypoint.
 * @param preferredSegmentHeading An angle used to express the direction of traffic on the side of
 *     the road that the vehicle should arrive on. Consequently, it is not useful for one-way
 *     streets.
 *     Units expressed in degrees [0, 360], where 0 means North.
 * @return An instance of @c GMSNavigationWaypoint, or nil if the location or the
 *     preferredSegmentHeading is not valid.
 */
- (nullable instancetype)initWithLocation:(CLLocationCoordinate2D)location
                                    title:(NSString *)title
                  preferredSegmentHeading:(int32_t)preferredSegmentHeading;

- (null_unspecified instancetype)init NS_DESIGNATED_INITIALIZER NS_UNAVAILABLE;

/* Returns a copy of this waypoint. */
- (GMSNavigationWaypoint *)copy;

/* Returns a mutable copy of this waypoint. */
- (GMSNavigationMutableWaypoint *)mutableCopy;

@end

/**
 * A mutable waypoint class.
 */
@interface GMSNavigationMutableWaypoint : GMSNavigationWaypoint

/**
 * Whether it is preferred to route the driver to the same side of the road. The route will arrive
 * on the preferred side of the road unless there is a significant delay caused by a road closure
 * or slow-moving traffic. Default to NO.
 * Setting this to true clears any value in @c preferredHeading.
 */
@property(nonatomic) BOOL preferSameSideOfRoad;

/**
 * An angle used to express the direction of traffic on the side of the road that the vehicle
 * should arrive on. Consequently, it is not useful for one-way streets.
 * Units expressed in degrees [0, 360], where 0 means North and angles increase clockwise.
 * Default and unset value is -1.
 * Setting a valid value will clear the @c preferSameSideOfRoad.
 */
@property(nonatomic) int32_t preferredHeading;

/**
 * Indicates that the waypoint is meant for vehicles to stop at, where the intention is to either
 * pickup or drop-off. When you set this value, waypoints on roads that are unsuitable for pickup
 * and drop-off may be adjusted to a more suitable location. This option works only for DRIVE and
 * TWO_WHEELER travel modes. Default to NO.
 */
@property(nonatomic) BOOL vehicleStopover;

@end

NS_ASSUME_NONNULL_END
