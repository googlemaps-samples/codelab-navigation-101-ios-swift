//
//  GMSNavigationSpeedAlertOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <UIKit/UIKit.h>

#import "GMSNavigationTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * An immutable class that defines triggering thresholds for different severities of speed alerts,
 * represented by GMSNavigationSpeedAlertSeverity.
 *
 * You can use this to customize the speed alert triggering thresholds in percentage for both minor
 * and major alerts, and customize the time based triggering threshold for major speed alert.
 *
 * The speed alerts triggered by corresponding thresholds from this GMSNavigationSpeedAlertOptions
 * have UI customized in GMSNavigationSpeedometerUIOptions if set.
 */
@interface GMSNavigationSpeedAlertOptions : NSObject <NSCopying, NSMutableCopying>

/**
 * The duration threshold controls the speed alert severity upgrade. A major speed alert is
 * triggered when the speed exceeds the minor speed alert threshold for more than the given number
 * of seconds.
 */
@property(nonatomic, readonly) NSTimeInterval severityUpgradeDurationSeconds;

/**
 * Gets the speed alert threshold (as a percentage) for the specific
 * GMSNavigationSpeedAlertSeverity. A value of 0.0 represents 0%, and 1.0 represents 100%. A
 * negative value indicates no threshold being set for that speedingType.
 */
- (CGFloat)thresholdPercentageForSpeedAlertSeverity:
    (GMSNavigationSpeedAlertSeverity)speedAlertSeverity;

@end

/**
 * A mutable class that defines triggering thresholds for different severities of speed alerts,
 * represented by GMSNavigationSpeedAlertSeverity.
 */
@interface GMSNavigationMutableSpeedAlertOptions : GMSNavigationSpeedAlertOptions

/**
 * The duration threshold controls the speed alert severity upgrade. A major speed alert is
 * triggered when the speed exceeds the minor speed alert threshold for more than the given number
 * of seconds. This duration threshold is used only if the minor threshold percentage is set. A
 * negative value indicates no duration threshold.
 */
@property(nonatomic) NSTimeInterval severityUpgradeDurationSeconds;

/**
 * Sets the speed alert threshold in percentage for the specific GMSNavigationSpeedAlertSeverity.
 * One severity of speed alert is triggered when the speed exceeds the corresponding threshold.
 *
 * If both minor and major speed alert threshold are set, the major speed alert threshold must be
 * smaller than the major one. If only one speed alert severity's threshold is set, the other
 * severity of speed alert will not be triggered.
 *
 * If you set the minor threshold to a value larger than the major threshold, the options updates
 * the major threshold to equal the minor threshold. And vice versa.
 *
 * @param percentageAboveLimit Percentage threshold above the speed limit. A value of 0.0 represents
 * 0%, and 1.0 represents 100%. A negative value indicates no threshold being set for that
 * speedingType.
 * @param speedAlertSeverity Speed alert severity for the given threshold.
 */
- (void)setSpeedAlertThresholdPercentage:(CGFloat)percentageAboveLimit
                   forSpeedAlertSeverity:(GMSNavigationSpeedAlertSeverity)speedAlertSeverity;

@end

NS_ASSUME_NONNULL_END
