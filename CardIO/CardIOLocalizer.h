//
//  CardIOLocalizer.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CardIOLocalizer : NSObject

#if CARDIO_DEBUG
+ (NSArray *)allLanguages;
+ (BOOL)passesSelfTest:(NSError **)error;
#endif

+ (NSTextAlignment)textAlignmentForLanguageOrLocale:(NSString *)languageOrLocale;

+ (void)preload;

@end

// This ugly stuff is to prevent name-mangling, so that this function
// can be called from either Objective-C or Objective-C++ files.
#ifdef __cplusplus
extern "C" {
#endif
  
  NSString *CardIOLocalizedString(NSString *key,
                                  NSString *languageOrLocale);

#ifdef __cplusplus
}
#endif
