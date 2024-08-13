//
//  GMSNavigationLaneDirection.h
//  Google Navigation SDK for iOS
//
//  Copyright 2023 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import "GMSNavigationTypes.h"

NS_ASSUME_NONNULL_BEGIN

/** Information about a single lane direction during navigation. */
@interface GMSNavigationLaneDirection : NSObject

/** Returns the @c GMSNavigationLaneShape for this lane direction. */
@property(nonatomic, readonly) GMSNavigationLaneShape laneShape;

/** Whether this lane direction is recommended or not. */
@property(nonatomic, readonly) bool recommended;

- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
