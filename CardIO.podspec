Pod::Spec.new do |spec|
  spec.name             = 'CardIO'
  spec.version          = '5.1.0'
  spec.license          = { type: 'MIT', file: 'LICENSE.md' }
  spec.homepage         = 'https://www.card.io'
  spec.authors          = { 'CardIO' => 'support@paypal.com' }
  spec.summary          = 'Credit card scanning for mobile apps'
  spec.social_media_url = 'https://twitter.com/cardio'
  spec.source           = { :git => 'https://github.com/card-io/card.io-iOS-SDK.git', :tag => "#{spec.version}" }
  spec.platform         = :ios, '6.1'
  spec.ios.deployment_target = '6.1'
  spec.requires_arc     = true
  spec.source_files     = 'CardIO/*.h'
  spec.preserve_path    = 'CardIO/*.a'
  spec.frameworks       = 'AVFoundation', 'AudioToolbox', 'CoreMedia', 'CoreVideo', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'Security', 'UIKit'
  spec.libraries        = 'CardIO', 'c++'
  spec.xcconfig         = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/CardIO/CardIO"' }
end
