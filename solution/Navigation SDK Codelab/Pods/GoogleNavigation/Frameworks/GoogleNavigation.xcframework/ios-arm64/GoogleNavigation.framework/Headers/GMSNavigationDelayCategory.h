//
//  GMSNavigationDelayCategory.h
//  Google Navigation SDK for iOS
//
//  Copyright 2018 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

/**
 * A GMSNavigationDelayCategory is a category that represents the delay category of a route or a
 * a path.
 */
typedef NS_ENUM(NSInteger, GMSNavigationDelayCategory) {
  /** No traffic data is provided. */
  GMSNavigationDelayCategoryNoData = 0,
  GMSNavigationDelayCategoryHeavy = 1,
  GMSNavigationDelayCategoryMedium = 2,
  GMSNavigationDelayCategoryLight = 3,
};
