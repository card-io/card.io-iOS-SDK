Pod::Spec.new do |spec|
  spec.name             = 'CardIO'
  spec.version          = '5.1.1-bitcode'
  spec.license          = { type: 'MIT', file: 'LICENSE.md' }
  spec.homepage         = 'https://www.card.io'
  spec.authors          = { 'CardIO' => 'support@paypal.com', 'Vladimir Bilyov' => 'vladimir.bilyov@gmail.com' }
  spec.summary          = 'Credit card scanning for mobile apps'
  spec.social_media_url = 'https://twitter.com/cardio'
#  spec.source           = { :git => 'https://github.com/card-io/card.io-iOS-SDK.git', :tag => "#{spec.version}" }
   spec.source           = { :git => '/tmp/card.io-iOS-SDK_2', :tag => "#{spec.version}" }
  spec.platform         = :ios, '6.1'
  spec.ios.deployment_target = '6.1'
  spec.requires_arc     = true
  spec.source_files     = 'CardIO/*.h'
  spec.frameworks       = 'AVFoundation', 'AudioToolbox', 'CoreMedia', 'CoreVideo', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'Security', 'UIKit'
  spec.libraries        = 'c++'
  spec.resource		= 'CardIO/libCardIO.a.zip'
  spec.vendored_libraries = 'CardIO/libCardIO.a'
  
  def spec.post_install (target)
    system "echo `pwd` > /tmp/e.log"
    spec.system("if [ -f ./Pods/CardIO/CardIO/libCardIO.a.zip ]; then unzip ./Pods/CardIO/CardIO/libCardIO.a.zip -o -d ./Pods/CardIO/CardIO && rm ./Pods/CardIO/CardIO/libCardIO.a.zip; fi")
  end
end