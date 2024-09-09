//
//  GMSNavigationServices.h
//  Google Navigation SDK for iOS
//
//  Copyright 2016 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <Foundation/Foundation.h>
#if __has_feature(modules)
@import GoogleMapsBase;
#else
#import <GoogleMapsBase/GoogleMapsBase.h>
#endif

@class GMSNavigationTermsAndConditionsOptions;
@class GMSNavigationTermsDialogUIParams;
@class GMSNavigationSession;

NS_ASSUME_NONNULL_BEGIN

/**
 * Called when the user accepts or rejects the terms and conditions.
 *
 * For versions >= 5.5.0, @c termsAccepted will always be YES.
 *
 * @related GMSNavigationServices
 */
typedef void (^GMSTermsResponseCallback)(BOOL termsAccepted);

/** Services enabling control of mobile access to the Google Maps Navigation SDK for iOS. */
@interface GMSNavigationServices : NSObject

/**
 * For versions >= 5.5.0, indicates whether the terms and conditions
 * have been acknowledged by the user.
 *
 * For earlier versions, indicates whether the terms and conditions
 * have been accepted by the user.
 *
 * If false, the services disable access to navigation interfaces.
 */
+ (BOOL)areTermsAndConditionsAccepted;

/**
 * Shows a modal dialog box if the app user has not yet accepted the Navigation SDK terms and
 * conditions. The callback is sent on the main queue with the user's response.
 *
 * If the user has already accepted the terms and conditions, no dialog appears, and the callback
 * contains @c termsAccepted = @c YES.
 *
 * @param options The @c GMSNavigationTermsAndConditionsOptions object which modifies the appearance
 *    of the terms and conditions dialog. See @ GMSNavigationTermsAndConditionsOptions for more
 *    information.
 * @param callback Block sent on the main queue with the user's response.
 */
+ (void)showTermsAndConditionsDialogIfNeededWithOptions:
            (GMSNavigationTermsAndConditionsOptions *)options
                                               callback:(GMSTermsResponseCallback)callback;

/**
 * Deprecated. Use @c GMSNavigationTermsAndConditionsOptions API with @c
 * showTermsAndConditionsDialogIfNeededWithOptions:callback: instead.
 *
 * Indicates if |showTermsAndConditionsDialogIfNeededWithCompanyName:callback:| should
 * display the driver awareness disclaimer only. The default is @c NO and the disclaimer is
 * shown in addition to the default terms and services provided with the Navigation SDK.
 * Set to @c YES to indicate that only the driver awareness disclaimer should be shown.
 *
 * If the project must show the Terms and Conditions dialog, setting this variable to @c YES has no
 * effect. Additionally, the getter method always returns @c NO .
 *
 * This property must be set or read from the main thread.
 */
@property(class, nonatomic) BOOL shouldOnlyShowDriverAwarenesssDisclaimer
    __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
        "Use the GMSNavigationTermsAndConditionsOptions API instead.")
        ;

/**
 * Deprecated. Use @c showTermsAndConditionsDialogIfNeededWithOptions:callback: instead.
 *
 * Shows a modal dialog box if the app user has not yet accepted the Navigation SDK terms and
 * conditions. The callback is sent on the main queue with the user's response.
 *
 * If the user has already accepted the terms and conditions, no dialog appears, and the callback
 * contains @c termsAccepted = @c YES.
 *
 * Set @c companyName parameter to your company. The company name appears in the terms and
 * conditions text. The text explains to app users that location data may be shared with this
 * company to improve operations.
 *
 * Call this method from the main thread. Multiple calls without waiting for a response have no
 * effect.
 *
 * @param title Title of the dialog box. If @c title is nil, the dialog uses the default title.
 *     Note: For custom titles, the caller of this method needs to localize this parameter. The
 *     default title is localized by the services automatically.
 * @param companyName Name of the company releasing the app and in the agreement with Google to
 *     share location data.
 * @param UIParams Parameters defining the look and feel of the dialog box. If nil, the dialog box
 *     uses the default look and feel.
 * @param callback Block sent on the main queue with the user's response.
 */
