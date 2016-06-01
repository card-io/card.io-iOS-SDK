//
//  CardIODmzBridge.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import "dmz.h"
#import <Foundation/Foundation.h>

static inline FrameOrientation frameOrientationWithInterfaceOrientation(UIInterfaceOrientation interfaceOrientation) {
  FrameOrientation frameOrientation = FrameOrientationPortrait; // provide a default to keep static analyzer happy
  switch(interfaceOrientation) {
    case UIInterfaceOrientationPortrait:
      frameOrientation = FrameOrientationPortrait;
      break;
    case UIInterfaceOrientationPortraitUpsideDown:
      frameOrientation = FrameOrientationPortraitUpsideDown;
      break;
    case UIInterfaceOrientationLandscapeLeft:
      frameOrientation = FrameOrientationLandscapeLeft;
      break;
    case UIInterfaceOrientationLandscapeRight:
      frameOrientation = FrameOrientationLandscapeRight;
      break;
  }
  return frameOrientation; 
}

static inline CGRect CGRectWithDmzRect(dmz_rect rect) {
  return CGRectMake(rect.x, rect.y, rect.w, rect.h);
}

static inline CGRect CGRectWithRotatedDmzRect(dmz_rect rect) {
  return CGRectMake(rect.y, rect.x, rect.h, rect.w);
}
