//
//  GMSMapView+AccessoryViewManagement.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#if __has_feature(modules)
@import GoogleMaps;
#else
#import <GoogleMaps/GoogleMaps.h>
#endif

@protocol GMSNavigationAccessoryView;

NS_ASSUME_NONNULL_BEGIN

@interface GMSMapView (AccessoryViewManagement)

/**
 * Invalidates an accessory view and triggers a re-layout for that view. The view must be one of the
 * current accessory views. If guidance is inactive, this call is a NO-OP instruction.
 */
- (void)invalidateLayoutForAccessoryView:(UIView<GMSNavigationAccessoryView> *)accessoryView;

/**
 * Sets the position of the accessory view below the primary header of the navigation UI. Passing a
 * nil value removes the accessory view. If guidance is inactive, this call is a NO-OP instruction.
 *
 * @note: If the map view is short, the SDK hides the accessory view due to limited space. The views
 * are internally managed to optimize display of the map.
 */
- (void)setHeaderAccessoryView:(nullable UIView<GMSNavigationAccessoryView> *)headerAccessoryView;

@end

NS_ASSUME_NONNULL_END
