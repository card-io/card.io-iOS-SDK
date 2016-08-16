//
//  CardIOVideoFrame.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "dmz.h"
#import "CardIODetectionMode.h"

// Processor and container for a single frame captured from the camera.

typedef enum {
  FrameEncodingColorPNG = 1,
  FrameEncodingGrayPNG = 2
} FrameEncoding;

@class CardIOIplImage;
@class CardIOCardScanner;
@class CardIOReadCardInfo;

@interface CardIOVideoFrame : NSObject

- (id)initWithSampleBuffer:(CMSampleBufferRef)sampleBuffer interfaceOrientation:(UIInterfaceOrientation)currentOrientation;

- (void)process;
- (BOOL)foundAllEdges;
- (uint)numEdgesFound;
- (NSData *)encodedImageUsingEncoding:(FrameEncoding)encoding;
- (UIImage *)imageWithGrayscale:(BOOL)grayscale;
+ (NSString *)filenameForImageEncodedUsingEncoding:(FrameEncoding)encoding;

@property(nonatomic, assign, readwrite) float focusScore;
@property(nonatomic, assign, readwrite) BOOL focusOk;
@property(nonatomic, assign, readwrite) BOOL focusSucks;
@property(nonatomic, assign, readwrite) float brightnessScore;
@property(nonatomic, assign, readwrite) BOOL brightnessLow;
@property(nonatomic, assign, readwrite) BOOL brightnessHigh;
@property(nonatomic, assign, readwrite) BOOL foundTopEdge;
@property(nonatomic, assign, readwrite) BOOL foundBottomEdge;
@property(nonatomic, assign, readwrite) BOOL foundLeftEdge;
@property(nonatomic, assign, readwrite) BOOL foundRightEdge;
@property(nonatomic, assign, readwrite) BOOL flipped;
@property(nonatomic, assign, readwrite) BOOL scanExpiry;
@property(nonatomic, assign, readwrite) NSInteger isoSpeed;
@property(nonatomic, assign, readwrite) float shutterSpeed;
@property(nonatomic, strong, readwrite) CardIOIplImage *ySample;
@property(nonatomic, strong, readwrite) CardIOIplImage *cbSample;
@property(nonatomic, strong, readwrite) CardIOIplImage *crSample;
@property(nonatomic, strong, readwrite) CardIOIplImage *cardY;
@property(nonatomic, strong, readwrite) CardIOIplImage *cardCb;
@property(nonatomic, strong, readwrite) CardIOIplImage *cardCr;
@property(nonatomic, strong, readwrite) CardIOCardScanner *scanner;
@property(nonatomic, strong, readwrite) CardIOReadCardInfo *cardInfo; // Will be nil unless frame processing completes with a successful scan
@property(assign) dmz_context *dmz;
@property(nonatomic, assign, readwrite) BOOL calculateBrightness;
@property(nonatomic, assign, readwrite) BOOL torchIsOn;

@property(nonatomic, assign, readwrite) CardIODetectionMode detectionMode;

#if CARDIO_DEBUG
@property(nonatomic, strong, readwrite) NSString *debugString;
@property(nonatomic, strong, readwrite) UIImage *debugCardImage;
#endif

@end

#endif
