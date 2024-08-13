//
//  GMSNavigationSpeedometerUIOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GMSNavigationTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * An immutable class that encapsulates UI configuration for different severities of speed alerts,
 * represented by GMSNavigationSpeedAlertSeverity.
 *
 * You can use this class to customize the speed alert UI, such as the colors of the font and icon
 * background of minor and major speed alert.
 *
 * You use GMSNavigationSpeedometerUIOptions to customize the speed alert UI for different
 * severities. You must use GMSNavigationSpeedAlertOptions to define the triggering thresholds
 * for each severity of speed alert.
 */
@interface GMSNavigationSpeedometerUIOptions : NSObject <NSCopying, NSMutableCopying>

/**
 * Gets the color of the speed alert text to use for the specified speed alert severity and
 * lighting mode.
 *
 * @note: This returns UIColor.clearColor for @c GMSNavigationSpeedAlertSeverityUnknown and
 *     @c GMSNavigationSpeedAlertSeverityNotSpeeding.
 */
- (UIColor *)textColorForSpeedAlertSeverity:(GMSNavigationSpeedAlertSeverity)speedAlertSeverity
                               lightingMode:(GMSNavigationLightingMode)lightingMode;

/**
 * Gets the speed alert icon background color to use for the specified speed alert severity and
 * lighting mode.
 *
 * @note: This returns UIColor.clearColor for @c GMSNavigationSpeedAlertSeverityUnknown and
 *     @c GMSNavigationSpeedAlertSeverityNotSpeeding.
 */
- (UIColor *)backgroundColorForSpeedAlertSeverity:
                 (GMSNavigationSpeedAlertSeverity)speedAlertSeverity
                                     lightingMode:(GMSNavigationLightingMode)lightingMode;

@end

/**
 * The mutable class that encapsulates UI configuration for different severities of speed alerts,
 * represented by GMSNavigationSpeedAlertSeverity.
 */
@interface GMSNavigationMutableSpeedometerUIOptions : GMSNavigationSpeedometerUIOptions

/**
 * Sets the color of the speed alert text to use for the specified speed alert severity and lighting
 * mode.
 *
 * @note: Attempting to set the color for @c GMSNavigationSpeedAlertSeverityUnknown or
 *     @c GMSNavigationSpeedAlertSeverityNotSpeeding is a no-op.
 */
- (void)setTextColor:(UIColor *)color
    forSpeedAlertSeverity:(GMSNavigationSpeedAlertSeverity)speedAlertSeverity
             lightingMode:(GMSNavigationLightingMode)lightingMode;

/**
 * Sets the speed alert icon background color to use for the specified speed alert severity and
 * lighting mode.
 *
 * @note: Attempting to set the color for @c GMSNavigationSpeedAlertSeverityUnknown or
 *     @c GMSNavigationSpeedAlertSeverityNotSpeeding is a no-op.
 */
- (void)setBackgroundColor:(UIColor *)color
     forSpeedAlertSeverity:(GMSNavigationSpeedAlertSeverity)speedAlertSeverity
              lightingMode:(GMSNavigationLightingMode)lightingMode;

@end

NS_ASSUME_NONNULL_END
