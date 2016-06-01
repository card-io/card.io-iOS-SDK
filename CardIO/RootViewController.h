//
//  RootViewController.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <UIKit/UIKit.h>
#import "CardIOPaymentViewControllerDelegate.h"
#import "CardIOViewDelegate.h"

@interface RootViewController : UIViewController<CardIOPaymentViewControllerDelegate, CardIOViewDelegate, UIActionSheetDelegate, UIAlertViewDelegate>

- (IBAction)scan;
- (IBAction)scanPicoPika;

#if CARDIO_DEBUG
- (IBAction)doI18n;
#endif

@end
