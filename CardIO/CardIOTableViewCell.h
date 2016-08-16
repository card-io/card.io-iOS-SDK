//
//  CardIOTableViewCell.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>

// This should really be a category on UITableViewCell, but
// categories don't play nicely with static libraries (requires
// extra linker flags).

@interface CardIOTableViewCell : NSObject

+ (UIFont *)defaultTextLabelFontForCellStyle:(UITableViewCellStyle)cellStyle;
+ (UIFont *)defaultTextLabelFontForCellStyle:(UITableViewCellStyle)cellStyle fontSize:(CGFloat)fontSize;
+ (CGFloat)defaultTextLabelFontSizeForCellStyle:(UITableViewCellStyle)cellStyle;
+ (UIColor *)defaultTextLabelColorForCellStyle:(UITableViewCellStyle)cellStyle;

+ (UIFont *)defaultDetailTextLabelFontForCellStyle:(UITableViewCellStyle)cellStyle;
+ (UIFont *)defaultDetailTextLabelFontForCellStyle:(UITableViewCellStyle)cellStyle fontSize:(CGFloat)fontSize;
+ (CGFloat)defaultDetailTextLabelFontSizeForCellStyle:(UITableViewCellStyle)cellStyle;
+ (UIColor *)defaultDetailTextLabelColorForCellStyle:(UITableViewCellStyle)cellStyle;

+ (UITableViewCellStyle) defaultCellStyle;

@end
