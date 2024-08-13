//
//  GMSNavigationTypes.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

/**
 * \defgroup NavigationTypes GMSNavigationTypes
 * @{
 */
#ifndef IPHONE_MAPS_SDK_NAV_GMSNAVIGATIONTYPES_H_
#import <Foundation/Foundation.h>

#define IPHONE_MAPS_SDK_NAV_GMSNAVIGATIONTYPES_H_

/** The camera mode which determines the camera following behavior. */
typedef NS_ENUM(NSInteger, GMSNavigationCameraMode) {
  /** Disables camera following. The camera is in this mode when it is being panned by the user. */
  GMSNavigationCameraModeFree = 0,

  /** Follows the user location with the current followingPerspective. */
  GMSNavigationCameraModeFollowing,

  /** Shows an overview of the remaining route. This is dynamically updated in guidance mode. */
  GMSNavigationCameraModeOverview,
};

/** The different camera perspectives that can be set when following the user location. */
typedef NS_ENUM(NSInteger, GMSNavigationCameraPerspective) {
  /**
   * The camera automatically rotates to face the user bearing and is tilted. When guidance is
   * inactive, the user location is positioned at the center of the viewport. When guidance is
   * active, the user location is positioned near the bottom of the viewport.
   */
  GMSNavigationCameraPerspectiveTilted = 0,

  /**
   * The camera is always oriented north and looks directly downwards. The user location is
   * positioned at the center of the screen.
   */
  GMSNavigationCameraPerspectiveTopDownNorthUp,

  /**
   * The camera automatically rotates to face the user bearing and looks directly downwards. When
   * guidance is inactive, the user location is positioned at the center of the viewport. When
   * guidance is active, the user location is positioned near the bottom of the viewport.
   */
  GMSNavigationCameraPerspectiveTopDownHeadingUp,
};

/** The different travel modes that can be used for navigation. */
typedef NS_ENUM(NSInteger, GMSNavigationTravelMode) {
  /**
   * Driving routes will be fetched, and the reported user course will be based on the direction of
   * movement.
   */
  GMSNavigationTravelModeDriving = 0,

  /**
   * Cycling routes will be fetched, and the reported user course will be based on the compass
   * direction the device is facing.
   */
  GMSNavigationTravelModeCycling,

  /**
   * Walking routes will be fetched, and the reported user course will be based on the compass
   * direction the device is facing.
   */
  GMSNavigationTravelModeWalking,

  /**
   * Two-wheeler routes will be fetched, and the reported user course will be based on the direction
   * of movement.
   */
  GMSNavigationTravelModeTwoWheeler,

  /**
   * Taxicab routes will be fetched, and the reported user course will be based on the direction
   * of movement.
   */
  GMSNavigationTravelModeTaxicab,
};

/** Determines whether voice guidance is played under certain circumstances. */
typedef NS_ENUM(NSInteger, GMSNavigationVoiceGuidance) {
  /** Disables voice guidance. */
  GMSNavigationVoiceGuidanceSilent = 0,

  /** Enables voice guidance for traffic alerts only. */
  GMSNavigationVoiceGuidanceAlertsOnly,

  /** Enables voice guidance for both turn-by-turn guidance and alerts. */
  GMSNavigationVoiceGuidanceAlertsAndGuidance,
};

/** Determines what type of audio devices voice guidance may be played through. */
typedef NS_ENUM(NSInteger, GMSVoiceGuidanceAudioDeviceType) {
  /** Voice guidance plays only through the built-in device speaker or headphones. */
  GMSVoiceGuidanceAudioDeviceTypeBuiltInOnly = 0,

  /**
   * Voice guidance plays over a bluetooth connection if available, else it uses the built-in device
   * speaker or headphones.
   */
  GMSVoiceGuidanceAudioDeviceTypeBluetooth,
};

