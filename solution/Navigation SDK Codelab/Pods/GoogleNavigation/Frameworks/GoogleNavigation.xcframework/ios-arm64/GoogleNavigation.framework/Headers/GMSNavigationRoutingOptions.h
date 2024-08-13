//
//  GMSNavigationRoutingOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

#import "GMSNavigationTypes.h"

NS_ASSUME_NONNULL_BEGIN

/** An immutable class that contains options related to routing logic (e.g., routing strategy). */
@interface GMSNavigationRoutingOptions : NSObject <NSCopying, NSMutableCopying>

/** Specifies the ranking order of routes, either by time, or by distance. */
@property(nonatomic, readonly) GMSNavigationRoutingStrategy routingStrategy;

/** The alternate routes strategy used when setting destinations. */
@property(nonatomic, readonly) GMSNavigationAlternateRoutesStrategy alternateRoutesStrategy;

/**
 * An array of target distances. An target distance is used to rank routes to a destination by the
 * absolute delta to it from smallest to largest. The elements should be non-negative integers.
 * Don't set GMSNavigationAlternateRoutesStrategy and this field at the same time.
 * Target distance is only supported for the first destination for now. So only put one
 * positive integer in the array. If the first element is not a positive integer, the
 * routing strategy defaults to the best routing strategy.
 */
@property(nonatomic, nullable, readonly) NSArray<NSNumber *> *targetDistancesMeters;

/**
 * Initializes the routing options with routing strategy.
 *
 * @param routingStrategy Routing strategy that specifies the order of returned routes.
 */
- (instancetype)initWithRoutingStrategy:(GMSNavigationRoutingStrategy)routingStrategy;

/**
 * Initializes the routing options with an alternate routes strategy.
 *
 * @param alternateRoutesStrategy Alternate routes strategy that determines the number of returned
 * alternate routes.
 */
- (instancetype)initWithAlternateRoutesStrategy:
    (GMSNavigationAlternateRoutesStrategy)alternateRoutesStrategy;

/**
 * Initializes the routing options with target distances, and sets the routing strategy to
 * GMSNavigationRoutingStrategyDeltaToTargetDistance. Ensure that target distances are always
 * up-to-date when used.
 *
 * @param targetDistancesMeters Target distances for destinations. Each target distance is
 *        used to rank the routes to its corresponding destination by its absolute delta to
 *        the routes.
 */
- (instancetype)initWithTargetDistancesMeters:(NSArray<NSNumber *> *)targetDistancesMeters;

@end

/** A mutable class that contains options related to routing logic (e.g., routing strategy). */
@interface GMSNavigationMutableRoutingOptions : GMSNavigationRoutingOptions

/** Specifies the ranking order of routes, either by time, or by distance. */
@property(nonatomic) GMSNavigationRoutingStrategy routingStrategy;

/** The alternate routes strategy used when setting destinations. */
@property(nonatomic) GMSNavigationAlternateRoutesStrategy alternateRoutesStrategy;

/**
 * Target distances used to ranking the routes. The elements should be non-negative
 * integers.
 * Don't set GMSNavigationAlternateRoutesStrategy and this field at the same time.
 * Target distance is only supported for the first destination for now. So only put one
 * positive integer in the array. If the first element is not a positive integer, the
 * routing strategy defaults to the best routing strategy.
 */
@property(nonatomic, copy, nullable) NSArray<NSNumber *> *targetDistancesMeters;

@end

NS_ASSUME_NONNULL_END
