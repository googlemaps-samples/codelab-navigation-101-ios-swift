//
//  GMSNavigationInstructionOptions.h
//  Google Navigation SDK for iOS
//
//  Copyright 2023 Google LLC
//
//  Usage of this SDK is subject to the Google Maps/Google Earth APIs Terms of
//  Service: https://cloud.google.com/maps-platform/terms
//

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>


@class GMSNavigationStepInfoImageOptions;

NS_ASSUME_NONNULL_BEGIN

/** Options for formatting attributed instruction strings. */
@interface GMSNavigationInstructionOptions : NSObject

/**
 * Image options to be used when generating inline images. Setting this to nil specifies using
 * a default set of image options.
 */
@property(nonatomic, copy, null_resettable) GMSNavigationStepInfoImageOptions *imageOptions;

/**
 * By default, instructions will sometimes use a special format for long-distance instructions,
 * such as staying on the same highway for a long time. Setting this to YES will disable the use of
 * such instructions. This can be an overall better experience on space-constrained displays such as
 * CarPlay.
 *
 * Defaults to NO.
 */
@property(nonatomic) BOOL disableLongDistanceFormat;

/**
 * The primary font to use when formatting the instructions.
 *
 * Setting this to nil implies use of the default font from the Google navigation experience.
 */
@property(nonatomic, copy, null_resettable) UIFont *primaryFont;

/**
 * The secondary font to use when formatting the instructions.
 *
 * Setting this to nil implies use of the default font from the Google navigation experience.
 */
@property(nonatomic, copy, null_resettable) UIFont *secondaryFont;

/**
 * The font for small elements like exit numbers or conjunctions.
 *
 * Setting this to nil implies use of the default font from the Google navigation experience.
 */
@property(nonatomic, copy, null_resettable) UIFont *tertiaryFont;

/**
 * The color to use for instruction text.
 *
 * Setting this to nil implies white.
 */
@property(nonatomic, copy, null_resettable) UIColor *textColor;

/**
 * The primary road shield height to assign when formatting the instructions.
 *
 * Road shields are the logos for particular highways or other roads. They may be used inline in
 * the attributed instructions in order to more compactly reference a road. This value controls the
 * height assigned to such road shields.
 */
@property(nonatomic) CGFloat primaryRoadShieldHeight;

/**
 * The secondary road shield height to assign when formatting the instructions.
 *
 * See @c primaryRoadShieldHeight for a description of road shields.
 */
@property(nonatomic) CGFloat secondaryRoadShieldHeight;

/**
 * The width of the outline drawn around road shields.
 *
 * By default, the width is 0, which will cause no outline to be drawn.
 *
 * See @c primaryRoadShieldHeight for a description of road shields.
 */
@property(nonatomic) CGFloat roadShieldOutlineWidth;

/**
 * The color of the outline drawn around road shields.
 *
 * By default, the color is nil, which will cause no outline to be drawn.
 *
 * See @c primaryRoadShieldHeight for a description of road shields.
 */
@property(nonatomic, nullable) UIColor *roadShieldOutlineColor;

/**
 * The exit cue height to use when formatting the instructions.
 *
 * When exiting a highway or other limited access road, instructions may reference specific exit
 * numbers in some situations. When this is done, a graphic highlighting the exit number may be
 * created. This property allows controlling the height of that graphic.
 */
@property(nonatomic) CGFloat exitNumberHeight;

/**
 * The exit cue background color to assign when formatting the instructions.
 *
 * When exiting a highway or other limited access road, instructions may reference specific exit
 * numbers in some situations. When this is done, a background color may be assigned to the graphic
 * highlighting the exit number. This property allows controlling that color.
 *
 * Setting this to nil implies use of the default color from the Google navigation experience.
 */
@property(nonatomic, copy, null_resettable) UIColor *exitCueBackgroundColor;

@end

NS_ASSUME_NONNULL_END