/** A GMSRouteStatus is a status code that represents the result of a route request. */
typedef NS_ENUM(NSInteger, GMSRouteStatus) {
  /**
   * A route could not be calculated because of an internal error. In some case, this can be
   * resolved by updating to a newer SDK version.
   */
  GMSRouteStatusInternalError = 0,

  /** A route to the destination was successfully calculated. */
  GMSRouteStatusOK,

  /** A route to the destination could not be calculated. */
  GMSRouteStatusNoRouteFound,

  /** A route to the destination could not be calculated because of a network error. */
  GMSRouteStatusNetworkError,

  /** A route to the destination could not be calculated because of insufficient quota. */
  GMSRouteStatusQuotaExceeded,

  /**
   * A route could not be calculated because the provided key does not have permission to use the
   * Navigation SDK.
   */
  GMSRouteStatusAPIKeyNotAuthorized,

  /** The route calculation was canceled in favor of a newer one. */
  GMSRouteStatusCanceled,

  /**
   * A route could not be calculated because there were duplicate waypoints present in the request.
   */
  GMSRouteStatusDuplicateWaypointsError,

  /** A route could not be calculated because no waypoints were provided. */
  GMSRouteStatusNoWaypointsError,

  /**
   * A route could not be calculated because the user's location is not available. This could be
   * because the user hasn't granted location permissions for the app.
   */
  GMSRouteStatusLocationUnavailable,

  /**
   * A route could not be generated because there was a problem with the waypoints provided in the
   * request. For example, a stale or invalid Place ID may have been provided.
   */
  GMSRouteStatusWaypointError,

  /**
   * A route could not be generated if given an unsupported travel mode. For example, if you are
   * setting destinations with a route token, only Driving and TwoWheeler travel mode are supported.
   */
  GMSRouteStatusTravelModeUnsupported,
};

/** Lighting mode is used to specify different color schemes based on available light. */
typedef NS_ENUM(NSInteger, GMSNavigationLightingMode) {
  /** Use a lighting mode suitable for daylight viewing. */
  GMSNavigationLightingModeNormal = 0,

  /** Use a lighting mode suitable for night viewing. */
  GMSNavigationLightingModeLowLight,
};

/**
 * The routing strategy specifies how routes are ranked, which affects the route when it is chosen
 * and during re-routing. The default value is GMSNavigationRoutingStrategyDefaultBest.
 */
typedef NS_ENUM(NSInteger, GMSNavigationRoutingStrategy) {
  /**
   * Ranks routes by NavSDK default cost model. This is the default routing strategy for navigating.
   */
  GMSNavigationRoutingStrategyDefaultBest = 0,

  /** Ranks routes by distance. The highest ranking route is the shortest of those returned. */
  GMSNavigationRoutingStrategyShorter,

  /** Ranks routes by absolute delta to a target distance, from smallest to largetest*/
  GMSNavigationRoutingStrategyDeltaToTargetDistance,
};

/** The format specifies whether to show distance or ETA information in route callouts. */
typedef NS_ENUM(NSInteger, GMSNavigationRouteCalloutFormat) {
  /**
   * Shows the time or distance, depending on the routing strategy. Shows time with the default best
   * routing strategy and distance with the shorter routing strategy.
   */
  GMSNavigationRouteCalloutFormatDefault = 0,

  /** Shows time information in route callouts (e.g., 10 min, 5 min faster). */
  GMSNavigationRouteCalloutFormatTime,

  /** Shows distance information in route callouts (e.g., 10 km, 5 km longer). */
  GMSNavigationRouteCalloutFormatDistance,
};

/** Indicates the maximum number of alternate routes that can be requested. */
typedef NS_ENUM(NSInteger, GMSNavigationAlternateRoutesStrategy) {
  /** All available alternate routes should be shown. */
  GMSNavigationAlternateRoutesStrategyAll = 0,

  /** No alternate routes should be shown. */
  GMSNavigationAlternateRoutesStrategyNone,

  /** One alternate route should be shown. */
  GMSNavigationAlternateRoutesStrategyOne,
};

typedef NS_ENUM(NSInteger, GMSNavigationSpeedAlertSeverity) {
  /** Either speed or speed limit could not be determined. */
  GMSNavigationSpeedAlertSeverityUnknown = -2,

  /** No speeding is occurring. */
  GMSNavigationSpeedAlertSeverityNotSpeeding = -1,

  /** Minor speed alert. */
  GMSNavigationSpeedAlertSeverityMinor = 0,

  /** Major speed alert. */
  GMSNavigationSpeedAlertSeverityMajor,
};

/** The state of navigation. */
typedef NS_ENUM(NSInteger, GMSNavigationNavState) {
  /** Error or unspecified state. */
  GMSNavigationNavStateUnknown = 0,

  /** Actively navigating. Information about the upcoming maneuver step is available. */
  GMSNavigationNavStateEnroute = 1,

  /**
   * Actively navigating but searching for a new route. The upcoming maneuver step is not yet
   * available.
   */
  GMSNavigationNavStateRerouting = 2,

  /** Navigation has ended. */
  GMSNavigationNavStateStopped = 3

};

/** Whether this step is on a drive-on-right or drive-on-left route. May be unspecified. */
typedef NS_ENUM(NSUInteger, GMSNavigationDrivingSide) {
  /** Unspecified side. */
  GMSNavigationDrivingSideNone = 0,

  /** Drive-on-left side. */
  GMSNavigationDrivingSideLeft = 1,

  /** Drive-on-right side. */
  GMSNavigationDrivingSideRight = 2,

};

