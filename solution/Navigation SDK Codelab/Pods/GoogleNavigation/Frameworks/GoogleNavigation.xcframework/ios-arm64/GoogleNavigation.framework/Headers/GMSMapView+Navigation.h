//
//  GMSMapView+Navigation.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

#if __has_feature(modules)
@import GoogleMaps;
#else
#import <GoogleMaps/GoogleMaps.h>
#endif
#import "GMSNavigationTypes.h"

@class GMSLocationSimulator;
@class GMSNavigationSession;
@class GMSNavigator;
@class GMSRoadSnappedLocationProvider;

/**
 * The value used to clear the @c followingZoomLevel, and reset the camera to adopt the default
 * zoom behavior.
 */
FOUNDATION_EXTERN const float GMSNavigationNoFollowingZoomLevel;

NS_ASSUME_NONNULL_BEGIN

/** A delegate for events on GMSMapView related to the navigation UI. */
@protocol GMSMapViewNavigationUIDelegate <NSObject>

@optional

/**
 * Called when the re-center button has been tapped.
 *
 * @param mapView The map view that the re-center button is on.
 */
- (void)mapViewDidTapRecenterButton:(GMSMapView *)mapView;

@end

@interface GMSMapViewOptions (Navigation)

/**
 * The screen the view will be used on.
 *
 * Defaults to the main screen. Should be set to the CarPlay screen if this map view is to
 * be used with CarPlay.
 */
@property(nonatomic, null_resettable) UIScreen *screen;

@end

@interface GMSMapView (Navigation)

/** A delegate of GMSMapView which receives callbacks for navigation UI events. */
@property(nonatomic, weak, nullable) IBOutlet id<GMSMapViewNavigationUIDelegate>
    navigationUIDelegate;

/**
 * Whether navigation functionality is enabled for this map. If this is YES, routes and turn-by-turn
 * directions can be displayed on the map, the camera can enter following mode, and the re-center
 * button appears when the camera is not following the device location.
 *
 * If the user has not accepted the Google Navigation terms and conditions, setting this property
 * will have no effect. To show the terms and conditions dialog, see the methods on
 * GMSNavigationServices.
 */
@property(nonatomic, assign, getter=isNavigationEnabled) BOOL navigationEnabled;

/**
 * The navigator for this GMSMapView which allows routes to be requested and turn-by-turn guidance
 * to be started.
 *
 * If the user has not accepted the Google Navigation terms and conditions, this will be nil. To
 * show the terms and conditions dialog, see the methods on GMSNavigationServices.
 */
@property(nonatomic, readonly, nullable) GMSNavigator *navigator;

/**
 * Allows subscription to road-snapped location updates.
 *
 * If the user has not accepted the Google Navigation terms and conditions, this will be nil. To
 * show the terms and conditions dialog, see the methods on GMSNavigationServices.
 */
@property(nonatomic, readonly, nullable)
    GMSRoadSnappedLocationProvider *roadSnappedLocationProvider;

/**
 * Allows you to simulate the device location. The simulated location affects the position of the
 * chevron on the map, the progress of turn-by-turn guidance, and the updates provided by the
 * road-snapped location provider.
 *
 * If the user has not accepted the Google Navigation terms and conditions, this will be nil. To
 * show the terms and conditions dialog, see the methods on GMSNavigationServices.
 */
@property(nonatomic, readonly, nullable) GMSLocationSimulator *locationSimulator;

/**
 * The mode of the camera which determines its behavior when the navigationEnabled property is set
 * to YES. See |GMSNavigationCameraMode| for the available modes.
 */
@property(nonatomic, assign) GMSNavigationCameraMode cameraMode;

/**
 * The camera perspective that will be used when following the device's location. The
 * |navigationEnabled| property must be set to YES and |cameraMode| must be set to
 * GMSNavigationCameraModeFollowing for this perspective to take effect.
 */
@property(nonatomic, assign) GMSNavigationCameraPerspective followingPerspective;

/**
 * The travel mode which determines what type of routes will be fetched and the way that device
 * course is determined.
 *
 * In driving mode, device course is based on the direction of movement, while in cycling or walking
 * mode the course is based on the compass direction the device is facing. Device course is
 * represented by the direction of the device location marker and reported by the
 * GMSRoadSnappedLocationProvider.
 */
