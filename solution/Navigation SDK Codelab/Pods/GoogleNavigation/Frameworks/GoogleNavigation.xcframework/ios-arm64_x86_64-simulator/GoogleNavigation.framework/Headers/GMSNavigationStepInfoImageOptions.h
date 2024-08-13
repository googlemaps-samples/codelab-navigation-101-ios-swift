//
//  GMSNavigationStepInfoImageOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2023 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//
#import <Foundation/Foundation.h>

#import "GMSNavigationScreenMetrics.h"


/** The image size which GMSNavigationStepInfo images will be generated. */
typedef NS_ENUM(NSInteger, GMSNavigationManeuverImageSize) {
  /**
   * 48pt x 48pt maneuver image size. Recommended use for cases such as next step maneuvers and
   * maneuver lists where the image is not the primary focus.
   */
  GMSNavigationManeuverImageSizeSquare48,

  /**
   * 96pt x 96pt maneuver image size. Recommended use for banners or headers where the maneuver
   * image should be visually prominent.
   */
  GMSNavigationManeuverImageSizeSquare96,
};

NS_ASSUME_NONNULL_BEGIN

@interface GMSNavigationStepInfoImageOptions : NSObject
/**
 * The object which provides screen metrics for the screen the image will be displayed on. In most
 * cases, developers can pass the instance of UIScreen for the screen where the image will be
 * displayed. This property defaults to UIScreen.mainScreen.
 */
@property(nonatomic, nullable) id<GMSNavigationScreenMetrics> screenMetrics;

/**
 * The image size for maneuverImage in GMSNavigationStepInfo.
 * Defaults to GMSNavigationManeuverImageSizeSquare96.
 */
@property(nonatomic) GMSNavigationManeuverImageSize maneuverImageSize;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

