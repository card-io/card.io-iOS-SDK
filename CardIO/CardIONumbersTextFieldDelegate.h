//
//  CardIONumbersTextFieldDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOConfigurableTextFieldDelegate.h"

@class CardIOCreditCardNumberFormatter;

@interface CardIONumbersTextFieldDelegate : CardIOConfigurableTextFieldDelegate

@property(nonatomic, strong, readonly) CardIOCreditCardNumberFormatter *formatter;

- (BOOL)cleanupTextField:(UITextField *)textField;

@end