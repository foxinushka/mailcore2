#!/bin/bash

#echo "Run tests"

# Copy swift bundle to /data/local/tmp on device (can be ignored if it's already copied)
# for i in ~/swift-source/bundle/*.so; do echo $i; adb push "$i" /data/local/tmp/; done;

# Copy gnu stl
adb push $ANDROID_NDK/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/libgnustl_shared.so /data/local/tmp
# Copy mailcore2 C++
adb push ./libs/armeabi-v7a/libMailCore.so /data/local/tmp
# Copy mailcore2 C wrapper for C++ API
adb push ./libs/armeabi-v7a/libcmailcore.so /data/local/tmp
# Copy mailcore 2 Swift wrapper for C API
adb push ./libs/armeabi-v7a/libswiftmailcore.so /data/local/tmp
# Copy tests for SwiftMailCore
adb push ./libs/armeabi-v7a/testSwiftMailCore /data/local/tmp
# Run tests
adb shell LD_LIBRARY_PATH=/data/local/tmp /data/local/tmp/testSwiftMailCore