+ (void)showTermsAndConditionsDialogIfNeededWithTitle:(nullable NSString *)title
                                          companyName:(NSString *)companyName
                                             UIParams:(nullable GMSNavigationTermsDialogUIParams *)
                                                          UIParams
                                             callback:(GMSTermsResponseCallback)callback
    __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
        "Use showTermsAndConditionsDialogWithOptions:callback: instead.")
        ;

/**
 * Deprecated. Use @c showTermsAndConditionsDialogIfNeededWithOptions:callback: instead.
 *
 * Shows the terms and conditions dialog using the default look and feel.
 *
 * See +showTermsAndConditionsDialogIfNeededWithTitle:companyName:UIParams:callback: for details,
 * including a description of the parameters @title, @c companyName and @c callback.
 */
+ (void)showTermsAndConditionsDialogIfNeededWithTitle:(nullable NSString *)title
                                          companyName:(NSString *)companyName
                                             callback:(GMSTermsResponseCallback)callback
    __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
        "Use showTermsAndConditionsDialogWithOptions:callback: instead.")
        ;

/**
 * Deprecated. Use @c showTermsAndConditionsDialogIfNeededWithOptions:callback: instead.
 *
 * Shows the terms and conditions dialog using the default title and look and feel.
 *
 * See +showTermsAndConditionsDialogIfNeededWithTitle:companyName:UIParams:callback: for details,
 * including a description of the parameters @c companyName and @c callback.
 */
+ (void)showTermsAndConditionsDialogIfNeededWithCompanyName:(NSString *)companyName
                                                   callback:(GMSTermsResponseCallback)callback
    __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
        "Use showTermsAndConditionsDialogWithOptions:callback: instead.")
        ;

/**
 * Resets the terms and conditions to the unaccepted state. After calling this method,
 * |areTermsAndConditionsAccepted| will return NO, and
 #if SDK_BUILD_CONFIG(EnableNavSDKSkipToSOptions)
 * @c showTermsAndConditionsDialogIfNeededWithOptions:callback: and
 #endif
 * |showTermsAndConditionsDialogIfNeededWithCompanyName:callback:| will show the terms and
 * conditions dialog. The |navigationEnabled| property of any existing GMSMapView instances will be
 * reset to NO.
 */
+ (void)resetTermsAndConditionsAccepted;

/**
 * Enables reporting of abnormal SDK terminations such as the app crashes while the SDK is still
 * running. This allows Google to improve SDK stability when applicable. The default is @c YES and
 * value must be updated before the services instance is initialized.
 *
 * This property must be set from the main thread.
 */
+ (void)setAbnormalTerminationReportingEnabled:(BOOL)abnormalTerminationReportingEnabled;

/**
 * Creates a new navigation session which is not associated with a map view.
 *
 * This allocates and returns a new navigation session. Waypoints and options may be set on
 * the session, and listeners may be added to it.
 *
 * If the terms and conditions have not yet been accepted, this method will return nil.
 * That is the only reason nil will be returned from this method.
 *
 * You can associate this session with a map after creating it by using the @c GMSMapView method
 * @c -enableNavigationWithSession:. Sessions are heavyweight objects that consume memory, data,
 * and battery, so they should be allocated only if a persistent navigation session is a major
 * feature of the application. For the same reason, if your app creates a navigation UI after it
 * establishes a navigation session, make sure to start the navigation UI with the existing
 * navigation session rather than creating a new one.
 *
 * The lifetime of the navigation session is governed by normal Objective-C semantics.
 * Therefore, the caller of this routine should save a reference to the session.
 */
+ (nullable GMSNavigationSession *)createNavigationSession;

/**
 * Returns the open source software license information for Google Navigation SDK for iOS. This
 * information must be available within your application.
 */
+ (NSString *)openSourceLicenseInfo;

/** Returns the version for this release of the Navigation SDK for iOS. */
+ (NSString *)navSDKVersion;

@end

NS_ASSUME_NONNULL_END
