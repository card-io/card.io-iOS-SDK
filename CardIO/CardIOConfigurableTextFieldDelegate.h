//
//  CardIOConfigurableTextFieldDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>


@interface CardIOConfigurableTextFieldDelegate : NSObject<UITextFieldDelegate> {
@private
  BOOL numbersOnly;
  NSInteger maxLength; // set to zero for no max length
}

@property(nonatomic, assign, readwrite) BOOL numbersOnly;
@property(nonatomic, assign, readwrite) NSInteger maxLength;

+ (BOOL)containsNumbersOnly:(NSString *)newText;
+ (NSInteger)lengthOfString:(NSString *)originalText afterChangingCharactersInRange:(NSRange)range replacementString:(NSString *)string;

+ (NSInteger)nonDigitsInTextField:(UITextField *)textField beforeOffset:(NSInteger)offset;
+ (UITextPosition *)positionInTextField:(UITextField *)textField after:(NSInteger)numberOfDigits;

+ (void)getSelectionInTextField:(UITextField *)textField
          withSelectedTextRange:(UITextRange *)selectedTextRange
                       forStart:(NSInteger *)startSelectionOffset
                         forEnd:(NSInteger *)endSelectionOffset;

+ (void)vibrate;

@end