/** A set of values that specify the navigation action to take. */
typedef NS_ENUM(NSUInteger, GMSNavigationManeuver) {
  /** Unknown maneuver. */
  GMSNavigationManeuverUnknown = 0,

  /** Starting point of the maneuver. */
  GMSNavigationManeuverDepart = 1,

  /** Arrival at a destination. */
  GMSNavigationManeuverDestination = 2,

  /** Arrival at a destination located on the left side of the road. */
  GMSNavigationManeuverDestinationLeft = 3,

  /** Arrival at a destination located on the right side of the road. */
  GMSNavigationManeuverDestinationRight = 4,

  /** Continue straight. */
  GMSNavigationManeuverStraight = 5,

  /** Starting point of the maneuver. */
  GMSNavigationManeuverTurnLeft = 6,

  /** Regular right turn at an intersection. */
  GMSNavigationManeuverTurnRight = 7,

  /** Keep left as the road diverges. */
  GMSNavigationManeuverTurnKeepLeft = 8,

  /** Keep right as the road diverges. */
  GMSNavigationManeuverTurnKeepRight = 9,

  /** Slight left turn at an intersection. */
  GMSNavigationManeuverTurnSlightLeft = 10,

  /** Slight right turn at an intersection. */
  GMSNavigationManeuverTurnSlightRight = 11,

  /** Sharp left turn at an intersection. */
  GMSNavigationManeuverTurnSharpLeft = 12,

  /** Sharp right turn at an intersection. */
  GMSNavigationManeuverTurnSharpRight = 13,

  /** Clockwise turn onto the opposite side of the street. */
  GMSNavigationManeuverTurnUTurnClockwise = 14,

  /** Counterclockwise turn onto the opposite side of the street. */
  GMSNavigationManeuverTurnUTurnCounterClockwise = 15,

  /** Current road joins another. */
  GMSNavigationManeuverMergeUnspecified = 16,

  /** Current road joins another on the left. */
  GMSNavigationManeuverMergeLeft = 17,

  /** Current road joins another on the right. */
  GMSNavigationManeuverMergeRight = 18,

  /** Current road joins another road slightly on the left. */
  GMSNavigationManeuverForkLeft = 19,

  /** Current road joins another road slightly on the right. */
  GMSNavigationManeuverForkRight = 20,

  /** Enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampUnspecified = 21,

  /** Regular left turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampLeft = 22,

  /** Regular right turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampRight = 23,

  /** Keep to the left side of the road when entering a turnpike or freeway as the road diverges. */
  GMSNavigationManeuverOnRampKeepLeft = 24,

  /**
   * Keep to the right side of the road when entering a turnpike or freeway as the road diverges.
   */
  GMSNavigationManeuverOnRampKeepRight = 25,

  /** Slight left turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampSlightLeft = 26,

  /** Slight right turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampSlightRight = 27,

  /** Sharp left turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampSharpLeft = 28,

  /** Sharp right turn to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampSharpRight = 29,

  /** Clockwise turn onto the opposite side of the street to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampUTurnClockwise = 30,

  /** Counterclockwise turn onto the opposite side of the street to enter a turnpike or freeway. */
  GMSNavigationManeuverOnRampUTurnCounterClockwise = 31,

  /** Exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampUnspecified = 32,

  /** Regular left turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampLeft = 33,

  /** Regular right turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampRight = 34,

  /** Keep to the left side of the road when exiting a turnpike or freeway as the road diverges. */
  GMSNavigationManeuverOffRampKeepLeft = 35,

  /** Keep to the right side of the road when exiting a turnpike or freeway as the road diverges. */
  GMSNavigationManeuverOffRampKeepRight = 36,

  /** Slight left turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampSlightLeft = 37,

  /** Slight right turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampSlightRight = 38,

  /** Sharp left turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampSharpLeft = 39,

  /** Sharp right turn to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampSharpRight = 40,

  /** Clockwise turn onto the opposite side of the street to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampUTurnClockwise = 41,

  /** Counterclockwise turn onto the opposite side of the street to exit a turnpike or freeway. */
  GMSNavigationManeuverOffRampUTurnCounterClockwise = 42,

  /** Enter a roundabout in the clockwise direction. */
  GMSNavigationManeuverRoundaboutClockwise = 43,

  /** Enter a roundabout in the counterclockwise direction. */
  GMSNavigationManeuverRoundaboutCounterClockwise = 44,

  /** Enter a roundabout in the clockwise direction and continue straight. */
  GMSNavigationManeuverRoundaboutStraightClockwise = 45,

  /** Enter a roundabout in the counterclockwise direction and continue straight. */
  GMSNavigationManeuverRoundaboutStraightCounterClockwise = 46,

  /** Enter a roundabout in the clockwise direction and turn left. */
  GMSNavigationManeuverRoundaboutLeftClockwise = 47,

  /** Enter a roundabout in the counterclockwise direction and turn left. */
  GMSNavigationManeuverRoundaboutLeftCounterClockwise = 48,

  /** Enter a roundabout in the clockwise direction and turn right. */
  GMSNavigationManeuverRoundaboutRightClockwise = 49,

  /** Enter a roundabout in the counterclockwise direction and turn right. */
  GMSNavigationManeuverRoundaboutRightCounterClockwise = 50,

  /** Enter a roundabout in the clockwise direction and turn slightly left. */
  GMSNavigationManeuverRoundaboutSlightLeftClockwise = 51,

  /** Enter a roundabout in the counterclockwise direction and turn slightly to the left. */
  GMSNavigationManeuverRoundaboutSlightLeftCounterClockwise = 52,

  /** Enter a roundabout in the clockwise direction and turn slightly to the right. */
  GMSNavigationManeuverRoundaboutSlightRightClockwise = 53,

  /** Enter a roundabout in the counterclockwise direction and turn slightly to the right. */
  GMSNavigationManeuverRoundaboutSlightRightCounterClockwise = 54,

  /** Enter a roundabout in the clockwise direction and turn sharply to the left. */
  GMSNavigationManeuverRoundaboutSharpLeftClockwise = 55,

  /** Enter a roundabout in the counterclockwise direction and turn sharply to the left. */
  GMSNavigationManeuverRoundaboutSharpLeftCounterClockwise = 56,

  /** Enter a roundabout in the clockwise direction and turn sharply to the right. */
  GMSNavigationManeuverRoundaboutSharpRightClockwise = 57,

  /** Enter a roundabout in the counterclockwise direction and turn sharply to the right. */
  GMSNavigationManeuverRoundaboutSharpRightCounterClockwise = 58,

  /**
   * Enter a roundabout in the clockwise direction and turn clockwise onto the opposite side of the
   * street.
   */
  GMSNavigationManeuverRoundaboutUTurnClockwise = 59,

  /**
   * Enter a roundabout in the counterclockwise direction and turn counterclockwise onto the
   * opposite side of the street.
   */
  GMSNavigationManeuverRoundaboutUTurnCounterClockwise = 60,

  /** Exit a roundabout in the clockwise direction. */
  GMSNavigationManeuverRoundaboutExitClockwise = 61,

  /** Exit a roundabout in the counterclockwise direction. */
  GMSNavigationManeuverRoundaboutExitCounterClockwise = 62,

  /** Take the boat ferry. */
  GMSNavigationManeuverFerryBoat = 63,

  /** Take the train ferry. */
  GMSNavigationManeuverFerryTrain = 64,

  /** The street name changes. */
  GMSNavigationManeuverNameChange = 65

};