@property(nonatomic, assign) GMSNavigationTravelMode travelMode;

/**
 * The lighting mode determines which color scheme should be used for rendering the map. It is also
 * used to determine the default colors of various interface elements.
 */
@property(nonatomic, assign) GMSNavigationLightingMode lightingMode;

/**
 * Determines whether the speed limit should be displayed when guidance is active and speed limit
 * data is available. The default value is NO.
 */
@property(nonatomic, assign) BOOL shouldDisplaySpeedLimit;

/**
 * Specifies whether the speedometer icon is shown.
 *
 * When enabled, a speedometer icon that indicates the vehicle speed appears in the bottom corner
 * during guidance. When reliable speed limit data is available, the speed limit icon is also
 * visible, and is attached with the speedometer icon. The speedometer icon can have different
 * colors for text and background, depending on the speed alert severity.
 *
 * If the recenter button is enabled, then the speed limit and the speedometer icon are temporarily
 * hidden when the recenter button displays.
 */
@property(nonatomic) BOOL shouldDisplaySpeedometer;

/**
 * The rectangle that is covered by the navigation header. Height is zero when the header is hidden.
 */
@property(nonatomic, readonly) UILayoutGuide *navigationHeaderLayoutGuide;

/**
 * The rectangle that is covered by the navigation footer. Height is zero when the footer is hidden.
 */
@property(nonatomic, readonly) UILayoutGuide *navigationFooterLayoutGuide;

/** Specifies which route callout format (default, time, or distance) to use. */
@property(nonatomic, assign) GMSNavigationRouteCalloutFormat routeCalloutFormat;

/**
 * Customized zoom level during navigation. Setting this value will override the default Navigation
 * SDK zoom level when the camera is following device location (i.e. @c cameraMode equals
 * @c GMSNavigationCameraModeFollowing). This can be set to @c GMSNavigationNoFollowingZoomLevel
 * if no zoom level override should be used.
 */
@property(nonatomic) float followingZoomLevel;

/**
 * Sets the My Location provider for this map view.
 *
 * Normally the My Location dot and accuracy circle for a map view are driven by the actual device
 * location. By setting this property, the My Location dot and accuracy circle will be driven by
 * the road-snapped location from the given location provider instead. To return to the normal
 * behavior, set this property to nil.
 *
 * This has no effect when @c navigationEnabled is on for this map view.
 */
@property(nonatomic, nullable) GMSRoadSnappedLocationProvider *roadSnappedMyLocationSource;

/**
 * Begins navigation in this map view using the given navigation session.
 *
 * Note: for the most efficient use of memory and CPU, call this method before
 * invoking any other navigation-related methods on this map view.
 *
 * @return Whether navigation was successfully started (for instance, NO will
 *     be returned if the terms and conditions have not yet been accepted).
 */
- (BOOL)enableNavigationWithSession:(GMSNavigationSession *)navigationSession;

@end

/**
 * Support for smooth gestures when a map is displayed on the CarPlay screen.
 *
 * These methods should be called from the corresponding methods of CPMapTemplateDelegate in order
 * to implement gesture-based panning for a MapView showing on a CarPlay screen.
 */
@interface GMSMapView (CarPlay)

/**
 * This method should be called from the application's implementation of the CPMapTemplateDelegate
 * method -mapTemplateDidBeginPanGesture: in order to implement pan gestures for CarPlay map
 * templates.
 */
- (void)didBeginPanGesture;

/**
 * This method should be called from the application's implementation of the CPMapTemplateDelegate
 * method -mapTemplate:didUpdatePanGestureWithTranslation: in order to implement pan gestures for
 * CarPlay map templates.
 */
- (void)didUpdatePanGestureWithTranslation:(CGPoint)translation velocity:(CGPoint)velocity;

/**
 * This method should be called from the application's implementation of the CPMapTemplateDelegate
 * method -mapTemplate:didEndPanGestureWithVelocity: in order to implement pan gestures for CarPlay
 * map templates.
 */
- (void)didEndPanGestureWithVelocity:(CGPoint)velocity;

@end

NS_ASSUME_NONNULL_END
