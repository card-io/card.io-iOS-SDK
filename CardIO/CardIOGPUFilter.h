//
//  CardIOGPUFilter.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import <Foundation/Foundation.h>
#import "CardIOGPURenderer.h"
#import <OpenGLES/ES3/gl.h>

@interface CardIOGPUFilter : NSObject {
  CardIOGPURenderer *_gpuRenderer;
}

@property (nonatomic, assign, readonly) CGSize size;

- (id)initWithSize:(CGSize)size vertexShaderSrc:(NSString *)vertexShaderSrc fragmentShaderSrc:(NSString *)fragmentShaderSrc;

// Called upon app backgrounding, to call glFinish()
- (void)finish;

// Returns a new UIImage of the given size
- (UIImage *)processUIImage:(UIImage *)srcUIImage toSize:(const CGSize)size;

#if USE_CAMERA
- (UIImage *)processIplToUIImage:(IplImage *)srcImg toSize:(const CGSize)size;

// Sets the imageData of the given dstImg IplImage.
- (void)processIplImage:(IplImage *)srcImg dstIplImg:(IplImage *)dstImg;
#endif // USE_CAMERA

// Helper class methods
+ (void)loadIdentityMatrix:(GLfloat *)matrix size:(GLuint)size;
+ (void)loadOrthoMatrix:(GLfloat *)matrix left:(GLfloat)left right:(GLfloat)right bottom:(GLfloat)bottom top:(GLfloat)top near:(GLfloat)near far:(GLfloat)far;
+ (NSString *)matrixAsString:(GLfloat *)matrix size:(GLuint)size rowMajor:(BOOL)rowMajor;

@end
