//
//  CardIOAnalytics.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>

@class CardIOContext;
@class CardIOCardScanner;

@interface CardIOAnalytics : NSObject

- (id)initWithContext:(CardIOContext *)aContext;

#if USE_CAMERA || SIMULATE_CAMERA

// Trigger the reporting of current scan analytics
- (void)reportEventWithLabel:(NSString *)reportLabel withScanner:(CardIOCardScanner *)cardScanner;

#endif // USE_CAMERA || SIMULATE_CAMERA

@property(nonatomic, weak, readwrite) CardIOContext *context; // danger of retain cycles here, since context has a ref to us
@property(nonatomic, strong, readwrite) NSString *sessionID;

@end

