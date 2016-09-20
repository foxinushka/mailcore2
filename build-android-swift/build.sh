#!/bin/bash

#ndk-build APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk NDK_PROJECT_PATH=.

#ndk-build

echo $(pwd)

swiftc \
    -target armv7-none-linux-androideabi \
    -sdk $ANDROID_NDK/platforms/android-21/arch-arm \
    -I $(pwd)/include \
    -import-objc-header $(pwd)/include/MailCore/CCore.h \
    -l$(pwd)/libs/armeabi-v7a/libcmailcore.so \
    -L $ANDROID_NDK/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a \
    -L $ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/lib/gcc/arm-linux-androideabi/4.9.x \
    -emit-library \
    -module-name swiftmailcore \
    -Xlinker -soname=libswiftmailcore.so \
    -o ./libs/armeabi-v7a/libswiftmailcore.so \
    ../src/swift/imap/ImapSession.swift \
    ../src/swift/imap/ImapOperation.swift \
    ../src/swift/imap/ImapNamespace.swift \
    ../src/swift/imap/ImapAppendMessageOperation.swift \
    ../src/swift/imap/ImapFetchContentOperation.swift \
    ../src/swift/imap/ImapFetchMessagesOperation.swift \
    ../src/swift/imap/ImapCopyMessagesOperation.swift \
    ../src/swift/imap/ImapFolderInfoOperation.swift \
    ../src/swift/imap/ImapFolderStatusOperation.swift \
    ../src/swift/imap/ImapSearchExpression.swift \
    ../src/swift/imap/ImapSearchOperation.swift \
    ../src/swift/basetypes/Converter.swift \
    ../src/swift/basetypes/IndexSet.swift \
