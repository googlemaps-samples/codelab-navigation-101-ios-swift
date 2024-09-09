//
//  GMSNavigator.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#if __has_feature(modules)
@import GoogleMapsBase;
#else
#import <GoogleMapsBase/GoogleMapsBase.h>
#endif
#import "GMSNavigationDelayCategory.h"
#import "GMSNavigationTypes.h"

@class GMSNavigationLicensePlateRestriction;
@class GMSNavigationNavInfo;
@class GMSNavigationRouteInfo;
@class GMSNavigationRoutingOptions;
@class GMSNavigationSpeedAlertOptions;
@class GMSNavigationWaypoint;
@class GMSNavigator;
@class GMSPath;
@class GMSRouteLeg;

NS_ASSUME_NONNULL_BEGIN

/** Listener for events on GMSNavigator. */
@protocol GMSNavigatorListener <NSObject>

@optional

/**
 * Called when the driver has arrived at a GMSNavigationWaypoint.
 *
 * @param waypoint The waypoint that was arrived at.
 */
- (void)navigator:(GMSNavigator *)navigator didArriveAtWaypoint:(GMSNavigationWaypoint *)waypoint;

/**
 * Called when the current route changes or is cleared.
 *
 * Note that there are several types of triggers for this listener, including
 * but not limited to:
 *
 * <ul>
 *   <li>the in-progress trip was updated
 *   <li>the driver diverged from the current route
 *   <li>the driver selected an alternative route from the UI
 *   <li>the driver was offered or required to use a better route
 *   <li>the driver started navigating to a destination (via a call to setDestinations)
 *   <li>the driver started navigating to a new waypoint after arriving at a
 *   previous one
 *   <li>the route was cleared (via a call to clearDestinations)
 * </ul>
 */
- (void)navigatorDidChangeRoute:(GMSNavigator *)navigator;

/**
 * Called when the estimated time(s) to the destination(s) are updated.
 *
 * @param time The time to the next destination.
 */
- (void)navigator:(GMSNavigator *)navigator didUpdateRemainingTime:(NSTimeInterval)time;

/**
 * Called when the estimated distance(s) to the destination(s) are updated.
 *
 * @param distance The distance to the next destination.
 */
- (void)navigator:(GMSNavigator *)navigator didUpdateRemainingDistance:(CLLocationDistance)distance;

/**
 * Called when the delay category to the destination(s) are updated.
 *
 * @param delayCategory The delay category to the next destination.
 */
- (void)navigator:(GMSNavigator *)navigator
    didUpdateDelayCategory:(GMSNavigationDelayCategory)delayCategory;

/**
 * Called when the estimated lighting conditions are updated, for example when night falls at the
 * devices's current location.
 *
 * @param lightingMode The suggested color mode to match the current lighting conditions.
 */
- (void)navigator:(GMSNavigator *)navigator
    didChangeSuggestedLightingMode:(GMSNavigationLightingMode)lightingMode;

/**
 * Notifies you that the driver is exceeding the speed limit by the specified percentage.
 *
 * @param navigator GMSNavigator that reports the speeding.
 * @param percentageAboveLimit Percentage above the speed limit the driver is currently driving at.
 *     Set to 0 when the driver is not speeding. Set to -1 when the speed limit or current speed is
 *     invalid.
 */
- (void)navigator:(GMSNavigator *)navigator
    didUpdateSpeedingPercentage:(CGFloat)percentageAboveLimit;

/**
 * Notifies you that the device has detected that the vehicle is exceeding the speed limit by the
 * specified percentage along with the current speed alert severity. This is called at regular
 * intervals whenever a valid speed or speed limit update is available. This usually results in
 * frequent calls during active navigation when the driver is moving.
 *
 * @param navigator GMSNavigator that reports the speeding.
 * @param speedAlertSeverity The severity of the current speed alert. Set to
 *    @c GMSNavigationSpeedAlertSeverityUnknown when the speed limit is unknown or the speed is
 *    invalid. Set to @c GMSNavigationSpeedAlertSeverityNotSpeeding when the driver is not speeding
 *    according to the thresholds configured in @c GMSNavigationSpeedAlertOptions. When the driver
 *    is speeding this will be set to @c GMSNavigationSpeedAlertSeverityMinor or
 *    @c GMSNavigationSpeedAlertSeverityMajor according to the configured thresholds.
 * @param percentageAboveLimit Percentage above the speed limit the driver is currently driving at.
 *    Only valid when speedAlertSeverity is Minor or Major.
 */
- (void)navigator:(GMSNavigator *)navigator
    didUpdateSpeedAlertSeverity:(GMSNavigationSpeedAlertSeverity)speedAlertSeverity
             speedingPercentage:(CGFloat)percentageAboveLimit;

