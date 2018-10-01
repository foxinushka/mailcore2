#!/bin/bash

export TOOLCHAINS=swift

# Force clean
rm -rf .build Package.resolved test.log

rm -rf ./build-android-swift/third-party
rm -rf ./build-android-swift/include
rm -rf ./build-android-swift/mailcore2-android-*.zip
rm -rf ./build-android-swift/cmake-build
rm -rf ./build-android-swift/libs
rm -rf ./build-android-swift/obj

# Build extrenal
swift-install

# Generate LinuxMain.swift
sourcery

# Build
pass_to_swiftc="-Xbuild -Xswiftc -Xbuild"
pass_to_frontend="$pass_to_swiftc -Xfrontend $pass_to_swiftc"

swift-test --deploy \
    $pass_to_frontend -experimental-disable-objc-attr

# Test
X_ANDROID_TZ="America/Los_Angeles" \
    swift-test --just-run | tee test.log

return_code=${PIPESTATUS[0]}
cat test.log | xcpretty --report junit

exit $return_code