/** A set of values describing the shape of a lane. */
typedef NS_ENUM(NSInteger, GMSNavigationLaneShape) {
  /** Unknown lane shape. */
  GMSNavigationLaneShapeUnknown = 0,

  /** Continue straight. */
  GMSNavigationLaneShapeStraight = 1,

  /** Slight left turn (10-45 degrees). */
  GMSNavigationLaneShapeSlightLeft = 2,

  /** Slight right turn (10-45 degrees). */
  GMSNavigationLaneShapeSlightRight = 3,

  /** Normal left turn (45-135 degrees). */
  GMSNavigationLaneShapeNormalLeft = 4,

  /** Normal right turn (45-135 degrees). */
  GMSNavigationLaneShapeNormalRight = 5,

  /** Sharp left turn (135-175 degrees). */
  GMSNavigationLaneShapeSharpLeft = 6,

  /** Sharp right turn (135-175 degrees). */
  GMSNavigationLaneShapeSharpRight = 7,

  /** A left turn onto the opposite side of the same street (175-180 degrees). */
  GMSNavigationLaneShapeUTurnLeft = 8,

  /** A right turn onto the opposite side of the same street (175-180 degrees). */
  GMSNavigationLaneShapeUTurnRight = 9
};


#endif /* IPHONE_MAPS_SDK_NAV_GMSNAVIGATIONTYPES_H_ */

/**@}*/
