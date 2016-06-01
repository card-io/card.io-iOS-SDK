//
//  CardIOExpiryTextFieldDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOConfigurableTextFieldDelegate.h"
#import "CardIOCreditCardExpiryFormatter.h"

@interface CardIOExpiryTextFieldDelegate : CardIOConfigurableTextFieldDelegate

@property(nonatomic, strong, readonly) CardIOCreditCardExpiryFormatter *formatter;

- (BOOL)cleanupTextField:(UITextField *)textField;

@end
