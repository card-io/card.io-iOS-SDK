[![card.io logo](https://raw.githubusercontent.com/card-io/card.io-iOS-source/master/Resources/cardio_logo_220.png "card.io")](https://www.card.io)

card.io SDK for iOS
===================

[card.io](https://www.card.io/) provides fast, easy credit card scanning in mobile apps.

> #### *NEW!!! card.io is now an open-source project!*
> 
> As of December 2014, all of the source code for card.io is now available at the [card.io-iOS-source repo](https://github.com/card-io/card.io-iOS-source).
> 
> ##### What does this mean for you?
> 
> * If you simply wish to integrate card.io into your mobile apps, then you can (and probably should) ignore the existence of [card.io-iOS-source](https://github.com/card-io/card.io-iOS-source).
> * But if you're curious about how card.io performs its magic, or if you'd like to improve the appearance or behavior of card.io, then come visit [card.io-iOS-source](https://github.com/card-io/card.io-iOS-source)!

Brought to you by  
[![PayPal logo](https://raw.githubusercontent.com/card-io/card.io-iOS-source/master/Resources/pp_h_rgb.png)](https://paypal.com/ "PayPal")


Stay up to date
---------------

Please keep your app up to date with the latest version of the SDK.
All releases follow [semantic versioning](http://semver.org/).

To receive updates about new versions:

* Follow [@cardio](https://twitter.com/cardio) (also great to send us feedback)
* Subscribe to our [card-io-sdk-announce](https://groups.google.com/forum/#!forum/card-io-sdk-announce) list
* "Watch" this GitHub repository

You can find and start technical discussions using the [Stack Overflow card.io tag](http://stackoverflow.com/questions/tagged/card.io).

Sample app
----------

For a quick first look at card.io, we have included a very small sample application that you can build and run.

1. Download the latest version of the SDK.
2. Simply open the `SampleApp` folder or the `SampleApp-Swift` folder and follow the instructions in the `README.md` file you find there.


Instructions
------------

The card.io iOS SDK includes header files and a single static library. We'll walk you through integration and usage.

### Requirements

*   The latest non-beta version of Xcode. (Older or newer versions *might* also work.)
*   Supports target deployment of iOS version 6.1+ and instruction set armv7+ (including 64-bit).

### Setup

##### If you use [CocoaPods](http://cocoapods.org), then add this line to your podfile:

```ruby
pod 'CardIO'
```

##### If you don't use CocoaPods, then:

1. Download the latest version of the SDK.
2. Add the CardIO directory (containing several .h files, `libCardIO.a`, `libopencv_core.a`, and `libopencv_imgproc.a`) to your Xcode project.
3. In your project's Build Settings (in the `TARGETS` section, not the `PROJECTS` section), add `-lc++` to `Other Linker Flags`.
4. *Either:*
  * Add these frameworks to your project.
[Weak linking](http://developer.apple.com/library/mac/#documentation/DeveloperTools/Conceptual/cross_development/Configuring/configuring.html) is supported.
     * Accelerate
     * AudioToolbox
     * AVFoundation
     * CoreGraphics
     * CoreMedia
     * CoreVideo
     * Foundation
     * MobileCoreServices
     * OpenGLES
     * QuartzCore
     * Security
     * UIKit
5. *or:*
  * Add only these frameworks to your project  (as `Optional` [i.e., weak-linked] libraries):
    * Accelerate
    * AVFoundation
    * AudioToolbox
    * CoreMedia
    * MobileCoreServices
  * and confirm that these two Build Settings are both enabled:
    * `Enable Modules (C and Objective-C)`
    * `Link Frameworks Automatically`

##### With or without CocoaPods:

1.  Add [card.io's open source license acknowledgments](acknowledgments.md) to
[your app's acknowledgments](http://stackoverflow.com/questions/3966116/where-to-put-open-source-credit-information-for-an-iphone-app).
2.  Refer to the header files for more usage options and information.
3.  You should add the key [`NSCameraUsageDescription`](https://developer.apple.com/library/prerelease/content/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW24) to your app's `Info.plist` and set the value to be a string describing why your app needs to use the camera (e.g. "To scan credit cards."). This string will be displayed when the app initially requests permission to access the camera.

### Sample code

You can use card.io in two ways:

* **As a view controller**: *Quick and easy.* Create a `CardIOPaymentViewController` and present it modally. The card.io view controller handles all aspects of the UX, including manual entry as a fallback, all transitions, and number confirmation.

* **As a view**: *More flexible.* Create a `CardIOView` to do card scanning only and manage everything else yourself. This enables a broader range of presentations, such as in-place transitions, but requires that you handle the rest of the UI yourself.


#### Integrate as a View Controller

Create a class (most likely a subclass of `UIViewController`) that conforms to `CardIOPaymentViewControllerDelegate`.

```obj-c
// SomeViewController.h

#import "CardIO.h"
@interface SomeViewController : UIViewController<CardIOPaymentViewControllerDelegate>
// ...
```

Make an optional call to speed up the subsequent launch of card.io scanning:

```obj-c
// SomeViewController.m

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  [CardIOUtilities preloadCardIO];
}

```

Start card.io card scanning:

```obj-c
// SomeViewController.m

- (IBAction)scanCard:(id)sender {
  CardIOPaymentViewController *scanViewController = [[CardIOPaymentViewController alloc] initWithPaymentDelegate:self];
  [self presentViewController:scanViewController animated:YES completion:nil];
}
```

Write delegate methods to receive the card info or a cancellation:

```obj-c
// SomeViewController.m

- (void)userDidCancelPaymentViewController:(CardIOPaymentViewController *)scanViewController {
  NSLog(@"User canceled payment info");
  // Handle user cancellation here...
  [scanViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)userDidProvideCreditCardInfo:(CardIOCreditCardInfo *)info inPaymentViewController:(CardIOPaymentViewController *)scanViewController {
  // The full card number is available as info.cardNumber, but don't log that!
  NSLog(@"Received card info. Number: %@, expiry: %02i/%i, cvv: %@.", info.redactedCardNumber, info.expiryMonth, info.expiryYear, info.cvv);
  // Use the card info...
  [scanViewController dismissViewControllerAnimated:YES completion:nil];
}
```

#### Integrate as a View

*CardIOView is new as of card.io Version 3.3.0 (September 2013). We look forward to seeing how creative developers integrate it into their apps. If you do something cool with it, share it with [@cardio](https://twitter.com/cardio)! We also look forward to quickly resolving any issues that you may discover.*

Create a class (most likely a subclass of `UIViewController`) that conforms to `CardIOViewDelegate`.

```obj-c
// SomeViewController.h

#import "CardIO.h"
@interface SomeViewController : UIViewController<CardIOViewDelegate>
// ...
```

Using a CardIOView provides UI flexibility. Here are two sample integration options:

* Create a CardIOView when you need it, and then delete it when its work is finished.
* Include a hidden CardIOView in your view, show it when you need it, and then hide it when its work is finished.

##### Option 1: Create a CardIOView when you need it

Confirm that the user's device is capable of scanning cards:

```obj-c
// SomeViewController.m

- (void)viewDidLoad {
  [super viewDidLoad];

  if (![CardIOUtilities canReadCardWithCamera]) {
    // Hide your "Scan Card" button, or take other appropriate action...
  }
}
```

Make an optional call to speed up the subsequent launch of card.io scanning:

```obj-c
// SomeViewController.m

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  [CardIOUtilities preloadCardIO];
}

```

Start card.io card scanning:

```obj-c
// SomeViewController.m

- (IBAction)scanCard:(id)sender {
  CardIOView *cardIOView = [[CardIOView alloc] initWithFrame:CGRECT_WITHIN_YOUR_VIEW];
  cardIOView.delegate = self;
  
  [self.view addSubview:cardIOView];
}
```

Write the delegate method to receive the results:

```obj-c
// SomeViewController.m

- (void)cardIOView:(CardIOView *)cardIOView didScanCard:(CardIOCreditCardInfo *)info {
    if (info) {
    // The full card number is available as info.cardNumber, but don't log that!
    NSLog(@"Received card info. Number: %@, expiry: %02i/%i, cvv: %@.", info.redactedCardNumber, info.expiryMonth, info.expiryYear, info.cvv);
    // Use the card info...
  }
  else {
    NSLog(@"User cancelled payment info");
    // Handle user cancellation here...
  }
  
  [cardIOView removeFromSuperview];
}
```

Include a method to cancel card scanning:

```obj-c
// SomeViewController.m

- (IBAction)cancelScanCard:(id)sender {
  [cardIOView removeFromSuperview];
}
```

##### Option 2: Include a hidden CardIOView in your view

Make an IBOutlet property:

```obj-c
// SomeViewController.m

@interface SomeViewController ()
@property(nonatomic, strong, readwrite) IBOutlet CardIOView *cardIOView;
@end
```

In your .xib, include a CardIOView, mark it as `hidden`, and connect it to the IBOutlet property. (Note: usually you will want to set the background color of the CardIOView to `clearColor`.)

After confirming that the user's device is capable of scanning cards, set the `delegate` property of the CardIOView:

```obj-c
// SomeViewController.m

- (void)viewDidLoad {
  [super viewDidLoad];

  if (![CardIOUtilities canReadCardWithCamera]) {
    // Hide your "Scan Card" button, remove the CardIOView from your view, and/or take other appropriate action...
  } else {
    self.cardIOView.delegate = self;
  }
}
```

Make an optional call to speed up the subsequent launch of card.io scanning:

```obj-c
// SomeViewController.m

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  [CardIOUtilities preloadCardIO];
}

```

Start card.io card scanning:

```obj-c
// SomeViewController.m

- (IBAction)scanCard:(id)sender {
  self.cardIOView.hidden = NO;
}
```

Write the delegate method to receive the results:

```obj-c
// SomeViewController.m

- (void)cardIOView:(CardIOView *)cardIOView didScanCard:(CardIOCreditCardInfo *)info {
    if (info) {
    // The full card number is available as info.cardNumber, but don't log that!
    NSLog(@"Received card info. Number: %@, expiry: %02i/%i, cvv: %@.", info.redactedCardNumber, info.expiryMonth, info.expiryYear, info.cvv);
    // Use the card info...
  }
  else {
    NSLog(@"User canceled payment info");
    // Handle user cancellation here...
  }

  cardIOView.hidden = YES;
}
```

Include a method to cancel card scanning:

```obj-c
// SomeViewController.m

- (IBAction)cancelScanCard:(id)sender {
  self.cardIOView.hidden = YES;
}
```


### Hints & Tips

* Processing images can be memory intensive, so make sure to test that your app properly handles memory warnings.
* For your users' security, [obscure your app's cached screenshots](https://viaforensics.com/resources/reports/best-practices-ios-android-secure-mobile-development/ios-avoid-cached-application-snapshots/).  
**Note:** By default, a `CardIOPaymentViewController` automatically blurs its own screens when the app is backgrounded. A `CardIOView` does not do any automatic blurring.
* The first time that you create either a `CardIOPaymentViewController` or a `CardIOView`, the card.io SDK must load resources, which can result in a noticeable delay. To avoid this delay you may optionally call `[CardIOUtilities preloadCardIO]` in advance, so that this resource loading occurs in advance on a background thread.
