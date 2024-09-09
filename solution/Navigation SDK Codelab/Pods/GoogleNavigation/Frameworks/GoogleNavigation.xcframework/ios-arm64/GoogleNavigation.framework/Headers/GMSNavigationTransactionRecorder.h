//
//  GMSNavigationTransactionRecorder.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

@class GMSNavigationWaypoint;

NS_ASSUME_NONNULL_BEGIN

typedef void (^GMSNavigationTransactionRecorderErrorHandler)(NSError *error);

/**
 * Contains methods for recording transactions. This class should only be used if you are a Mobility
 * Services customer and are billed by Google on a per-transaction basis.
 */
@interface GMSNavigationTransactionRecorder : NSObject

/**
 * Returns a shared singleton GMSNavigationTransactionRecorder instance. This singleton is held
 * weakly and may be deallocated if an application does not keep a strong reference. You must call
 * this function only on the main thread.
 *
 * This method will throw an exception if GMSServices +provideAPIKey: has not been called.
 */
+ (GMSNavigationTransactionRecorder *)sharedInstance;

/**
 * You should call this function each time a passenger or a delivery is picked up. You should
 * populate the transactionIDs parameter with a unique ID for each transaction that applies to this
 * event. You must call this function only on the main thread.
 *
 * <p>This method should be called if and only if your company is billed by Google on a
 * per-transaction basis.
 *
 * @param waypoint The GMSNavigationWaypoint at which the pickup is occurring, or nil if there was
 *     no guidance session leading to this pickup.
 * @param transactionIDs One or more transaction IDs to which this pickup applies. The transaction
 *     ID must be unique for each billable transaction. Transaction IDs must contain at least one
 *     and at most 64 characters.
 * @param errorHandler A block that will be invoked asynchronously on the main thread if an error
 *     occurs while recording the pickup.
 */
- (void)recordPickupAtWaypoint:(nullable GMSNavigationWaypoint *)waypoint
             forTransactionIDs:(NSArray<NSString *> *)transactionIDs
              withErrorHandler:(nullable GMSNavigationTransactionRecorderErrorHandler)errorHandler;

/**
 * You should call this function each time a passenger is dropped-off or a delivery is delivered.
 * You should populate the transactionIDs parameter with a unique ID for each transaction that
 * applies to this event. You must call this function only on the main thread.
 *
 * <p>This method should be called if and only if your company is billed by Google on a
 * per-transaction basis.
 *
 * @param waypoint The GMSNavigationWaypoint at which the dropoff is occurring, or nil if there was
 *     no guidance session leading to this dropoff.
 * @param transactionIDs One or more transaction IDs to which this dropoff applies. The transaction
 *     ID must be unique for each billable transaction. Transaction IDs must contain at least one
 *     and at most 64 characters.
 * @param errorHandler A block that will be invoked asynchronously on the main thread if an error
 *     occurs while recording the dropoff.
 */
- (void)recordDropoffAtWaypoint:(nullable GMSNavigationWaypoint *)waypoint
              forTransactionIDs:(NSArray<NSString *> *)transactionIDs
               withErrorHandler:(nullable GMSNavigationTransactionRecorderErrorHandler)errorHandler;

/** Generate a new unique transaction ID. */
+ (NSString *)generateTransactionID;

/** Init is unavailable. Use +sharedInstance to acquire an instance. */
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
