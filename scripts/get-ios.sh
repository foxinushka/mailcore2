#!/bin/sh

pushd "`dirname "$0"`" > /dev/null
scriptpath="`pwd`"
popd > /dev/null

. "$scriptpath/include.sh/build-dep.sh"

deps="ctemplate-ios tidy-html5-ios"
for dep in $deps ; do
  name="$dep"
  get_prebuilt_dep
done

#Currently there is no prebuild version of release we need. So we will compile it
deps="libetpan-ios"
for dep in $deps ; do
  name="$dep"
  sh "$scriptpath/build-libetpan-ios.sh"
done

deps="ctemplate-ios libetpan-ios tidy-html5-ios" #restoring original dependencies list
deps+=" libsasl-ios"

if test "x$CONFIGURATION_BUILD_DIR" != x ; then
  mkdir -p "$CONFIGURATION_BUILD_DIR"
  cd "$scriptpath/../Externals"
  for dep in $deps ; do
    if test -d "$dep" ; then
      if test -d "$dep"/lib ; then
        rsync -a "$dep"/lib/ "$CONFIGURATION_BUILD_DIR"
      fi
      if test -d "$dep"/include ; then
        rsync -a "$dep"/include/ "$CONFIGURATION_BUILD_DIR/include/"
      fi
    fi
  done
fi
