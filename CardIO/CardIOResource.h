//
//  CardIOResource.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOCreditCardInfo.h"

@interface CardIOResource : NSObject

// These are drawn using Quartz
+ (UIButton *)lightButton;
+ (UIImage *)boltImageForTorchOn:(BOOL)torchIsOn;

@end
