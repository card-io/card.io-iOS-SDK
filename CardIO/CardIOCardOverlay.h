//
//  CardIOCardOverlay.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <Foundation/Foundation.h>

@class CardIOReadCardInfo;

@interface CardIOCardOverlay : NSObject

+ (UIImage *)cardImage:(UIImage *)cardImage withDisplayInfo:(CardIOReadCardInfo *)cardInfo annotated:(BOOL)shouldAnnotate;

@end

#endif
