//
//  CardIOCreditCardNumber.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>

#import "CardIOCreditCardInfo.h"

@interface CardIOCreditCardNumber : NSObject 

+ (CardIOCreditCardType)cardTypeForCardNumber:(NSString *)cardNumber;
+ (NSInteger)numberLengthForCardNumber:(NSString *)cardNumber; // returns -1 for unknown
+ (NSInteger)cvvLengthForCardType:(CardIOCreditCardType)cardType; // returns -1 for unknown
+ (BOOL)passesLuhnChecksum:(NSString *)cardNumber;
+ (NSString *)stringByRemovingNonNumbers:(NSString *)stringWithSpaces;
+ (NSString *)stringbyRemovingSpaces:(NSString *)stringWithSpaces;
+ (BOOL)isValidNumber:(NSString *)number;

@end
