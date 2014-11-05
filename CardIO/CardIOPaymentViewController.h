//
//  CardIOPaymentViewController.h
//  Version 3.10.1
//
//  Copyright (c) 2011-2014 PayPal. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CardIOPaymentViewControllerDelegate.h"

/// CardIOPaymentViewController is one of two main entry points into the card.io SDK.
/// @see CardIOView
@interface CardIOPaymentViewController : UINavigationController

/// Initializer for scanning.
/// If scanning is not supported by the user's device, card.io will offer manual entry.
/// @param aDelegate Your CardIOPaymentViewControllerDelegate (typically a UIViewController).
/// @return Properly initialized CardIOPaymentViewController.
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate;

/// Initializer for scanning, with extra hooks for controlling whether the camera will
/// be displayed (useful for testing).
/// @param aDelegate Your CardIOPaymentViewControllerDelegate (typically a UIViewController).
/// @param scanningEnabled If scanningEnabled is NO, card.io will offer manual entry,
///        regardless of whether scanning is supported by the user's device.
/// @return Properly initialized CardIOPaymentViewController.
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate scanningEnabled:(BOOL)scanningEnabled;

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

/// If YES, the status bar's style will be kept as whatever your app has set it to.
/// If NO, the status bar style will be set to the default style.
/// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL keepStatusBarStyle;

/// The default appearance of the navigation bar is navigationBarStyle == UIBarStyleDefault;
/// tintColor == nil (pre-iOS 7), barTintColor == nil (iOS 7).
/// Set either or both of these properties if you want to override these defaults.
/// @see navigationBarTintColor
@property(nonatomic, assign, readwrite) UIBarStyle navigationBarStyle;
/// The default appearance of the navigation bar is navigationBarStyle == UIBarStyleDefault;
/// tintColor == nil (pre-iOS 7), barTintColor == nil (iOS 7).
/// Set either or both of these properties if you want to override these defaults.
/// @see navigationBarStyle
@property(nonatomic, retain, readwrite) UIColor *navigationBarTintColor;

/// Normally, card.io blurs the screen when the app is backgrounded,
/// to obscure card details in the iOS-saved screenshot.
/// If your app already does its own blurring upon backgrounding,
/// you might choose to disable this behavior.
/// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL disableBlurWhenBackgrounding;

/// Alter the card guide (bracket) color. Opaque colors recommended.
/// Defaults to nil; if nil, will use card.io green.
@property(nonatomic, retain, readwrite) UIColor *guideColor;

/// If YES, don't have the user confirm the scanned card, just return the results immediately.
/// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL suppressScanConfirmation;

/// If YES, instead of displaying the image of the scanned card,
/// present the manual entry screen with the scanned card number prefilled.
/// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL suppressScannedCardImage;

/// Mask the card number digits as they are manually entered by the user. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL maskManualEntryDigits;

/// Set to NO if you don't need to collect the card expiration. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectExpiry;

/// Set to NO if you don't need to collect the CVV from the user. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectCVV;

/// Set to YES if you need to collect the billing postal code. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL collectPostalCode;
/// Deprecated.
/// @see collectPostalCode
@property(nonatomic, assign, readwrite, getter=collectPostalCode, setter=setCollectPostalCode:) BOOL collectZip __attribute__((deprecated("Use collectPostalCode instead.")));

/// Set to YES to show the card.io logo over the camera view instead of the PayPal logo. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL useCardIOLogo;

/// By default, in camera view the card guide and the buttons always rotate to match the device's orientation.
///   All four orientations are permitted, regardless of any app or viewcontroller constraints.
/// If you wish, the card guide and buttons can instead obey standard iOS constraints, including
///   the UISupportedInterfaceOrientations settings in your app's plist.
/// Set to NO to follow standard iOS constraints. Defaults to YES. (Does not affect the manual entry screen.)
@property(nonatomic, assign, readwrite) BOOL allowFreelyRotatingCardGuide;

/// Set to YES to prevent card.io from showing its "Enter Manually" button. Defaults to NO.
///
/// @note If +canReadCardWithCamera returns false, then if card.io is presented it will
///       automatically display its manual entry screen.
///       Therefore, if you want to prevent users from *ever* seeing card.io's manual entry screen,
///       you should first check +canReadCardWithCamera before initing the view controller.
@property(nonatomic, assign, readwrite) BOOL disableManualEntryButtons;

/// Access to the delegate.
@property(nonatomic, weak, readwrite) id<CardIOPaymentViewControllerDelegate> paymentDelegate;

/// The preload method prepares card.io to launch faster. Calling preload is optional but suggested.
/// On an iPhone 5S, for example, preloading makes card.io launch ~400ms faster.
/// The best time to call preload is when displaying a view from which card.io might be launched;
/// e.g., inside your view controller's viewWillAppear: method.
/// preload works in the background; the call to preload returns immediately.
/// The preload method of CardIOPaymentViewController and of CardIOView do the same work,
/// so a call to either of them suffices.
+ (void)preload;

/// Determine whether this device supports camera-based card scanning, considering
/// factors such as hardware support and OS version.
///
/// card.io automatically provides manual entry of cards as a fallback,
/// so it is not typically necessary for your app to check this.
///
/// @return YES iff the user's device supports camera-based card scanning.
+ (BOOL)canReadCardWithCamera;

/// Please send the output of this method with any technical support requests.
/// @return Human-readable version of this library.
+ (NSString *)libraryVersion;


#pragma mark - Deprecated properties

/// Previous versions of card.io (prior to 3.2.3) provided an informative message when the user first launched card.io.
@property(nonatomic, assign, readwrite) BOOL showsFirstUseAlert __attribute__((deprecated("The former first-time alert is no more.")));

/// Previous versions of card.io (prior to 3.10.0) required you to obtain an "application token" from the card.io website.
@property(nonatomic, copy, readwrite) NSString *appToken __attribute__((deprecated("The former appToken is no longer required.")));

@end