//
//  CardIOReadCardInfo.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>


@interface CardIOReadCardInfo : NSObject

+ (CardIOReadCardInfo *)cardInfoWithNumber:(NSString *)cardNumber
                                  xOffsets:(NSArray *)xOffsets
                                   yOffset:(NSUInteger)yOffset
                               expiryMonth:(NSUInteger)expiryMonth
                                expiryYear:(NSUInteger)expiryYear
#if CARDIO_DEBUG
                        expiryGroupedRects:(NSArray *)expiryGroupedRects
                          nameGroupedRects:(NSArray *)nameGroupedRects
#endif
                        ;

@property(nonatomic, strong, readonly) NSString *numbers;
@property(nonatomic, strong, readonly) NSArray *xOffsets;
@property(nonatomic, assign, readonly) NSUInteger yOffset;
@property(nonatomic, assign, readonly) NSUInteger expiryYear;
@property(nonatomic, assign, readonly) NSUInteger expiryMonth;
@property(nonatomic, assign, readonly) BOOL isFlipped;

#if CARDIO_DEBUG
@property(nonatomic, strong, readonly) NSArray *expiryGroupedRects;
@property(nonatomic, strong, readonly) NSArray *nameGroupedRects;
#endif

@end
