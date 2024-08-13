//
//  GMSNavigationStepInfo.h
//  Google Navigation SDK for iOS
//
//  Copyright 2022 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#import "GMSNavigationTypes.h"

@class GMSNavigationLane;
@class GMSNavigationStepInfoImageOptions;

NS_ASSUME_NONNULL_BEGIN

/** Information about a single step along a navigation route. */
@interface GMSNavigationStepInfo : NSObject

/** The @c GMSNavigationManeuver for this step. */
@property(nonatomic, readonly) GMSNavigationManeuver maneuver;

/**
 * The UIImage for the maneuver of this step using provided options. Default options values will be
 * used if the options parameter is nil.
 *
 * Returns nil if there is no maneuver image for this step.
 */
- (nullable UIImage *)maneuverImageWithOptions:
    (nullable GMSNavigationStepInfoImageOptions *)options;

/**
 * The different available lanes for this step.
 *
 * The array is ordered such that the first lane is on the left and last lane is on the right
 * regardless of driving side.
 *
 * Returns nil if there is no lane guidance for this step.
 */
@property(nonatomic, nullable, readonly) NSArray<GMSNavigationLane *> *lanes;

/**
 * The UIImage for the lane guidance of this step using provided options. Default options values
 * will be used if the options parameter is nil.
 *
 * Returns nil if there is no lane guidance for this step.
 */
- (nullable UIImage *)lanesImageWithOptions:(nullable GMSNavigationStepInfoImageOptions *)options;

/**
 * The full road name for this step containing all information for the road including direction.
 *
 * Examples (each line is a separate example):
 *
 * Lean Ave
 *
 * CA-85 / Mtn View
 *
 * Exit 9A / North First Street
 */
@property(nonatomic, readonly) NSString *fullRoadName;

/**
 * The simplified version of the road name. This is shorter than the full road name and may not
 * contain all pieces of identifying information about the road such as direction or name of exit.
 *
 * Examples (each line is a separate example):
 *
 * Lean Ave
 *
 * CA-85
 *
 * Exit 9A
 */
@property(nonatomic, readonly) NSString *simpleRoadName;

/**
 * The full text of the instruction for this step.
 *
 * Examples (each line is a separate example):
 *
 * Turn left onto Lean Ave.
 *
 * Use the right lane to take the CA-85 ramp to Mtn View.
 *
 * Use the 2nd from the right lane to take exit 9A toward North First Street.
 */
@property(nonatomic, readonly) NSString *fullInstructionText;

/** Exit number of this step if it exists. */
@property(nonatomic, nullable, readonly) NSString *exitNumber;

/** Whether this step is on a drive-on-right or drive-on-left route. */
@property(nonatomic, readonly) GMSNavigationDrivingSide drivingSide;

/**
 * The counted number of the exit to take relative to the location where the roundabout was entered.
 * Only set for roundabouts, otherwise -1.
 */
@property(nonatomic, readonly) NSInteger roundaboutTurnNumber;

/**
 * The index of the step in the list of all steps in the route. The first step has step number 0.
 */
@property(nonatomic, readonly) NSInteger stepNumber;

/** The total distance of this step. This value does not change. */
@property(nonatomic, readonly) CLLocationDistance distanceFromPrevStepMeters;

/** The estimated time it takes to complete this step. This value does not change. */
@property(nonatomic, readonly) NSTimeInterval timeFromPrevStepSeconds;

- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