/**
 * Called when the current @c GMSNavigationNavInfo is updated. This is called regularly during
 * active navigation.
 *
 * @param navInfo The updated @c GMSNavigationNavInfo.
 */
- (void)navigator:(GMSNavigator *)navigator didUpdateNavInfo:(GMSNavigationNavInfo *)navInfo;

@end

/**
 * Called when a route from the device's location to the provided destination(s) is found, or fails
 * to be found for a reason indicated by the RouteStatus.
 *
 * @related GMSNavigator
 */
typedef void (^GMSRouteStatusCallback)(GMSRouteStatus routeStatus);

/**
 * Called when the route information (ETA and distance) to the provided waypoint is calculated.
 *
 * @param routeInfo The route information to the given destination. Will be nil if the calculation
 *                  fails.
 * @related GMSNavigator
 */
typedef void (^GMSRouteInfoCallback)(GMSNavigationRouteInfo *_Nullable routeInfo);

/**
 * Called if setting transaction IDs through the setTransactionIDs fails. Refer documentation for
 * the API for more details.
 *
 * @related GMSNavigator
 */
typedef void (^GMSNavigationTransactionIDErrorHandler)(NSError *error);

/**
 * This is the main class of the Google Navigation SDK for iOS and provides methods for controlling
 * navigation to a destination and accessing route and progress information.
 *
 * This class does not support subclassing.
 *
 * This class is not thread-safe. All methods must be called from the main thread.
 */
@interface GMSNavigator : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Adds a listener. The listener is held with a weak reference.
 *
 * @param listener An object conforming to the @c GMSNavigatorListener protocol.
 */
- (void)addListener:(id<GMSNavigatorListener>)listener;

/**
 * Removes a listener.
 *
 * @param listener An object conforming to the @c GMSNavigatorListener protocol.
 *
 * @return Returns YES if the listener was removed. Returns NO if the object was not a listener.
 */
- (BOOL)removeListener:(id<GMSNavigatorListener>)listener;

#pragma mark Destinations and Routes

/**
 * Sets multiple destinations for navigation, overriding any previously set destinations.
 *
 * The provided callback will be called with GMSRouteStatusOK if a route is found from the device's
 * location to the given destination. If a new destination is set before a route is found, then the
 * request will be canceled, and the callback will be called with GMSRouteStatusCanceled. If a
 * route cannot be found for any other reason, the callback will be called with an appropriate error
 * status.
 *
 * The callback will always be dispatched asynchronously on the main queue.
 */
- (void)setDestinations:(NSArray<GMSNavigationWaypoint *> *)destinations
               callback:(GMSRouteStatusCallback)callback;

/**
 * Sets multiple destinations for navigation, overriding any previously set destinations. The
 * returned routes are calculated using routing options.
 *
 * @param destinations An array of destination waypoints.
 * @param routingOptions The options that influence routing logic (routing strategy).
 * @param callback Called when a route from the consumer’s location to the provided destination(s)
 *                 is found, or fails to be found for a reason indicated by the RouteStatus.
 */
- (void)setDestinations:(NSArray<GMSNavigationWaypoint *> *)destinations
         routingOptions:(GMSNavigationRoutingOptions *)routingOptions
               callback:(GMSRouteStatusCallback)callback;

/**
 * Sets multiple destinations for navigation, using a route token to navigate on a precomputed
 * route. Routes will be the same, modulo changes to the driver starting location and to
 * road/traffic conditions. Re-routes will still occur based on the routing options encoded in
 * the token.
 *
 * Only @c GMSNavigationTravelModeDriving and @c GMSNavigationTravelModeTwoWheeler
 * are supported when you use the route token to start a navigation session. Configure the travel
 * mode by setting @c travelMode. The call will fail if the current travel mode is unsupported, and
 * a @c GMSRouteStatusTravelModeUnsupported will be returned in the callback.
 *
 * @param destinations An array of destination waypoints, should be the same as the destinations
 *     given to RoutesPreferred API to get the route token.
 * @param routeToken A route token string returned by RoutesPreferred API. Routing options
 *     specified in RoutesPreferred API are encoded in this route token, and will be used to
 *     regenerate the precomputed route or a new route when reroute happens.
 * @param callback Called when a route from the consumer's location to the provided destination(s)
 *     is found, or fails to be found for a reason indicated by the RouteStatus.
 */
- (void)setDestinations:(NSArray<GMSNavigationWaypoint *> *)destinations
             routeToken:(NSString *)routeToken
               callback:(GMSRouteStatusCallback)callback;

/**
 * Returns route information based on the routing strategy: default best or shorter route. This
 * method is only available to Mobility Services customers who are billed by Google on a
 * per-transaction basis. Returns a `nil` value if the project lacks permission to call this API.
 *
 * @param destination The destination waypoint.
 * @param routingOptions The options used to fetch the route info. The routing strategy and
 *                       alternate routes strategy are ignored since this method returns the route
 *                       information for all routing strategies.
 * @param callback The callback called when routes information are received.
 */
