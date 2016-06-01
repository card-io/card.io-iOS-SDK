//
//  CardIORowBasedTableViewSection.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>

@interface CardIORowBasedTableViewSection : NSObject <
  UITableViewDataSource,
  UITableViewDelegate
> {
@private
  NSArray *rows;
  NSString *headerTitle;
  UIView *headerView;
  NSString *footerTitle;
  UIView *footerView;
}

- (NSUInteger)indexOfRow:(id<UITableViewDelegate, UITableViewDataSource>)row;

// Each row should be an object that conforms to UITableViewDelegate and UITableViewDataSource,
// but which handles only requests for a single row. It should generally ignore the section and row info
// passed in (except where needed such as to deselect a cell at a particular index path).
// Rows unfortunately must implement tableView:numberOfRowsInSection:, but the value it (as well as other irrelevant
// methods such as tableView:numberOfSections:) returns will be ignored. :)

@property(nonatomic, strong, readwrite) NSArray *rows;
@property(nonatomic, strong, readwrite) NSString *headerTitle;
@property(nonatomic, strong, readwrite) UIView *headerView;
@property(nonatomic, strong, readwrite) NSString *footerTitle;
@property(nonatomic, strong, readwrite) UIView *footerView;

@end
