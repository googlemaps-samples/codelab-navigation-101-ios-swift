//
//  GMSNavigationLicensePlateRestriction.h
//  Google Navigation SDK for iOS
//
//  Copyright 2018 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A class contains information for license plate restriction. It mantains the state of vehicle's
 * license plate information and restriction.
 */
@interface GMSNavigationLicensePlateRestriction : NSObject

/**
 * Initializes a license plate restriction object.
 * Set license plate restriction with current vehicle's last digit of license plate and country
 * code. This allows us to route around certain types of road restrictions which are based on
 * license plate number.
 *
 * Returns nil if license plate's last digit or country code is invalid.
 *
 * @param lastDigit the last digit of the current vehicle's license plate. This value must be
 *        between 0 and 9.
 * @param countryCode the country code of the current vehicle's license plate. Currently Indonesia
 *        (ID) and Brazil (BZ) are supported.
 */
- (nullable instancetype)initWithLicensePlateLastDigit:(NSInteger)lastDigit
                                           countryCode:(NSString *)countryCode;

/**
 * Returns the country code for license plate restriction set by a user.
 *
 * Defaults to empty string.
 */
@property(nonatomic, readonly) NSString *countryCode;

/**
 * Returns the last digit of vehicle's license plate number.
 *
 * Defaults to -1.
 */
@property(nonatomic, readonly) NSInteger lastDigit;

@end

NS_ASSUME_NONNULL_END
