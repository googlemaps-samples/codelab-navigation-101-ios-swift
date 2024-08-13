//
//  GMSNavigationScreenMetrics.h
//  Google Navigation SDK for iOS
//
//  Copyright 2023 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * Protocol for returning information about screen metrics.
 *
 * This protocol is a subset of the screen-metric-related properties implemented by UIScreen.
 */
@protocol GMSNavigationScreenMetrics

/** The bounding rectangle of the screen, measured in points. */
@property(nonatomic, assign) CGRect bounds;

/** The bounding rectangle of the physical screen, measured in pixels.*/
@property(nonatomic, assign) CGRect nativeBounds;

/** The native scale factor for the physical screen. */
@property(nonatomic, assign) CGFloat nativeScale;

/** The natural scale factor associated with the screen. */
@property(nonatomic, assign) CGFloat scale;

@end

/**
 * UIScreen category already implements all the methods in the GMSNavigationScreenMetrics protocol.
 */
@interface UIScreen (GMSNavigationStepImageOptions) <GMSNavigationScreenMetrics>
@end
