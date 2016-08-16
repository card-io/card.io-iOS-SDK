//
//  ShutterView.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>


@interface CardIOShutterView : UIView

- (void)setOpen:(BOOL)shouldBeOpen animated:(BOOL)animated duration:(CFTimeInterval)duration;

@property(nonatomic, assign, readwrite) BOOL open;

@end
