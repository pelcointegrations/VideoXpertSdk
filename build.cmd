@echo off

if NOT DEFINED BUILD_NUMBER (
  set MAJOR_VER=3
)

if NOT DEFINED BUILD_NUMBER (
  set MINOR_VER=0
)

if NOT DEFINED BUILD_NUMBER (
  set BUILD_NUMBER=0000
)

if NOT DEFINED OUTPUT_PATH (
  set OUTPUT_PATH=%CD%
)

call Nuget\nuget.exe pack Nuget\VideoXpertSdk.nuspec -Version %MAJOR_VER%.%MINOR_VER%.%BUILD_NUMBER% -OutputDirectory %OUTPUT_PATH%