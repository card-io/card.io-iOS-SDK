//
//  CardIOPostalCodeTextFieldDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOConfigurableTextFieldDelegate.h"

@interface CardIOPostalCodeTextFieldDelegate : CardIOConfigurableTextFieldDelegate {
    
}

+(BOOL)isValidPostalCode:(NSString*)postalCode;

@end
