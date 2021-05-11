#!/bin/sh
set -x

pushd "`dirname "$0"`" > /dev/null
scriptpath="`pwd`"
popd > /dev/null

. "$scriptpath/include.sh/build-dep.sh"

url="git@github.com:readdle/libetpan.git"
rev=cbbac53faaa62f34d4f0c9361e0438f354793308
name="libetpan-ios"
xcode_target="libetpan ios"
xcode_project="libetpan.xcodeproj"
library="libetpan-ios.a"
xcframework="libetpan-ios.xcframework"
embedded_deps="libsasl-ios"

build_git_ios
