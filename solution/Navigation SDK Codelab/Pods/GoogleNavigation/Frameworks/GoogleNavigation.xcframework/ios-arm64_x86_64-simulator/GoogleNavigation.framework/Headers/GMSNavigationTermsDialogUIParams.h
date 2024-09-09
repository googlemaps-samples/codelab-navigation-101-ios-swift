//
//  GMSNavigationTermsDialogUIParams.h
//  Google Navigation SDK for iOS
//
//  Copyright 2019 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <UIKit/UIKit.h>

#if __has_feature(modules)
@import GoogleMapsBase;
#else
#import <GoogleMapsBase/GoogleMapsBase.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/** Parameters that describe the look and feel of the dialog. */
@interface GMSNavigationTermsDialogUIParams : NSObject

/** Color used for the background of the dialog box. */
@property(nonatomic, nullable, readonly) UIColor *backgroundColor;

/** Font used for text of the title. */
@property(nonatomic, nullable, readonly) UIFont *titleFont;

/** Color of text in the title. */
@property(nonatomic, nullable, readonly) UIColor *titleColor;

/** Font used for text of the Terms and Driver's Awareness Disclaimer. */
@property(nonatomic, nullable, readonly) UIFont *mainTextFont;

/** Color of the text used for the Terms and Driver's Awareness Disclaimer. */
@property(nonatomic, nullable, readonly) UIColor *mainTextColor;

/** Font used for text on the Cancel and Accept buttons. */
@property(nonatomic, nullable, readonly) UIFont *buttonsFont;

/**
 * Deprecated. Cancel button has been removed from the dialog.
 *
 * Color of the text of the Cancel button. The background color of the button is transparent.
 */
@property(nonatomic, nullable, readonly)
    UIColor *cancelButtonTextColor __GMS_AVAILABLE_BUT_DEPRECATED_MSG(
        "Cancel button has been removed from the dialog.");

/** Color of the text of the Accept button. The background color of the button is transparent. */
@property(nonatomic, nullable, readonly) UIColor *acceptButtonTextColor;

/**
 * Constructs a @c GMSNavigationTermsDialogUIParams object.
 *
 * See property comments for the meaning of the parameters.
 */
- (instancetype)initWithBackgroundColor:(nullable UIColor *)backgroundColor
                              titleFont:(nullable UIFont *)titleFont
                             titleColor:(nullable UIColor *)titleColor
                           mainTextFont:(nullable UIFont *)mainTextFont
                          mainTextColor:(nullable UIColor *)mainTextColor
                            buttonsFont:(nullable UIFont *)buttonsFont
                  cancelButtonTextColor:(nullable UIColor *)cancelButtonTextColor
                  acceptButtonTextColor:(nullable UIColor *)acceptButtonTextColor
    NS_DESIGNATED_INITIALIZER;

/** Use designated initializer instead. */
- (null_unspecified instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
