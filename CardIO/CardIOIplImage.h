//
//  CardIOIplImage.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

#define Y_PLANE 0
#define CBCR_PLANE 1

@interface CardIOIplImage : NSObject {
@private
  IplImage *image;
}

+ (CardIOIplImage *)imageWithSize:(CvSize)size depth:(int)depth channels:(int)channels;
+ (CardIOIplImage *)imageWithIplImage:(IplImage *)anImage;
- (id)initWithIplImage:(IplImage *)anImage;

+ (CardIOIplImage *)imageFromYCbCrBuffer:(CVImageBufferRef)imageBuffer plane:(size_t)plane;

- (CardIOIplImage *)copyCropped:(CvRect)roi;
- (CardIOIplImage *)copyCropped:(CvRect)roi destSize:(CvSize)destSize;

- (NSArray *)split;

+ (CardIOIplImage *)rgbImageWithY:(CardIOIplImage *)y cb:(CardIOIplImage *)cb cr:(CardIOIplImage *)cr;

- (UIImage *)UIImage;

@property(nonatomic, assign, readonly) IplImage *image;
@property(nonatomic, assign, readonly) CvSize cvSize;
@property(nonatomic, assign, readonly) CGSize cgSize;
@property(nonatomic, assign, readonly) CvRect cvRect;

@end
