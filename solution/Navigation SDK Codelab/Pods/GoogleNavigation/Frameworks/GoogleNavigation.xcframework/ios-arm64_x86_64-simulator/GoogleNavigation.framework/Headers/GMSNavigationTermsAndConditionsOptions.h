//
//  GMSNavigationTermsAndConditionsOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2024 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>


@class GMSNavigationTermsDialogUIParams;

NS_ASSUME_NONNULL_BEGIN

/**
 * Options for displaying terms and conditions.
 */
@interface GMSNavigationTermsAndConditionsOptions : NSObject <NSCopying>

- (instancetype)initWithCompanyName:(NSString *)companyName NS_DESIGNATED_INITIALIZER;

/** Default init is not available. Please use the designated initializer. */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Name of the company releasing the app and in the agreement with Google to
 * share location data.
 */
@property(nonatomic, copy) NSString *companyName;

/**
 * Title of the dialog box. If @c title is nil, the dialog uses the default title.
 * Note: For custom titles, the caller of this method needs to localize this parameter
 * The default title is localized by the services automatically.
 */
@property(nonatomic, copy, nullable) NSString *title;

/**
 * Indicates if @c -showTermsAndConditionsDialogIfNeededWithOptions:callback: should
 * display the driver awareness disclaimer only. The default is @c NO and the disclaimer is
 * shown in addition to the default terms and services provided with the Navigation SDK.
 * Set to @c YES to indicate that only the driver awareness disclaimer should be shown.
 *
 * If the project must show the Terms and Conditions dialog, setting this variable to @c YES has no
 * effect.
 */
@property(nonatomic, assign) BOOL shouldOnlyShowDriverAwarenessDialog;

/**
 * Parameters defining the look and feel of the dialog box. If nil, the dialog box
 * uses the default look and feel.
 */
@property(nonatomic, strong, nullable) GMSNavigationTermsDialogUIParams *uiParams;

@end

NS_ASSUME_NONNULL_END

