//
//  CardIOGPUTransformFilter.h
//  See the file "LICENSE.md" for the full license governing this code.
//

#import "CardIOGPUFilter.h"

@interface CardIOGPUTransformFilter : CardIOGPUFilter {
  GLfloat orthographicMatrix[16];
  GLuint _transformMatrixUniform, _orthographicMatrixUniform;
}

// Initialize with the size of the input texture
- (id)initWithSize:(CGSize)size;

// Set the perspective matrix for this filter.
// Array of floats in column-major format.
- (void)setPerspectiveMat:(float *)matrix;

@end
