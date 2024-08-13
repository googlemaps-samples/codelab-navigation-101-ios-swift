//
//  GMSRoadSnappedLocationProvider.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

@class GMSRoadSnappedLocationProvider;

NS_ASSUME_NONNULL_BEGIN

/** Listener for events on GMSRoadSnappedLocationProvider. */
@protocol GMSRoadSnappedLocationProviderListener <NSObject>

/**
 * Called when the device's location is updated.
 *
 * This is provided as frequently as possible by the location provider.  Locations are only
 * road-snapped when in driving mode, not when walking or cycling.
 *
 * If any of the location properties are unavailable, they are set to the following values:
 *   coordinate: kCLLocationCoordinate2DInvalid
 *   altitude: NAN
 *   horizontalAccuracy: -1
 *   verticalAccuracy: -1
 *   course: -1
 *   speed: -1
 *
 * Note that this method will not be called if the terms and conditions have not been accepted.
 */
- (void)locationProvider:(GMSRoadSnappedLocationProvider *)locationProvider
       didUpdateLocation:(CLLocation *)location;

@end

/**
 * Provides updates of the device's location. This class functions similarly to CLLocationManager,
 * except that if the device is in driving mode, the location updates is snapped to the nearest
 * road.
 *
 * This class is not intended for subclassing.
 */
@interface GMSRoadSnappedLocationProvider : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Adds a listener. The listener is held with a weak reference.
 *
 * @param listener An object conforming to the @c GMSRoadSnappedLocationProviderListener protocol.
 */
- (void)addListener:(id<GMSRoadSnappedLocationProviderListener>)listener;

/**
 * Removes a listener.
 *
 * @param listener An object conforming to the @c GMSRoadSnappedLocationProviderListener protocol.
 *
 * @return Returns YES if the listener was removed. Returns NO if the object was not a listener.
 */
- (BOOL)removeListener:(id<GMSRoadSnappedLocationProviderListener>)listener;

/**
 * Starts updating the device's road-snapped location. After this is called, the delegate will start
 * receiving location update events.
 *
 * In order to avoid battery drain or unintended logging of device location, |stopUpdatingLocation|
 * should be called when road-snapped location is no longer required.
 */
- (void)startUpdatingLocation;

/**
 * Stops updating the device's road-snapped location. In order to avoid battery drain or unintended
 * logging of device location, this method should be called when the listener is no longer required.
 */
- (void)stopUpdatingLocation;

/**
 * Whether the delegate should still receive location updates when the app is in the background.
 * Defaults to NO.
 */
@property(nonatomic) BOOL allowsBackgroundLocationUpdates;

@end

NS_ASSUME_NONNULL_END
