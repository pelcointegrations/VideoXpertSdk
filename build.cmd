@echo off

if NOT DEFINED MAJOR_VER (
  set MAJOR_VER=3
)

if NOT DEFINED MINOR_VER (
  set MINOR_VER=0
)

if NOT DEFINED BUILD_NUMBER (
  set BUILD_NUMBER=0000
)

if NOT DEFINED OUTPUT_PATH (
  set OUTPUT_PATH="%CD%\output"
)

REM Create the output path for the NuGet package if it doesn't exist
if not exist %OUTPUT_PATH% mkdir %OUTPUT_PATH%

REM Create Nuget Package
call Nuget\nuget.exe pack Nuget\VideoXpertSdk.nuspec -Version %MAJOR_VER%.%MINOR_VER%.%BUILD_NUMBER% -OutputDirectory %OUTPUT_PATH%