//
//  CardIODevice.h
//  See the file "LICENSE.md" for the full license governing this code.
//

// Repository for device-specific settings. Device includes both hardware and OS version.

#import <Foundation/Foundation.h>

@interface CardIODevice : NSObject

+ (BOOL)hasVideoCamera;
+ (BOOL)shouldSetPixelFormat;

@end
