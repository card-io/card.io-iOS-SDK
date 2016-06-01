//
//  iccChoicesSelectViewController.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <UIKit/UIKit.h>

typedef void(^PPChoiceSelected)(NSString* selection);

@interface iccChoicesSelectViewController : UITableViewController

- (instancetype)initWithTitle:(NSString *)title choices:(NSArray *)choices currentSelection:(NSString *)currentSelection completion:(PPChoiceSelected)completed;
@end
