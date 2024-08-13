//
//  GMSUISettings+Navigation.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if __has_feature(modules)
@import GoogleMaps;
#else
#import <GoogleMaps/GoogleMaps.h>
#endif

@class GMSNavigationSpeedometerUIOptions;

NS_ASSUME_NONNULL_BEGIN

/** Settings for the navigation user interface elements. */
@interface GMSUISettings (Navigation)

/**
 * Enables or disables the navigation header. The header displays guidance instructions at the top
 * of the map. This defaults to YES.
 */
@property(nonatomic, assign, getter=isNavigationHeaderEnabled) BOOL navigationHeaderEnabled;

/**
 * Enables or disables the navigation footer. The footer displays distance and ETA information at
 * the bottom of the map. This defaults to YES.
 */
@property(nonatomic, assign, getter=isNavigationFooterEnabled) BOOL navigationFooterEnabled;

/**
 * Enables or disables the navigation trip progress bar. The trip progress bar displays the details
 * of the trip ahead in a linear view on the trailing side of the map. This defaults to NO.
 */
@property(nonatomic, assign, getter=isNavigationTripProgressBarEnabled)
    BOOL navigationTripProgressBarEnabled;

/**
 * Enables or disables the recenter button. If set to YES, the recenter button is displayed if the
 * camera is not currently following the user location, or if it is following but the zoom is
 * significantly different to the default. This defaults to YES.
 */
@property(nonatomic, assign, getter=isRecenterButtonEnabled) BOOL recenterButtonEnabled;

/**
 * Whether a card showing incident details will be displayed at the top of the map when the user
 * taps an incident icon, eg a road closure. This defaults to YES.
 */
@property(nonatomic, assign) BOOL showsIncidentCards;

/** Whether destination markers for routes will be shown. This defaults to YES. */
@property(nonatomic, assign) BOOL showsDestinationMarkers;

/**
 * Whether to show traffic lights along the route during navigation.
 *
 * Changes to this setting take effect only in subsequent route requests.
 *
 * Once the setting is applied, the user interface shows the first 3 upcoming traffic lights or stop
 * signs at any time during navigation, provided the data is available.
 *
 * Defaults to NO.
 */
@property(nonatomic, assign) BOOL showsTrafficLights;

/**
 * Whether to show stop signs along the route during navigation.
 *
 * Changes to this setting take effect only in subsequent route requests.
 *
 * Once the setting is applied, the user interface shows the first 3 upcoming traffic lights or stop
 * signs at any time during navigation, provided the data is available.
 *
 * Defaults to NO.
 */
@property(nonatomic, assign) BOOL showsStopSigns;

/**
 * The primary background color to use for the navigation header. The default value is nil. When the
 * value of this property is nil, green will be used as the primary background color.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderPrimaryBackgroundColor;

/**
 * The secondary background color to use for the navigation header. Appears as the background color
 * in next-turn and lane guidance dropdowns. The default value is nil. When the value of this
 * property is nil, dark green will be used as the secondary background color.
 * The provided UIColor must be in a color space that supports [UIColor getRed:green:blue:alpha] or
 * it will be ignored.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderSecondaryBackgroundColor;

/** The alpha value of the navigation header view. This defaults to 1.0f (fully opaque). */
@property(nonatomic, assign) CGFloat navigationHeaderBackgroundAlpha;

/**
 * The primary background color of the navigation header, in night mode, when the navigation header
 * is showing the current step. The default value is nil. When the value of this property is nil,
 * @c navigationHeaderPrimaryBackgroundColor will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderPrimaryBackgroundColorNightMode;

/**
 * The secondary background color of the navigation header, in night mode, when the navigation
 * header is showing the current step. The default value is nil. When the value of this property is
 * nil, @c navigationHeaderSecondaryBackgroundColor will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderSecondaryBackgroundColorNightMode;

/** The color of the maneuver icon in the primary navigation header view. */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderLargeManeuverIconColor;

/** The color of the maneuver icon in the next turn navigation header view. */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderSmallManeuverIconColor;

/**
 * The color of the recommended lane or lanes. Defaults to white. This property is taken into
 * consideration only if the navigation header is displaying the current navigation step. Note that
 * the other lanes (the ones the driver should not take) are automatically colored using a grayed
 * out version of the secondary background color.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderGuidanceRecommendedLaneColor;

/**
 * The color of the text in the next step header when the navigation header is showing the current
 * step. The default value is nil. When the value of this property is nil or when the navigation is
 * showing any other step, white will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderNextStepTextColor;

/**
 * The font of the text in the next step header. The default value is nil. When the value of this
 * property is nil, the system font of size 16.0f will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderNextStepFont;

/**
 * The color of the text for the distance value when the navigation header is showing the current
 * step. The default value is nil. When the value of this property is nil or when the navigation is
 * showing any other step, white will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderDistanceValueTextColor;

/**
 * The font of the text for the distance value. The default value is nil. When the value of this
 * property is nil, the system bold font of size 24.0f will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderDistanceValueFont;

/**
 * The color of the text for the distance units when the navigation header is showing the current
 * step. The default value is nil. When the value of this property is nil or when the navigation is
 * showing any other step, gray will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderDistanceUnitsTextColor;

/**
 * The font of the text for the distance units. The default value is nil. When the value of this
 * property is nil, the system font of size 18.0f will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderDistanceUnitsFont;

/**
 * The color of the text in the instructions section. The default value is nil. When the value of
 * this property is nil, white will be used.
 */
@property(nonatomic, copy, nullable) UIColor *navigationHeaderInstructionsTextColor;

/**
 * The font of the text for the first row in the instructions section. The default value is nil.
 * When the value of this property is nil, the system bold font of size 30 will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderInstructionsFirstRowFont;

/**
 * The font of the text for the second row in the instructions section. The default value is nil.
 * When the value of this property is nil, the system bold font of size 24 will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderInstructionsSecondRowFont;

/**
 * The font of the text for the conjunctions in the instructions section. The default value is nil.
 * When the value of this property is nil, the system bold font of size 18 will be used.
 */
@property(nonatomic, copy, nullable) UIFont *navigationHeaderInstructionsConjunctionsFont;

/**
 * Sets the speedometer UI configuration based on speed alert severity.
 *
 * By setting a GMSNavigationSpeedometerUIOptions, you clear the previous one if set. When no
 * GMSNavigationSpeedometerUIOptions is configured, speed alert UI fallbacks to NavSDK default
 * configurations:
 * - Minor speed alert in day mode: red text with white background.
 * - Minor speed alert in night mode: red text with dark background.
 * - Major speed alert in day mode: white text with red background.
 * - Major speed alert in night mode: white text with red background.
 */
@property(nonatomic, copy, nullable) GMSNavigationSpeedometerUIOptions *speedometerUIOptions;

@end

NS_ASSUME_NONNULL_END
