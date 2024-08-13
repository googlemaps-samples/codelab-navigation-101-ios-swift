//
//  GMSNavigationDirectionsListController.h
//  Google Navigation SDK for iOS
//
//  Copyright 2018 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <UIKit/UIKit.h>

@class GMSNavigator;

NS_ASSUME_NONNULL_BEGIN

/**
 * A controller that manages and displays a directions list. The controller mantains its
 * own states internally based on the associated |navigator|. The |directionsListView| is updated
 * automatically based on |navigator| states.
 */
@interface GMSNavigationDirectionsListController : NSObject

/**
 * The view that displays the directions list. The view is lazy loaded when it is accessed for the
 * first time.
 */
@property(nonatomic, readonly) UIView *directionsListView;

/**
 * Initializes the controller with a |navigator|.
 *
 * @param navigator The controller automatically updates the list based on the current state of the
 *        |navigator| after |directionsListView| is accessed for the first time.
 */
- (instancetype)initWithNavigator:(GMSNavigator *)navigator NS_DESIGNATED_INITIALIZER;

/**
 * Updates the data source from the latest |navigator| state and reload the list. Calling this
 * method before |directionsListView| is accessed for the first time results in no-op.
 */
- (void)reloadData;

/**
 * Invalidates the layout of the |directionsListView|. This should be called during events
 * such as rotations and view size changes. Calling this method before |directionsListView| is
 * accessed for the first time results in no-op.
 */
- (void)invalidateLayout;

/** Use |initWithNavigator:| instead. */
- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
