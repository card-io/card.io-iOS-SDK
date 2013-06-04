//
//  CardIOPaymentViewController.h
//  Copyright (c) 2011-2013 PayPal. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CardIOPaymentViewControllerDelegate.h"

// CardIOPaymentViewController is the main entry point into the card.io SDK.
@interface CardIOPaymentViewController : UINavigationController

// Initializer for scanning only.
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate;

// Initializer for scanning only, with extra hooks for controlling whether the camera will be displayed (useful for testing).
// If scanningEnabled is NO, card.io will use manual entry, regardless of whether scanning is supported. (Default value is YES.)
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate scanningEnabled:(BOOL)scanningEnabled;

// Set your app token. If not set before presenting the view controller, an exception will be thrown.
@property(nonatomic, copy, readwrite) NSString *appToken;

// The preferred language for all strings appearing in the user interface.
// If not set, or if set to nil, defaults to the device's current language setting.
//
// Can be specified as a language code ("en", "fr", "zh-Hans", etc.) or as a locale ("en_AU", "fr_FR", "zh-Hant_HK", etc.).
// If card.io does not contain localized strings for a specified locale, then will fall back to the language. E.g., "es_CO" -> "es".
// If card.io does not contain localized strings for a specified region, then will fall back to American English.
//
// If you specify only a language code, and that code matches the device's currently preferred language,
// then card.io will attempt to use the device's current region as well.
// E.g., specifying "en" on a device set to "English" and "United Kingdom" will result in "en_GB".
//
// These localizations are currently included: da,de,en,en_AU,en_GB,en_SV,en_U5,es,fr,he,it,ja,nb,nl,pl,pt,ru,sv,tr,zh-Hans,zh-Hant_HK,zh-Hant_TW.
@property(nonatomic, copy, readwrite) NSString *languageOrLocale;

// If YES, the status bar's style will be kept as whatever your app has set it to.
// If NO, the status bar style will be set to UIStatusBarStyleBlackOpaque.
// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL keepStatusBarStyle;

// The default appearance of the navigation bar is UIBarStyleDefault, tintColor == nil.
// Set either or both of these properties if you want to override these defaults.
@property(nonatomic, assign, readwrite) UIBarStyle navigationBarStyle;
@property(nonatomic, retain, readwrite) UIColor *navigationBarTintColor;

// Normally, card.io blurs the screen when the app is backgrounded,
// to obscure card details in the iOS-saved screenshot.
// If your app already does its own blurring upon backgrounding, you might choose to disable this.
// Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL disableBlurWhenBackgrounding;

// Set to NO if you don't need to collect the card expiration. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectExpiry;

// Set to NO if you don't need to collect the CVV from the user. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectCVV;

// Set to YES if you need to collect the billing zip code. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL collectZip;

// Set to NO if you want to suppress the first-time how-to alert view. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL showsFirstUseAlert;

// Set to YES to show the card.io logo over the camera instead of the PayPal logo. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL useCardIOLogo;

// Set to YES to prevent card.io from showing manual entry buttons internally. Defaults to NO.
// If you want to prevent users from *ever* seeing card.io's manual entry screen, you should also:
//   * Check +canReadCardWithCamera before initing the view controller. If +canReadCardWithCamera
//     returns false, card.io will display a manual entry screen if presented.
//   * If needed for UI updates such as disabling/removing card scan buttons, subscribe to scan
//     notifications; see +(start|stop)GeneratingScanAvailabilityNotifications.
@property(nonatomic, assign, readwrite) BOOL disableManualEntryButtons;

// Access to the delegate.
@property(nonatomic, weak, readwrite) id<CardIOPaymentViewControllerDelegate> paymentDelegate;

// Indicates whether this device supports camera-based card scanning, including
// factors like hardware support and OS version. card.io automatically provides
// manual entry of cards as a fallback, so it is not necessary to check this.
+ (BOOL)canReadCardWithCamera;

// Please send the output of this method with any technical support requests.
+ (NSString *)libraryVersion;
@end