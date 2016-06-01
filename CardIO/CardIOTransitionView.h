//
//  CardIOTransitionView.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <UIKit/UIKit.h>
#import "CardIOAnimation.h"

@interface CardIOTransitionView : UIView

- (id)initWithFrame:(CGRect)frame cardImage:(UIImage *)cardImage transform:(CGAffineTransform)transform;
- (void)animateWithCompletion:(BareBlock)completionBlock;

@property(nonatomic, strong, readonly) UIImageView *cardView;

@end

#endif
