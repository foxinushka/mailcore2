#!/bin/bash

#ndk-build APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk NDK_PROJECT_PATH=.

#ndk-build

echo $(pwd)

swiftc \
    -target armv7-none-linux-androideabi \
    -sdk $ANDROID_NDK/platforms/android-21/arch-arm \
    -I $(pwd)/../build-android/include \
    -I $(pwd)/include \
    -import-objc-header $(pwd)/include/MailCore/swiftmailcore2-Bridging-Header.h \
    -l$(pwd)/libs/armeabi-v7a/libcmailcore.so \
    -L $ANDROID_NDK/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a \
    -L $ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/lib/gcc/arm-linux-androideabi/4.9.x \
    -emit-library \
    -module-name swiftmailcore \
    -Xlinker -soname=libswiftmailcore.so \
    -o ./libs/armeabi-v7a/libswiftmailcore.so \
    ../src/swift/utils/Operation.swift \
    ../src/swift/utils/MailCoreError.swift \
    ../src/swift/abstract/AbstractMessage.swift \
    ../src/swift/abstract/AbstractMessagePart.swift \
    ../src/swift/abstract/AbstractMultipart.swift \
    ../src/swift/abstract/AbstractPart.swift \
    ../src/swift/abstract/Address.swift \
    ../src/swift/abstract/MessageHeader.swift \
    ../src/swift/imap/ImapFolder.swift \
    ../src/swift/imap/ImapFolderInfo.swift \
    ../src/swift/imap/ImapFolderStatus.swift \
    ../src/swift/imap/ImapMessage.swift \
    ../src/swift/imap/ImapMultipart.swift \
    ../src/swift/imap/ImapPart.swift \
    ../src/swift/imap/ImapBaseOperation.swift \
    ../src/swift/imap/ImapOperation.swift \
    ../src/swift/imap/ImapAppendMessageOperation.swift \
    ../src/swift/imap/ImapCopyMessagesOperation.swift \
    ../src/swift/imap/ImapFetchContentOperation.swift \
    ../src/swift/imap/ImapFetchMessagesOperation.swift \
    ../src/swift/imap/ImapFolderInfoOperation.swift \
    ../src/swift/imap/ImapFolderStatusOperation.swift \
    ../src/swift/imap/ImapSearchOperation.swift \
    ../src/swift/imap/ImapIdleOperation.swift \
    ../src/swift/imap/ImapNamespace.swift \
    ../src/swift/imap/ImapSearchExpression.swift \
    ../src/swift/imap/ImapSession.swift \
    ../src/swift/basetypes/Convertible.swift \
    ../src/swift/basetypes/IndexSet+Mailcore.swift \
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
