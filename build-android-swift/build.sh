#!/bin/bash

#ndk-build APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk NDK_PROJECT_PATH=.

#ndk-build

echo "Build mailcore2"

swiftc \
    -target armv7-none-linux-androideabi \
    -sdk $ANDROID_NDK/platforms/android-21/arch-arm \
    -I $(pwd)/include \
    -import-objc-header $(pwd)/include/MailCore/swiftmailcore2-Bridging-Header.h \
    -l$(pwd)/libs/armeabi-v7a/libcmailcore.so \
    -L $ANDROID_NDK/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a \
    -L $ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/lib/gcc/arm-linux-androideabi/4.9.x \
    -emit-library \
    -module-name SwiftMailCore \
    -Xlinker -soname=libswiftmailcore.so \
    -o ./libs/armeabi-v7a/libswiftmailcore.so \
    -emit-module \
    ../src/swift/utils/Operation.swift \
    ../src/swift/utils/MailCoreError.swift \
    ../src/swift/abstract/AbstractMessage.swift \
    ../src/swift/abstract/AbstractMessagePart.swift \
    ../src/swift/abstract/AbstractMultipart.swift \
    ../src/swift/abstract/AbstractPart.swift \
    ../src/swift/abstract/Address.swift \
    ../src/swift/abstract/MessageHeader.swift \
    ../src/swift/abstract/AbstractMessageRendererCallback.swift \
    ../src/swift/abstract/HtmlRendererDelegate.swift \
    ../src/swift/abstract/HtmlRendererIMAPDelegate.swift \
    ../src/swift/imap/IMAPFolder.swift \
    ../src/swift/imap/IMAPFolderInfo.swift \
    ../src/swift/imap/IMAPFolderStatus.swift \
    ../src/swift/imap/IMAPMessage.swift \
    ../src/swift/imap/IMAPMultipart.swift \
    ../src/swift/imap/IMAPPart.swift \
    ../src/swift/imap/IMAPBaseOperation.swift \
    ../src/swift/imap/IMAPOperation.swift \
    ../src/swift/imap/IMAPAppendMessageOperation.swift \
    ../src/swift/imap/IMAPCopyMessagesOperation.swift \
    ../src/swift/imap/IMAPFetchContentOperation.swift \
    ../src/swift/imap/IMAPFetchMessagesOperation.swift \
    ../src/swift/imap/IMAPFolderInfoOperation.swift \
    ../src/swift/imap/IMAPFolderStatusOperation.swift \
    ../src/swift/imap/IMAPSearchOperation.swift \
    ../src/swift/imap/IMAPIdleOperation.swift \
    ../src/swift/imap/IMAPNamespace.swift \
    ../src/swift/imap/IMAPSearchExpression.swift \
    ../src/swift/imap/IMAPFetchFoldersOperation.swift \
    ../src/swift/imap/IMAPFetchContentToFileOperation.swift \
    ../src/swift/imap/IMAPFetchNamespaceOperation.swift \
    ../src/swift/imap/IMAPMoveMessagesOperation.swift \
    ../src/swift/imap/IMAPFetchParsedContentOperation.swift \
    ../src/swift/imap/IMAPMessageRenderingOperation.swift \
    ../src/swift/imap/IMAPCheckAccountOperation.swift \
    ../src/swift/imap/IMAPCapabilityOperation.swift \
    ../src/swift/imap/IMAPQuotaOperation.swift \
    ../src/swift/imap/IMAPCustomCommandOperation.swift \
    ../src/swift/imap/IMAPSession.swift \
    ../src/swift/basetypes/Convertible.swift \
    ../src/swift/basetypes/IndexSet.swift \
    ../src/swift/basetypes/String+Mailcore.swift \
    ../src/swift/basetypes/Dictionary+Mailcore.swift \
    ../src/swift/basetypes/Data+Mailcore.swift \
    ../src/swift/basetypes/Array+Mailcore.swift \
    ../src/swift/basetypes/UInt32+Mailcore.swift \
    ../src/swift/smtp/SmtpOperation.swift \
    ../src/swift/smtp/SmtpSendOperation.swift \
    ../src/swift/smtp/SmtpSession.swift \
    ../src/swift/rfc822/Attachment.swift \
    ../src/swift/rfc822/MessageBuilder.swift \
    ../src/swift/rfc822/MessageParser.swift \

echo "Build tests"

swiftc \
    -target armv7-none-linux-androideabi \
    -sdk $ANDROID_NDK/platforms/android-21/arch-arm \
    -I $(pwd)/libs/armeabi-v7a \
    -l$(pwd)/libs/armeabi-v7a/libswiftmailcore.so \
    -module-link-name SwiftMailCore \
    -L $(pwd)/libs/armeabi-v7a \
    -L $ANDROID_NDK/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a \
    -L $ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/lib/gcc/arm-linux-androideabi/4.9.x \
    -emit-library \
    -module-name TestSwiftMailCore \
    -Xlinker -soname=libTestSwiftMailCore.so \
    -o ./libs/armeabi-v7a/libTestSwiftMailCore.so \
    ./test/XCTestCase.swift \
    ../build-mac/swiftmailcore2Test/unittest.swift \
    ./test/test.swift \

#echo "Run tests"

# Copy swift bundle to /data/local/tmp on device (can be ignored if it's already copied)
# for i in ~/swift-source/bundle/*.so; do echo $i; adb push "$i" /data/local/tmp/; done;

# Copy gnu stl
#adb push ./libs/armeabi-v7a/libgnustl_shared.so /data/local/tmp
# Copy mailcore2 C++
#adb push ./libs/armeabi-v7a/libMailCore.so /data/local/tmp
# Copy mailcore2 C wrapper for C++ API
#adb push ./libs/armeabi-v7a/libcmailcore.so /data/local/tmp
# Copy mailcore 2 Swift wrapper for C API
#adb push ./libs/armeabi-v7a/libswiftmailcore.so /data/local/tmp
# Copy tests for SwiftMailCore
#adb push ./libs/armeabi-v7a/testSwiftMailCore /data/local/tmp
# Run tests
#adb shell LD_LIBRARY_PATH=/data/local/tmp /data/local/tmp/testSwiftMailCore






