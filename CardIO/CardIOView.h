//
//  CardIOView.h
//  Version 3.10.1
//
//  Copyright (c) 2011-2014 PayPal. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CardIOViewDelegate.h"

/// CardIOView is one of two main entry points into the card.io SDK.
/// @see CardIOPaymentViewController
@interface CardIOView : UIView

/// Determine whether this device supports camera-based card scanning, considering
/// factors such as hardware support and OS version.
/// @return YES iff the user's device supports camera-based card scanning.
+ (BOOL)canReadCardWithCamera;

/// The preload method prepares card.io to launch faster. Calling preload is optional but suggested.
/// On an iPhone 5S, for example, preloading makes card.io launch ~400ms faster.
/// The best time to call preload is when displaying a view from which card.io might be launched;
/// e.g., inside your view controller's viewWillAppear: method.
/// preload works in the background; the call to preload returns immediately.
/// The preload method of CardIOPaymentViewController and of CardIOView do the same work,
/// so a call to either of them suffices.
+ (void)preload;


#pragma mark - Properties you MUST set

/// Typically, your view controller will set itself as this delegate.
@property(nonatomic, strong, readwrite) id<CardIOViewDelegate> delegate;


#pragma mark - Properties you MAY set

/// The preferred language for all strings appearing in the user interface.
/// If not set, or if set to nil, defaults to the device's current language setting.
///
/// Can be specified as a language code ("en", "fr", "zh-Hans", etc.) or as a locale ("en_AU", "fr_FR", "zh-Hant_HK", etc.).
/// If card.io does not contain localized strings for a specified locale, then it will fall back to the language. E.g., "es_CO" -> "es".
/// If card.io does not contain localized strings for a specified language, then it will fall back to American English.
///
/// If you specify only a language code, and that code matches the device's currently preferred language,
/// then card.io will attempt to use the device's current region as well.
/// E.g., specifying "en" on a device set to "English" and "United Kingdom" will result in "en_GB".
///
/// These localizations are currently included:
/// ar,da,de,en,en_AU,en_GB,en_SE,es,es_MX,fr,he,is,it,ja,ko,ms,nb,nl,pl,pt,pt_BR,ru,sv,th,tr,zh-Hans,zh-Hant,zh-Hant_TW.
@property(nonatomic, copy, readwrite) NSString *languageOrLocale;

/// Alter the card guide (bracket) color. Opaque colors recommended.
/// Defaults to nil; if nil, will use card.io green.
@property(nonatomic, retain, readwrite) UIColor *guideColor;

/// Set to YES to show the card.io logo over the camera instead of the PayPal logo. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL useCardIOLogo;

/// By default, in camera view the card guide and the buttons always rotate to match the device's orientation.
///   All four orientations are permitted, regardless of any app or viewcontroller constraints.
/// If you wish, the card guide and buttons can instead obey standard iOS constraints, including
///   the UISupportedInterfaceOrientations settings in your app's plist.
/// Set to NO to follow standard iOS constraints. Defaults to YES. (Does not affect the manual entry screen.)
@property(nonatomic, assign, readwrite) BOOL allowFreelyRotatingCardGuide;

/// After a successful scan, the CardIOView will briefly display an image of the card with
/// the computed card number superimposed. This property controls how long (in seconds)
/// that image will be displayed.
/// Set this to 0.0 to suppress the display entirely.
/// Defaults to 1.0.
@property(nonatomic, assign, readwrite) CGFloat scannedImageDuration;


#pragma mark - Property you MAY get

/// The actual camera preview area within the CardIOView. Location is relative to the CardIOView's origin.
/// You might want to use this, for example, when adjusting your view controller's view layout.
@property(nonatomic, assign, readonly) CGRect cameraPreviewFrame;


#pragma mark - Deprecated properties

/// Previous versions of card.io (prior to 3.10.0) required you to obtain an "application token" from the card.io website.
@property(nonatomic, copy, readwrite) NSString *appToken __attribute__((deprecated("The former appToken is no longer required.")));

@end
