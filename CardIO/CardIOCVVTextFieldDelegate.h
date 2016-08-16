//
//  CardIOCVVTextFieldDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOConfigurableTextFieldDelegate.h"

@interface CardIOCVVTextFieldDelegate : CardIOConfigurableTextFieldDelegate

+ (BOOL)isValidCVV:(NSString *)cvv forNumber:(NSString *)number;

@end
