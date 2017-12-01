Pod::Spec.new do |s|
  s.name         = "RSMMailCore"
  s.version      = "2.0.beta.1"
  s.summary      = "SparkCore is absolutely awesome sanctuary of all the messages related business logic of Spark"
  s.description  = <<-DESC
                    Amen
                   DESC

  s.homepage = 'https://git.readdle.com/spark/spark-core' 
  s.license      = { :type => 'Copyright 2017 Readdle Inc.', :text => 'Copyright 2017 Readdle Inc.' }

  s.author       = { "Viktor Gedzenko" => "fox@readdle.com" }
  s.source       = { :git => "https://github.com/foxinushka/mailcore2.git", :tag => "#{s.version}"}
  s.platforms    = { :ios => "9.0", :osx => "10.10" }  

  s.framework  = "Foundation", "Security"

  s.ios.xcconfig = { "HEADER_SEARCH_PATHS" => "\"$(inherited)\" \"$(SDKROOT)/usr/include/libxml2\" \"$(PODS_TARGET_SRCROOT)/Externals/ctemplate-ios/include/\" \"$(PODS_TARGET_SRCROOT)/Externals/include/icu4c/include/\" \"$(PODS_TARGET_SRCROOT)/Externals/libetpan-ios/include/\" \"$(PODS_TARGET_SRCROOT)/Externals/libsasl-ios/include/\" \"$(SDKROOT)/usr/include/\" \"$(PODS_TARGET_SRCROOT)/src/core/basetypes/icu-ucsdet/include/\"",
    "SWIFT_INCLUDE_PATHS" => "\"$(PODS_TARGET_SRCROOT)/build-mac/CMailCore\" \"$(PODS_TARGET_SRCROOT)/Externals/libetpan-ios/include/\"",
    "OTHER_CPLUSPLUSFLAGS" => "$(inherited) $(OTHER_CFLAGS) -DSWIFT"
  }


  s.osx.xcconfig = { "HEADER_SEARCH_PATHS" => "\"$(inherited)\" \"$(SDKROOT)/usr/include/libxml2\" \"$(PODS_TARGET_SRCROOT)/Externals/ctemplate-osx/include/\" \"$(PODS_TARGET_SRCROOT)/Externals/include/icu4c/include/\" \"$(PODS_TARGET_SRCROOT)/Externals/libetpan-osx/include/\" \"$(PODS_TARGET_SRCROOT)/src/core/basetypes/icu-ucsdet/include/\"",
    "SWIFT_INCLUDE_PATHS" => "\"$(PODS_TARGET_SRCROOT)/build-mac/CMailCore\" \"$(PODS_TARGET_SRCROOT)/Externals/libetpan-osx/include/\"",
    "OTHER_CPLUSPLUSFLAGS" => "$(inherited) $(OTHER_CFLAGS) -DSWIFT"
  }


  s.prepare_command = <<-CMD
    scripts/get-mac.sh
    scripts/get-ios.sh
    sed -i '' 's#<tidy.h>#<tidy/tidy.h>#g' ./src/core/basetypes/MCHTMLCleaner.cpp
    sed -i '' 's#<buffio.h>#<tidy/buffio.h>#g' ./src/core/basetypes/MCHTMLCleaner.cpp
    mv src/core/zip/MiniZip/zip.h src/core/zip/MiniZip/rsmmczip.h
    sed -i '' 's#"zip.h"#"rsmmczip.h"#g' src/core/zip/MCZip.cpp 
    sed -i '' 's#"zip.h"#"rsmmczip.h"#g' src/core/zip/MiniZip/zip.c  
  CMD
  
  s.dependency 'RDlog4cocoa'
  s.dependency 'RDTidyHtml5', '5.4.0-fix-a-tag'
  s.dependency 'RDSQLite3/icu', '3.14.2-framework'

  s.default_subspec = 'core' 
  s.requires_arc = false

  s.header_dir = 'MailCore'
  s.libraries = "xml2", "iconv", "z", "resolv", "c++", "objc"

  s.subspec 'core' do |ss|
    ss.source_files = "src/c/**/*.{h,cpp}",
      "src/core/**/*.{h,cpp,c,mm}",
      "src/async/**/*.{h,cpp}",
      "src/objc/utils/MCOObjectWrapper.{mm,h}",
      "src/objc/utils/NSObject+MCO.h",
      "src/swift/**/*.swift"
      
    ss.ios.source_files = "build-mac/iOS/MailCore.h"
    ss.osx.source_files = "build-mac/OSX/MailCore.h"
             
    ss.exclude_files = "src/core/zip/MiniZip/iowin32.{h,c}",  
      "src/core/zip/MiniZip/mini*",
      "src/core/zip/MiniZip/mz*",
      "src/core/basetypes/**/*Win32*.cpp",
      "src/core/basetypes/**/*Android*",
      "src/core/basetypes/**/*GTK*",
      "src/core/basetypes/MCDataMac.mm",
      "src/core/rfc822/MCMessageParserMac.mm",
      "src/swift/utils/AndroidShim.swift"
    
    ss.public_header_files = "src/c/**/*.h"
    ss.ios.public_header_files = "build-mac/iOS/MailCore.h"
    ss.osx.public_header_files = "build-mac/OSX/MailCore.h"
    
    ss.private_header_files = "src/c/abstract/CAbstractMessageRendererCallbackWrapper.h",
      "src/c/CBase+Private.h",
      "src/c/CCore.h"
    ss.preserve_paths = 
      "build-mac/CMailCore/**/*.{h,modulemap}",
      "src/core/basetypes/include/unicode/*.h"

    ss.resources = "resources/providers.json"
    ss.dependency "RSMMailCore/etpan"
    ss.dependency "RSMMailCore/ctemplate"
    ss.dependency "RSMMailCore/sasl2"
  end

  s.subspec 'etpan' do |ss| 
    ss.ios.vendored_libraries = "Externals/libetpan-ios/lib/libetpan-ios.a"
    ss.ios.private_header_files = "Externals/libetpan-ios/include/libetpan/*.h"
    ss.ios.source_files = "Externals/libetpan-ios/include/libetpan/*.h"
    ss.ios.preserve_paths = "Externals/libetpan-ios/include/libetpan/*.h"

    ss.osx.vendored_libraries = "Externals/libetpan-osx/lib/libetpan.a"
    ss.osx.private_header_files = "Externals/libetpan-osx/include/libetpan/*.h"
    ss.osx.source_files = "Externals/libetpan-osx/include/libetpan/*.h"
    ss.osx.preserve_paths = "Externals/libetpan-osx/include/libetpan/*.h"
  end 

  s.subspec 'sasl2' do |ss| 
    ss.vendored_libraries = "Externals/libsasl-ios/lib/libsasl2.a"
    ss.private_header_files = "Externals/libsasl-ios/include/sasl/*.h"
    ss.source_files = "Externals/libsasl-ios/include/sasl/*.h"
    ss.preserve_paths = "Externals/libsasl-ios/include/sasl/*.h"
  end 

  s.subspec 'ctemplate' do |ss| 
    ss.ios.vendored_libraries = "Externals/ctemplate-ios/lib/libctemplate-ios.a"
    ss.ios.private_header_files = "Externals/ctemplate-ios/include/ctemplate/*.h"
    ss.ios.source_files = "Externals/ctemplate-ios/include/ctemplate/*.h"
    ss.ios.preserve_paths = "Externals/ctemplate-ios/include/ctemplate/*.h"

    ss.osx.vendored_libraries = "Externals/ctemplate-osx/lib/libctemplate.a"
    ss.osx.private_header_files = "Externals/ctemplate-osx/include/ctemplate/*.h"
    ss.osx.source_files = "Externals/ctemplate-osx/include/ctemplate/*.h"
    ss.osx.preserve_paths = "Externals/ctemplate-osx/include/ctemplate/*.h"
  end 
end
