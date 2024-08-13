//
//  GMSNavigationTimeAndDistance.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>

/** An immutable class that encapsulates the distance remaining and the ETA for a route. */
@interface GMSNavigationTimeAndDistance : NSObject

/** The duration for this route, in seconds. */
@property(nonatomic, readonly) NSTimeInterval durationSeconds;

/** The travel distance of this route, in meters. */
@property(nonatomic, readonly) CLLocationDistance distanceMeters;

@end
