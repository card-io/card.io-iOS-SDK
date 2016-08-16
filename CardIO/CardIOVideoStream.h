//
//  CardIOVideoStream.h
//  See the file "LICENSE.md" for the full license governing this code.
//

// Handles a video stream, including setup and teardown, and dispatching frames to be processed.

#if USE_CAMERA || SIMULATE_CAMERA

#import <Foundation/Foundation.h>
#import "CardIOVideoStreamDelegate.h"
#import <AVFoundation/AVFoundation.h>
#import "dmz.h"

#define LOG_FPS 1 // for performance tuning/testing

@class CardIOCardScanner;
@class CardIOConfig;

@interface CardIOVideoStream : NSObject<AVCaptureVideoDataOutputSampleBufferDelegate> {
@private
#if USE_CAMERA
  dmz_context *dmz;
#endif
}
- (void)willAppear;
- (void)willDisappear;

- (BOOL)hasTorch;
- (BOOL)canSetTorchLevel;
- (BOOL)torchIsOn;
- (BOOL)setTorchOn:(BOOL)torchShouldBeOn; // returns success value
- (BOOL)hasAutofocus;

- (void)refocus;

- (void)startSession;
- (void)stopSession;

#if SIMULATE_CAMERA
- (void)considerItScanned;
#endif

@property(nonatomic, strong, readwrite) CardIOConfig *config;
@property(nonatomic, assign, readonly) BOOL running;
@property(nonatomic, weak, readwrite) id<CardIOVideoStreamDelegate> delegate;
#if SIMULATE_CAMERA
@property(nonatomic, strong, readonly) CALayer *previewLayer;
#else
@property(nonatomic, strong, readonly) AVCaptureVideoPreviewLayer *previewLayer;
#endif
@property(nonatomic, strong, readwrite) CardIOCardScanner *scanner;

@end

#endif //USE_CAMERA || SIMULATE_CAMERA
