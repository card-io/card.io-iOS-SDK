//
//  CardIOCreditCardNumberFormatter.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>


@interface CardIOCreditCardNumberFormatter : NSObject

// expects an initialized object in obj -- handles both NSString and CardIOCreditCardInfo
- (BOOL)getObjectValue:(id __autoreleasing *)obj forString:(NSString *)string errorDescription:(NSString **)error;

// returns a string with proper spaces added
- (NSString *)stringForObjectValue:(id)obj;


@end
