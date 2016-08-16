//
//  CardIOOrientation.h
//  See the file "LICENSE.md" for the full license governing this code.
//

// Orientation helpers

#import <Foundation/Foundation.h>

#define INTERFACE_LANDSCAPE_OR_PORTRAIT(interfaceOrientation) UIInterfaceOrientationIsPortrait(interfaceOrientation) ? @"PORTRAIT" : @"LANDSCAPE"
#define DEVICE_LANDSCAPE_OR_PORTRAIT(deviceOrientation) UIDeviceOrientationIsPortrait(deviceOrientation) ? @"PORTRAIT" : @"LANDSCAPE"

#define kNavigationBarHeightPortrait  44
#define kNavigationBarHeightLandscape 32

typedef uint8_t InterfaceToDeviceOrientationDelta; // the amount that the interfaceOrientation is rotated relative to the deviceOrientation

enum {
  InterfaceToDeviceOrientationSame = 1,
  InterfaceToDeviceOrientationUpsideDown = 2,
  InterfaceToDeviceOrientationRotatedClockwise = 3,
  InterfaceToDeviceOrientationRotatedCounterclockwise = 4
};

static inline InterfaceToDeviceOrientationDelta orientationDelta(UIInterfaceOrientation interfaceOrientation, UIDeviceOrientation deviceOrientation) {
  uint16_t absoluteInterfaceOrientation = 0;
  switch (interfaceOrientation) {
    case UIInterfaceOrientationPortrait:
      absoluteInterfaceOrientation = 0;
      break;
    case UIInterfaceOrientationLandscapeLeft:
      absoluteInterfaceOrientation = 270;
      break;
    case UIInterfaceOrientationLandscapeRight:
      absoluteInterfaceOrientation = 90;
      break;
    case UIInterfaceOrientationPortraitUpsideDown:
      absoluteInterfaceOrientation = 180;
      break;
    default:
      break;
  }

  uint16_t absoluteDeviceOrientation = 0;
  switch (deviceOrientation) {
    case UIDeviceOrientationPortrait:
      absoluteDeviceOrientation = 0;
      break;
    case UIDeviceOrientationLandscapeRight:
      absoluteDeviceOrientation = 270;
      break;
    case UIDeviceOrientationLandscapeLeft:
      absoluteDeviceOrientation = 90;
      break;
    case UIDeviceOrientationPortraitUpsideDown:
      absoluteDeviceOrientation = 180;
      break;
    default:
      // Note that we are explicitly not dealing with device flat / upside down here, since they do not impact
      // the camera orientation. We assume that someone upstream of us hands this.
      break;
  }

  uint16_t orientationDelta = (360 + absoluteInterfaceOrientation - absoluteDeviceOrientation) % 360;

  InterfaceToDeviceOrientationDelta delta = InterfaceToDeviceOrientationSame;
  switch (orientationDelta) {
    case 0:
      delta = InterfaceToDeviceOrientationSame;
      break;
    case 90:
      delta = InterfaceToDeviceOrientationRotatedCounterclockwise;
      break;
    case 180:
      delta = InterfaceToDeviceOrientationUpsideDown;
      break;
    case 270:
      delta = InterfaceToDeviceOrientationRotatedClockwise;
      break;
    default:
      break;
  }

  return delta;
}

static inline CGFloat rotationForOrientationDelta(InterfaceToDeviceOrientationDelta delta) {
  CGFloat rotation = 0.0f;
  switch (delta) {
    case InterfaceToDeviceOrientationSame:
      rotation = 0.0f;
      break;
    case InterfaceToDeviceOrientationRotatedClockwise:
      rotation = (CGFloat)(3 * M_PI_2);
      break;
    case InterfaceToDeviceOrientationUpsideDown:
      rotation = (CGFloat)M_PI;
      break;
    case InterfaceToDeviceOrientationRotatedCounterclockwise:
      rotation = (CGFloat)M_PI_2;
      break;
    default:
      break;
  }

  return rotation;
}

static inline CGFloat NavigationBarHeightForOrientation(UIInterfaceOrientation interfaceOrientation) {
  return ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone
          && UIInterfaceOrientationIsLandscape(interfaceOrientation)
          ? kNavigationBarHeightLandscape
          : kNavigationBarHeightPortrait);
}

static inline CGFloat NavigationBarHeightForCurrentOrientation(UINavigationController *navigationController) {
  return NavigationBarHeightForOrientation((navigationController && navigationController.modalPresentationStyle == UIModalPresentationFullScreen)
                                           ? [[UIApplication sharedApplication] statusBarOrientation]
                                           : UIInterfaceOrientationPortrait);
}

static inline NSString *StringForInterfaceOrientation(UIInterfaceOrientation interfaceOrientation) {
  NSString *string = nil;
  switch (interfaceOrientation) {
    case UIInterfaceOrientationPortrait:
      string = @"UIInterfaceOrientationPortrait";
      break;
    case UIInterfaceOrientationPortraitUpsideDown:
      string = @"UIInterfaceOrientationPortraitUpsideDown";
      break;
    case UIInterfaceOrientationLandscapeLeft:
      string = @"UIInterfaceOrientationLandscapeLeft";
      break;
    case UIInterfaceOrientationLandscapeRight:
      string = @"UIInterfaceOrientationLandscapeRight";
      break;
    default:
      break;
  }
  
  return string;
}

static inline UIInterfaceOrientation InterfaceOrientationForString(NSString *string) {
  UIInterfaceOrientation interfaceOrientation;
  if ([string isEqualToString:@"UIInterfaceOrientationPortrait"]) {
    interfaceOrientation = UIInterfaceOrientationPortrait;
  }
  else if ([string isEqualToString:@"UIInterfaceOrientationPortraitUpsideDown"]) {
    interfaceOrientation = UIInterfaceOrientationPortraitUpsideDown;
  }
  else if ([string isEqualToString:@"UIInterfaceOrientationLandscapeLeft"]) {
    interfaceOrientation = UIInterfaceOrientationLandscapeLeft;
  }
  else if ([string isEqualToString:@"UIInterfaceOrientationLandscapeRight"]) {
    interfaceOrientation = UIInterfaceOrientationLandscapeRight;
  }
  else {
    interfaceOrientation = UIInterfaceOrientationPortrait;
  }
  
  return interfaceOrientation;
}
