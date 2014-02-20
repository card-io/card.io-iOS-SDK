card.io SDK for iOS
===================

[card.io](https://www.card.io/) provides fast, easy credit card scanning in mobile apps.

Stay up to date
---------------

**Get the latest SDK by downloading an archive of [the most recent release](https://github.com/card-io/card.io-iOS-SDK/releases).**

Please keep your app up to date with the latest version of the SDK.
All releases follow [semantic versioning](http://semver.org/).

To receive updates about new versions:

* Follow [@cardio](https://twitter.com/cardio) (also great to send us feedback)
* Subscribe to our [card-io-sdk-announce](https://groups.google.com/forum/#!forum/card-io-sdk-announce) list
* "Watch" this GitHub repository

You can find and start technical discussions using the [Stack Overflow card.io tag](http://stackoverflow.com/questions/tagged/card.io).
 
**CocoaPods users:** We strongly recommend that you [include your Pods directory in source control](http://guides.cocoapods.org/using/using-cocoapods.html#should-i-ignore-the-pods-directory-in-source-control?), as for security reasons we may sometimes stop distributing old versions of the SDK. For details, see [this discussion of the card.io SDK pod](https://github.com/card-io/card.io-iOS-SDK/issues/24).

Sample app
----------

For a quick first look at card.io, we have included a very small sample application that you can build and run.

1. **Get the latest SDK by downloading an archive of [the most recent release](https://github.com/card-io/card.io-iOS-SDK/releases).**
2. Simply open the `SampleApp` folder and follow the instructions in the `README.md` file you find there.


Instructions
------------

The card.io iOS SDK includes header files and a single static library. We'll walk you through integration and usage.

### Sign up for card.io

*   To use the card.io SDK, you'll need to [sign up](https://www.card.io/accounts/register/developer) and [get an app token](https://www.card.io/apps/). 

### Requirements

*   Supports target deployment of iOS version 6.1+ and instruction set armv7+ (including 64-bit).

### Setup

1. **Get the latest SDK by downloading an archive of [the most recent release](https://github.com/card-io/card.io-iOS-SDK/releases).**
2. Add the CardIO directory (containing several .h files and libCardIO.a) to your Xcode project.
3. In your project's Build Settings (in the `TARGETS` section, not the `PROJECTS` section), add `-lc++` to `Other Linker Flags`.
4. *Either:*
  * Add these frameworks to your project.
[Weak linking](http://developer.apple.com/library/mac/#documentation/DeveloperTools/Conceptual/cross_development/Configuring/configuring.html) is supported.
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
5. *or,* if you are using Xcode 5 or newer:
  * Add only this single framework to your project:
    * AVFoundation (as an `Optional` [i.e., weak-linked] library)
  * and confirm that these two Build Settings are both enabled:
    * `Enable Modules (C and Objective-C)`
    * `Link Frameworks Automatically`
6.  Add [card.io's open source license acknowledgments](acknowledgments.md) to
[your app's acknowledgments](http://stackoverflow.com/questions/3966116/where-to-put-open-source-credit-information-for-an-iphone-app).
7.  Refer to the header files for more usage options and information.

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
  NSLog(@"Received card info. Number: %@, expiry
