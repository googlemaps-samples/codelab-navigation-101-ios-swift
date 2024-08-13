//
//  GMSNavigationLane.h
//  Google Navigation SDK for iOS
//
//  Copyright 2023 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

@class GMSNavigationLaneDirection;

NS_ASSUME_NONNULL_BEGIN

/** Information about a single lane during navigation. */
@interface GMSNavigationLane : NSObject

/** The array of @c GMSNavigationLaneDirection in this given lane. */
@property(nonatomic, readonly) NSArray<GMSNavigationLaneDirection *> *laneDirections;

- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
