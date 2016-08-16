//
//  CardIOConfig.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOAnalytics.h"
#import "CardIODetectionMode.h"

@interface CardIOConfig : NSObject
@property(nonatomic, strong, readwrite) CardIOAnalytics *scanReport;

@property(nonatomic, copy, readwrite)   NSString *languageOrLocale;
@property(nonatomic, assign, readwrite) BOOL useCardIOLogo;
@property(nonatomic, retain, readwrite) UIColor *guideColor;
@property(nonatomic, assign, readwrite) CGFloat scannedImageDuration;
@property(nonatomic, assign, readwrite) BOOL allowFreelyRotatingCardGuide;
@property(nonatomic, assign, readwrite) BOOL scanExpiry;
@property(nonatomic, copy, readwrite)   NSString *scanInstructions;
@property(nonatomic, assign, readwrite) BOOL hideCardIOLogo;
@property(nonatomic, retain, readwrite) UIView *scanOverlayView;

@property(nonatomic, assign, readwrite) CardIODetectionMode detectionMode;
@end
