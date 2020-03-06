
Pod::Spec.new do |spec|

  spec.name         = "MyCode"
  spec.version      = "0.02"
  spec.summary      = "cocoapods项目测试"
  spec.description  = "cocoapods项目测试,什么鬼"

  spec.homepage     = "https://github.com/DLSaMa/MyCode"
  # spec.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"



  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  

  spec.author             = { "liuqi" => "lqcoder@163.com" }
 
 
  spec.source       = { :git => "https://github.com/DLSaMa/MyCode.git", :tag => "#{spec.version}" }


 
  spec.source_files  = "Classes", "WhatHell/**/*.{h,m}"
  spec.exclude_files = "Classes/Exclude"




  # spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"

end
