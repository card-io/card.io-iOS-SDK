//
//  CardIOSectionBasedTableViewDelegate.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>

@interface CardIOSectionBasedTableViewDelegate : NSObject <
  UITableViewDelegate,
  UITableViewDataSource
> {
@private
  NSArray *sections;
}

- (NSUInteger)indexOfSection:(id<UITableViewDelegate, UITableViewDataSource>)section;

// Each section should be an object that conforms to UITableViewDelegate and UITableViewDataSource,
// but which handles only requests for a single section. It should generally ignore the section
// passed in (except where needed such as to deselect a cell at a particular index path).
// Sections may implement tableView:numberOfSections: if they really want, but it will be ignored. :)

@property(nonatomic, strong, readwrite) NSArray *sections;

@end