- (void)getRouteInfoForDestination:(GMSNavigationWaypoint *)destination
                withRoutingOptions:(GMSNavigationRoutingOptions *)routingOptions
                          callback:(GMSRouteInfoCallback)callback;

/**
 * Deprecated. Call one of the @c -setDestinations:... methods with the new list of destinations
 * instead.
 *
 * Pops the first destination from the current list of destinations. Following this call, guidance
 * will be toward the next destination, if any.
 *
 * @return the waypoint guidance is now heading towards, or nil if there are no more waypoints left.
 */
- (nullable GMSNavigationWaypoint *)continueToNextDestination __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
    "Use one of the -setDestinations:... methods instead.");

/**
 * Clears all previously set destinations and removes any calculated routes from the map. If
 * guidance is active, this will automatically stop it.
 */
- (void)clearDestinations;

/** Whether to avoid highways when generating routes to destinations. Defaults to NO. */
@property(nonatomic, assign) BOOL avoidsHighways;

/** Whether to avoid toll roads when generating routes to destinations. Defaults to NO. */
@property(nonatomic, assign) BOOL avoidsTolls;

/** Whether to avoid ferries when generating routes to destinations. Defaults to YES. */
@property(nonatomic, assign) BOOL avoidsFerries;

/**
 * Set license plate restriction with current driver's last digit of license plate and country
 * code. This allows us to route around certain types of road restrictions which are based on
 * license plate number. This will only apply to setDestinations calls made after this value is
 * set. Ideally you'd set this immediately after getting the navigator.
 *
 * Set to nil if there is no license plate restriction. Default to nil.
 */
@property(nonatomic, nullable) GMSNavigationLicensePlateRestriction *licensePlateRestriction;

#pragma mark Guidance

/**
 * Whether turn-by-turn guidance is currently enabled. If guidanceActive is YES, but no route is
 * currently available then guidance will start when a route becomes available. This property will
 * be set to NO if clearDestinations is called, or we arrive at a waypoint.
 */
@property(nonatomic, getter=isGuidanceActive) BOOL guidanceActive;

/**
 * Whether guidance should automatically stop when @c -navigator:didArriveAtWaypoint: is called.
 *
 * When NO, the navigation header and footer will continue to be shown after arrival. The navigation
 * header will continue to show the final guidance step and the navigation footer will continue to
 * update the remaining time and distance until a time/distance of 0 is reached. Additionally,
 * @c -navigator:didUpdateRemainingTime and @c -navigator:didUpdateRemainingDistance updates will
 * continue. Explicitly set @c guidanceActive to NO to stop guidance and remaining time/distance
 * updates.
 *
 * When YES, @c guidanceActive will automatically be set to NO upon arrival.
 *
 * Defaults to YES.
 */
@property(nonatomic) BOOL stopGuidanceAtArrival;

/**
 * The minimum change in estimated time to the next destination that will trigger the
 * |navigator:didUpdateRemainingTime:| method to be called.
 *
 * If this is set to NSTimeIntervalMax, then time update callbacks will be disabled. If this is set
 * to a negative value, then the default threshold of one second will be used. Defaults to one
 * second.
 *
 * @note This value is ignored if no listeners implement @c navigator:didUpdateRemainingTime:.
 */
@property(nonatomic) NSTimeInterval timeUpdateThreshold;

/**
 * The minimum change in estimated distance to the next destination that will trigger the
 * |navigator:didUpdateRemainingDistance:| method to be called.
 *
 * If this is set to CLLocationDistanceMax, then distance update callbacks will be disabled. If this
 * is set to a negative value, then the default threshold of one meter will be used. Defaults to one
 * meter.
 *
 * @note This value is ignored if no listeners implement @c navigator:didUpdateRemainingDistance:.
 */
@property(nonatomic) CLLocationDistance distanceUpdateThreshold;

/**
 * Returns the estimated time to the next destination. This will be updated based on the current
 * device position whilst guidance is active.
 *
 * Returns CLTimeIntervalMax if no route is available.
 */
@property(nonatomic, readonly) NSTimeInterval timeToNextDestination;

/**
 * Returns the estimated distance to the next destination. This will be updated based on the current
 * device position whilst guidance is active.
 *
 * Returns CLLocationDistanceMax if no route is available.
 */
@property(nonatomic, readonly) CLLocationDistance distanceToNextDestination;

/**
 * Returns the delay category to the next destination. This will be updated based on the current
 * device position whilst guidance is active.
 *
 * Returns GMSNavigationDelayCategoryNoData if no route is available or traffic data is unavailable.
 */
