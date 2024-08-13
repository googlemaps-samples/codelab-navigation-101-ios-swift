//
//  GMSNavigationAccessoryView.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <UIKit/UIKit.h>

@class GMSMapView;

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol defining methods that support custom views specifying accessory UI elements applied to
 * the primary view. Accessory views must implement this protocol in order to be visible.
 */
@protocol GMSNavigationAccessoryView <NSObject>

/** @return Desired height of the accessory view constrained to the given @c size. */
- (CGFloat)heightForAccessoryViewConstrainedToSize:(CGSize)size onMapView:(GMSMapView *)mapView;

@end

NS_ASSUME_NONNULL_END
