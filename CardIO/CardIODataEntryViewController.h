//
//  CardIODataEntryViewController.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <UIKit/UIKit.h>

@class CardIOContext;
@class CardIOCreditCardInfo;

#define kCardPadding 10.0f

#define kPortraitZoomedInCardImageSizePercent ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone ? 0.935f : 0.885f) // this is selected such that the resulting card width matches the width of a grouped UITableViewCell
#define kLandscapeZoomedInCardImageSizePercent ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone ? 0.484f : 0.493f) // this is selected such that the resulting card width is half of (screenwidth - kCardPadding).

@interface CardIODataEntryViewController : UIViewController

@property(nonatomic, strong, readwrite) CardIOCreditCardInfo *cardInfo;
@property(nonatomic, strong, readwrite) UIImage *cardImage;
@property(nonatomic, strong, readwrite) UIImageView *cardView;
@property(nonatomic, assign, readwrite) CGPoint cardImageCenter;
@property(nonatomic, assign, readwrite) CGSize cardImageSize;
@property(nonatomic, strong, readwrite) UIView *floatingCardView;
@property(nonatomic, strong, readwrite) UIWindow *floatingCardWindow;
@property(nonatomic, strong, readwrite) UIWindow *priorKeyWindow;
@property(nonatomic, assign, readwrite) BOOL manualEntry;
@property(nonatomic, assign, readwrite) BOOL collectExpiry;
@property(nonatomic, assign, readwrite) BOOL collectCVV;
@property(nonatomic, assign, readwrite) BOOL collectPostalCode;
@property(nonatomic, assign, readwrite) BOOL restrictPostalCodeToNumericOnly;
@property(nonatomic, assign, readwrite) BOOL collectCardholderName;
@property(nonatomic, strong, readwrite) UITextField *expiryTextField;
@property(nonatomic, strong, readwrite) UITextField *numberTextField;
@property(nonatomic, strong, readwrite) UITextField *cvvTextField;
@property(nonatomic, strong, readwrite) UITextField *postalCodeTextField;
@property(nonatomic, strong, readwrite) UITextField *cardholderNameTextField;

+ (BOOL)cardExpiryIsValid:(CardIOCreditCardInfo *)info;

- (id)initWithContext:(CardIOContext *)aContext withStatusBarHidden:(BOOL)statusBarHidden;

@end