@property(nonatomic, readonly) GMSNavigationDelayCategory delayCategoryToNextDestination;

/**
 * Returns the estimated time to the given waypoint, or CLTimeIntervalMax if the waypoint is not
 * part of the current route. This is updated based on the current device position while
 * guidance is active.
 *
 * Returns CLTimeIntervalMax if the provided waypoint is not a destination in the current route.
 */
- (NSTimeInterval)timeToWaypoint:(GMSNavigationWaypoint *)waypoint;

/**
 * Returns the estimated distance to the given waypoint, or CLLocationDistanceMax if the waypoint is
 * not part of the current route. This will be updated based on the current device position whilst
 * guidance is active.
 *
 * Returns CLLocationDistanceMax if the provided waypoint is not a destination in the current route.
 */
- (CLLocationDistance)distanceToWaypoint:(GMSNavigationWaypoint *)waypoint;

/**
 * The current leg of the journey. This GMSRouteLeg will have its starting position as the most
 * recent known (road-snapped) position of the device.
 */
@property(nonatomic, readonly, nullable) GMSRouteLeg *currentRouteLeg;

/** An array of route legs where each leg corresponds to a destination that was set. */
@property(nonatomic, readonly, nullable) NSArray<GMSRouteLeg *> *routeLegs;

/**
 * The path that the user has traveled in the most recent guidance session, defined as the last time
 * guidanceActive was set to YES. The path consists of road-snapped locations returned by the
 * @c GMSRoadSnappedLocationProvider and simplified to produce line segments. Note: The system polls
 * the client for GPS signals to obtain location data. Poor GPS signal can result in further
 * interpolation, which might produce less precise routes. This path is empty if guidance has never
 * started.
 */
@property(nonatomic, readonly) GMSPath *traveledPath;

#pragma mark Audio guidance

/**
 * Determines whether voice guidance should be enabled for traffic and turn-by-turn alerts.
 *
 * Defaults to GMSNavigationVoiceGuidanceAlertsAndGuidance.
 */
@property(nonatomic, assign) GMSNavigationVoiceGuidance voiceGuidance;

/**
 * Determines what audio devices voice guidance may be played through.
 *
 * Defaults to GMSVoiceGuidanceAudioDeviceTypeBluetooth.
 */
@property(nonatomic, assign) GMSVoiceGuidanceAudioDeviceType audioDeviceType;

/** Determines whether the device should also vibrate when voice alerts are played. */
@property(nonatomic, assign, getter=isVibrationEnabled) BOOL vibrationEnabled;

/**
 * Determines whether UILocalNotifications containing guidance information will be presented when
 * the app is in the background. Defaults to YES.
 */
@property(nonatomic, assign) BOOL sendsBackgroundNotifications;

/** The suggested lighting mode, based on the time of day and device location. */
@property(nonatomic, assign, readonly) GMSNavigationLightingMode suggestedLightingMode;

/**
 * Determines whether prompts for traffic, better routes and incidents should be displayed.
 * Defaults to YES.
 */
@property(nonatomic, assign) BOOL shouldDisplayPrompts;

/**
 * GMSNavigationSpeedAlertOptions for customizing the triggering thresholds for
 * GMSNavigationSpeedAlertSeverity.
 *
 * You can use this property to customize the speed alert triggering thresholds in percentage for
 * both minor and major alerts. You can also use this method to customize the time based triggering
 * threshold for major speed alert.
 *
 * By setting nil, you won't receive any speeding feed data, and the NavSDK's default speed alert
 * will display: speed alert shows red text when the speed is more than 5 mph or 10 kph over the
 * speed limit, and shows white text and red background when speeding more than 10 mph or 20kph.
 */
@property(nonatomic, nullable) GMSNavigationSpeedAlertOptions *speedAlertOptions;

#pragma mark Transaction IDs

/**
 * Sets and logs to the server the ongoing transaction IDs that apply to the navigation events
 * during the current navigation session. Transaction IDs will be cleared at the end of the
 * navigation session. This method is only available to Mobility Services customers who are billed
 * by Google on a per-transaction basis. Returns a `nil` value if the project lacks permission to
 * call this API.
 *
 * @param transactionIDs The transaction IDs that apply to the current navigation session. The
 *     transaction ID must be unique for each billable transaction. An individual transaction ID
 *     must contain at least one and at most 64 characters. The list can be empty when a
 *     transaction has ended (but the session is still ongoing).
 * @param errorHandler A block that will be invoked asynchronously on the main thread if an error
 *     occurs when the transaction IDs are invalid.
 */
- (void)setTransactionIDs:(NSArray<NSString *> *)transactionIDs
             errorHandler:(nullable GMSNavigationTransactionIDErrorHandler)errorHandler;

@end

NS_ASSUME_NONNULL_END
