Pod::Spec.new do |spec|
  spec.name             = 'CardIO'
  spec.version          = '5.4.1'
  spec.license          = { type: 'MIT', file: 'LICENSE.md' }
  spec.homepage         = 'https://www.card.io'
  spec.authors          = { 'CardIO' => 'support@paypal.com' }
  spec.summary          = 'Credit card scanning for mobile apps'
  spec.social_media_url = 'https://twitter.com/cardio'
  spec.source           = { :git => 'https://github.com/card-io/card.io-iOS-SDK.git', :tag => "#{spec.version}" }
  spec.platform         = :ios, '6.1'
  spec.ios.deployment_target = '6.1'
  spec.requires_arc     = true
  spec.source_files     = 'CardIO/*.{h,m}'
  spec.frameworks       = 'Accelerate', 'AVFoundation', 'AudioToolbox', 'CoreGraphics', 'CoreMedia', 'CoreVideo', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'Security', 'UIKit'
  spec.libraries        = 'c++'
  spec.vendored_libraries = 'CardIO/libCardIOCore.a', 'CardIO/libopencv_core.a', 'CardIO/libopencv_imgproc.a'
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
end
