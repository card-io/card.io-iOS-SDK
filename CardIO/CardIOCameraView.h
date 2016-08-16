//
//  CardIOCameraView.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <UIKit/UIKit.h>
#import "CardIOGuideLayer.h"
#import "CardIOVideoStreamDelegate.h"

#define kRotationAnimationDuration 0.2f

@class CardIOConfig;
@class CardIOVideoFrame;
@class CardIOVideoStream;
@class CardIOCardScanner;

@interface CardIOCameraView : UIView<CardIOVideoStreamDelegate, CardIOGuideLayerDelegate>

- (id)initWithFrame:(CGRect)frame delegate:(id<CardIOVideoStreamDelegate>)delegate config:(CardIOConfig *)config;

- (void)updateLightButtonState;

- (void)willAppear;
- (void)willDisappear;

- (void)startVideoStreamSession;
- (void)stopVideoStreamSession;

- (CGRect)guideFrame;

// CGRect for the actual camera preview area within the cameraView
- (CGRect)cameraPreviewFrame;

@property(nonatomic, strong, readonly)  CardIOCardScanner *scanner;
@property(nonatomic, weak, readwrite)   id<CardIOVideoStreamDelegate> delegate;
@property(nonatomic, strong, readwrite) UIFont *instructionsFont;
@property(nonatomic, assign, readwrite) BOOL suppressFauxCardLayer;

@end

#endif