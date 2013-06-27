#!/bin/sh
# There is a Titanium bug where libstlport_shared.so is being copied into the final module.
# This is a problem because building an app through Titanium tries to re-add another copy of libstlport_shared.so which breaks the build process (signing bug).
# Run this script from the directory this file is contained in to clean up the module after you build it.

unzip dist/co.lanica.calcswig-android-0.1.zip 
find modules -name libstlport_shared.so -exec rm {} \;
rm dist/co.lanica.calcswig-android-0.1.zip
zip -r dist/co.lanica.calcswig-android-0.1.zip modules
rm -rf modules/



