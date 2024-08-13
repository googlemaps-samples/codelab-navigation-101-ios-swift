//
//  GMSNavigationSession.h
//  Google Navigation SDK for iOS
//
//  Copyright 2022 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

#import "GMSNavigationTypes.h"

@class GMSLocationSimulator;
@class GMSNavigator;
@class GMSRoadSnappedLocationProvider;

NS_ASSUME_NONNULL_BEGIN

/**
 * This class provides a set of related objects that can be used to programmatically control
 * a navigation session.
 */
@interface GMSNavigationSession : NSObject

/**
 * Whether or not navigation on this session is started.
 *
 * A session cannot be started unless terms and conditions have previously
 * been accepted.
 *
 * Starting a session is a prerequisite for activating guidance on the
 * session's navigator, or for starting location updates from the session's
 * road-snapped location provider.
 *
 * A started session receives location from CoreLocation as determined
 * by the application's location authorization. Your app can temporarily stop the Navigation SDK
 * from requesting location updates. For instance, it might do this in order to reduce battery usage
 * in a period when location updates are known to be unnecessary.
 *
 */
@property(nonatomic, getter=isStarted) BOOL started;

/** The travel mode for this session. */
@property(nonatomic) GMSNavigationTravelMode travelMode;

/**
 * An instance of GMSLocationSimulator which can be used to simulate locations for this session,
 * or nil if terms and conditions have not been accepted.
 */
@property(nonatomic, nullable, readonly) GMSLocationSimulator *locationSimulator;

/**
 * The instance of GMSNavigator managing this navigation session, or nil if terms and conditions
 * have not been accepted.
 */
@property(nonatomic, nullable, readonly) GMSNavigator *navigator;

/**
 * The road-snapped location provider for this session, or nil if terms and conditions have not
 * been accepted.
 */
@property(nonatomic, nullable, readonly)
    GMSRoadSnappedLocationProvider *roadSnappedLocationProvider;

/** Instances of this class should be obtained by calling the method on GMSNavigationServices. */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
