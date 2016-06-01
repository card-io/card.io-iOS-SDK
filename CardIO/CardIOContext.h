//
//  CardIOContext.h
//  See the file "LICENSE.md" for the full license governing this code.
//

// This object is a container for information about a particular card.io instantiation. Most of this information
// is either set by the developer or initialized on first use.

#import <Foundation/Foundation.h>
#import "CardIODetectionMode.h"

@class CardIOAnalytics;
@class CardIOConfig;

@interface CardIOContext : NSObject

@property(nonatomic, strong, readwrite) CardIOConfig *config;

@property(nonatomic, assign, readwrite) BOOL collectCVV;
@property(nonatomic, assign, readwrite) BOOL collectExpiry;
@property(nonatomic, assign, readwrite) BOOL collectPostalCode;
@property(nonatomic, assign, readwrite) BOOL restrictPostalCodeToNumericOnly;
@property(nonatomic, assign, readwrite) BOOL collectCardholderName;
@property(nonatomic, assign, readwrite) BOOL disableManualEntryButtons;
@property(nonatomic, assign, readwrite) BOOL keepStatusBarStyle;
@property(nonatomic, assign, readwrite) UIBarStyle navigationBarStyle;
@property(nonatomic, retain, readwrite) UIColor *navigationBarTintColor;
@property(nonatomic, assign, readwrite) BOOL disableBlurWhenBackgrounding;
@property(nonatomic, assign, readwrite) BOOL suppressScanConfirmation;
@property(nonatomic, assign, readwrite) BOOL suppressScannedCardImage;
@property(nonatomic, assign, readwrite) BOOL maskManualEntryDigits;

#if CARDIO_DEBUG
@property(nonatomic, assign, readwrite) BOOL doABTesting;
#endif

// All of the following are passthroughs to self.config
@property(nonatomic, strong, readwrite) CardIOAnalytics *scanReport;
@property(nonatomic, copy, readwrite)   NSString *languageOrLocale;
@property(nonatomic, assign, readwrite) BOOL useCardIOLogo;
@property(nonatomic, retain, readwrite) UIColor *guideColor;
@property(nonatomic, assign, readwrite) CGFloat scannedImageDuration;
@property(nonatomic, assign, readwrite) BOOL allowFreelyRotatingCardGuide;

@property(nonatomic, copy, readwrite)   NSString *scanInstructions;
@property(nonatomic, assign, readwrite) BOOL hideCardIOLogo;
@property(nonatomic, retain, readwrite) UIView *scanOverlayView;

@property(nonatomic, assign, readwrite) CardIODetectionMode detectionMode;

@property(nonatomic, assign, readwrite) BOOL scanExpiry;

@end
