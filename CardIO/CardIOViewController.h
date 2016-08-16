//
//  CardIOViewController.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#if USE_CAMERA || SIMULATE_CAMERA

#import <UIKit/UIKit.h>

#import <AudioToolbox/AudioServices.h>

@class CardIOContext;

@interface CardIOViewController : UIViewController

- (id)init;

@property(nonatomic, strong, readwrite) CardIOContext *context;

@end

#endif //USE_CAMERA || SIMULATE_CAMERA
