//
//  CardIOMultipleFieldTableViewCell.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <UIKit/UIKit.h>

@class CardIOMultipleFieldContentView;

@interface CardIOMultipleFieldTableViewCell : UITableViewCell<UITableViewDelegate, UITableViewDataSource> {
@private
  CardIOMultipleFieldContentView *content;
  Class textFieldClass;
}

//@property(nonatomic, retain, readwrite) NSArray *textFieldDelegates;
@property(nonatomic, assign, readwrite) NSUInteger numberOfFields; // should be a reasonable number ... 1-3 range.
@property(nonatomic, strong, readonly)  NSArray *textFields;
@property(nonatomic, strong, readonly)  NSMutableArray *labels;
@property(nonatomic, assign, readwrite) CGFloat labelWidth;
@property(nonatomic, assign, readwrite) Class textFieldClass;
@property(nonatomic, assign, readwrite) BOOL hiddenLabels;
@property(nonatomic, assign, readwrite) NSTextAlignment textAlignment;

- (BOOL)textFitsInMultiFieldForLabel:(NSString *)labelText
                      forPlaceholder:(NSString *)placeholderText
                       forFieldWidth:(CGFloat)fieldWidth;

@end
