//
//  CardIOCardScanner.h
//  See the file "LICENSE.md" for the full license governing this code.
//

// A thin, objective-c wrapper about dmz's ScannerState object, for convenience.

#if USE_CAMERA || SIMULATE_CAMERA

#import "scan.h"

@class CardIOIplImage;
@class CardIOReadCardInfo;

@interface CardIOCardScanner : NSObject

- (void)reset;
- (void)addFrame:(CardIOIplImage *)y
      focusScore:(float)focusScore
 brightnessScore:(float)brightnessScore
        isoSpeed:(NSInteger)isoSpeed
    shutterSpeed:(float)shutterSpeed
       torchIsOn:(BOOL)torchIsOn
     markFlipped:(BOOL)flipped
      scanExpiry:(BOOL)scanExpiry;
- (BOOL)complete;

// these properties are intentionally (superstitiously, anyhow) atomic -- card scanners get passed around between threads

// will return garbage unless -complete returns YES
// the xOffsets and yOffset populated in cardInfo will be
// from the most recent frame added via addFrame!
@property(strong, readonly) CardIOReadCardInfo *cardInfo;

@property(assign, readonly) ScanSessionAnalytics *scanSessionAnalytics;
@property(assign, readonly) BOOL lastFrameWasUpsideDown;

#if SIMULATE_CAMERA
@property(assign, readwrite) BOOL considerItScanned;
#endif

@end

#endif
