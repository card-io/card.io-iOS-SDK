//
//  CardGuideOverlayView.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <UIKit/UIKit.h>

#define kDefaultGuideColor [UIColor colorWithRed:0.0f green:1.0f blue:0.0f alpha:1.0f]

@protocol CardIOGuideLayerDelegate <NSObject>
- (void)guideLayerDidLayout:(CGRect)internalGuideFrame;
@end

/**
 * This layer is meant to be layered atop a camera preview; it provides guidance about where to hold
 * the card, and what edges are currently recognized.
 *
 * It should be a sublayer of the camera preview, with the same size.
 */

@class CardIOVideoFrame;

@interface CardIOGuideLayer : CALayer

- (id)initWithDelegate:(id<CardIOGuideLayerDelegate>)guideLayerDelegate;

- (CGRect)guideFrame;

- (void)showCardFound:(BOOL)found;

- (void)didRotateToDeviceOrientation:(UIDeviceOrientation)deviceOrientation;

@property(nonatomic, strong, readwrite) UIColor *guideColor;
@property(nonatomic, strong, readwrite) CardIOVideoFrame *videoFrame;
@property(nonatomic, assign, readwrite) CFTimeInterval animationDuration;
@property(nonatomic, assign, readwrite) UIDeviceOrientation deviceOrientation;
@property(nonatomic, strong, readwrite) CAGradientLayer *fauxCardLayer;

@end

#endif
