#!/bin/bash

# Copy resources
adb shell rm -rf /data/local/tmp/MailCorePackageTests//resources
adb shell mkdir -p /data/local/tmp/MailCorePackageTests//resources
adb push ../unittest/data/ /data/local/tmp/MailCorePackageTests//resources