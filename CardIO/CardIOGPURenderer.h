//
//  CardIOGPURenderer.h
//  See the file "LICENSE.md" for the full license governing this code.
//

@interface CardIOGPURenderer : NSObject {
  // Handles
  GLuint _programHandle;

  // Inputs
  GLuint _inputTexture, _positionSlot, _texCoordSlot, _textureUniform;
}
- (id)initWithSize:(CGSize)size vertexShaderSrc:(NSString *)vertexShaderSrc fragmentShaderSrc:(NSString *)vertexShaderSrc;
- (void)finish;

- (void)prepareForUse;
- (GLuint) uniformIndex:(NSString *)uniformName;

- (void)withContextDo:(void (^)(void))successBlock;

- (void)renderUIImage:(UIImage *)inputImage toSize:(const CGSize)targetSize;

// Creates a UIImage from the currently rendered framebuffer.
// Resulting image is 32bit RGBA
- (UIImage *)captureUIImageOfSize:(const CGSize)size;

#if USE_CAMERA
- (void)renderIplImage:(IplImage *)inputImage toSize:(const CGSize)targetSize;

// Creates an IplImage from the currently rendered framebuffer.
// Resulting image is 8bit grayscale
- (void) captureIplImage:(IplImage *)dstImg;
#endif // USE_CAMERA

@property (nonatomic, assign, readonly)  CGSize size;

@end
