//
//  CardIOViewContinuation.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <AVFoundation/AVFoundation.h>

@class CardIOCardScanner;
@class CardIOTransitionView;

@interface CardIOView (continued)

@property(nonatomic, strong, readonly) CardIOCardScanner *scanner;
@property(nonatomic, strong, readonly) CardIOTransitionView *transitionView;

@end
