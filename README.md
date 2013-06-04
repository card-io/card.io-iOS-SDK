card.io SDK for iOS
===================

[card.io](https://www.card.io/) provides fast, easy credit card scanning in mobile apps.

Stay up to date
---------------

Please be sure to keep your app up to date with the latest version of the SDK.
All releases follow [semantic versioning](http://semver.org/).

You can receive updates about new versions via a few different channels:

* Follow [@cardio](https://twitter.com/cardio) (also great to send us feedback)
* Subscribe to our [card-io-sdk-announce](https://groups.google.com/groups/card-io-sdk-announce) list.
* "Watch" this GitHub repository

Also be sure to check and post to the [Stack Overflow card.io tag](http://stackoverflow.com/questions/tagged/card.io).

Instructions
------------

The card.io iOS SDK includes header files and a single static library. We'll walk you through integration and usage.

### Requirements

*   Supports target deployment of iOS version 5.0+.
*   Supports armv7 and armv7s devices, but not armv6.

### Instructions

1. Get the latest SDK by cloning this repo or downloading an archive of the most recent tag.
2. Add the CardIO directory (containing several .h files and libCardIO.a) to your Xcode project.
3. In your project's Build Settings, add `-lc++` to `Other Linker Flags`.
4. Add these frameworks to your project.
[Weak linking](http://developer.apple.com/library/mac/#documentation/DeveloperTools/Conceptual/cross_development/Configuring/configuring.html)
for iOS versions back to 4.0 is supported.
    * AVFoundation
    * AudioToolbox
    * CoreMedia
    * CoreVideo
    * MobileCoreServices
    * OpenGLES
    * QuartzCore
    * Security
    * UIKit
5.  Add [card.io's open source license acknowledgments](acknowledgments.md) to
[your app's acknowledgments](http://stackoverflow.com/questions/3966116/where-to-put-open-source-credit-information-for-an-iphone-app).
6.  Refer to the header files for more usage options and information.


### Sample code

Create a class (most likely a subclass of `UIViewController`) that conforms to `CardIOPaymentViewControllerDelegate`.

```obj-c
// SomeViewController.h

#import "CardIO.h"
@interface SomeViewController : UIViewController<CardIOPaymentViewControllerDelegate>
// ...
```

Start card.io card scanning:

```obj-c
// SomeViewController.m

- (IBAction)scanCard:(id)sender {
  CardIOPaymentViewController *scanViewController = [[CardIOPaymentViewController alloc] initWithPaymentDelegate:self];
  scanViewController.appToken = @"YOUR_APP_TOKEN_HERE"; // get your app token from the card.io website
  [self presentModalViewController:scanViewController animated:YES];
}
```

Write delegate methods to receive the card info or a cancellation:

```obj-c
// SomeViewController.m

- (void)userDidCancelPaymentViewController:(CardIOPaymentViewController *)scanViewController {
  NSLog(@"User canceled payment info");
  // Handle user cancellation here...
  [scanViewController dismissModalViewControllerAnimated:YES];
}

- (void)userDidProvideCreditCardInfo:(CardIOCreditCardInfo *)info inPaymentViewController:(CardIOPaymentViewController *)scanViewController {
  // The full card number is available as info.cardNumber, but don't log that!
  NSLog(@"Received card info. Number: %@, expiry: %02i/%i, cvv: %@.", info.redactedCardNumber, info.expiryMonth, info.expiryYear, info.cvv);
  // Use the card info...
  [scanViewController dismissModalViewControllerAnimated:YES];
}
```

### Hints & Tips

* Processing images can be memory intensive, so make sure to test that your app properly handles memory warnings.
* For your users' security, [obscure your app's cached screenshots](https://viaforensics.com/resources/reports/best-practices-ios-android-secure-mobile-development/ios-avoid-cached-application-snapshots/).




