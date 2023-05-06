#! /bin/sh

if [ -z "$1" ] || [ "${1,,}" = "default" ]; then
  echo "Setting default MODE = INCLUDE and BUILD = DEBUG parameters [MODE { LIBRARY, INCLUDE }, BUILD { DEBUG, RELEASE }]"
  DEFAULT_MODE="INCLUDE"
  DEFAULT_BUILD="DEBUG"
else
  if [ -z "$1" ]; then
    echo "Pass MODE { LIBRARY, INCLUDE }"
    exit 1
  fi
  if [ -z "$2" ]; then
    echo "Pass BUILD { DEBUG, RELEASE }"
    exit 1
  fi
  DEFAULT_MODE="$1"
  DEFAULT_BUILD="$2"
fi

MODE=$DEFAULT_MODE
BUILD=$DEFAULT_BUILD

PROJECT_PATH=$(pwd)

clear
pwd
echo "-----------------------------------------------------------------------------------"

#Reyadeyat-Library
echo "Building Reyadeyat-Library MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"

#Reyadeyat-Modules
echo "Building Reyadeyat Modules"

#File Module
echo "Building Reyadeyat Modules - File 0.0.0"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/file.0.0.0/build.sh $MODE $BUILD $PROJECT_PATH
echo "Building Reyadeyat Modules - File API"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/build.sh $MODE $BUILD $PROJECT_PATH

#Memory Module
echo "Building Reyadeyat Modules - Memory 0.0.0"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0/build.sh $MODE $BUILD $PROJECT_PATH
echo "Building Reyadeyat Modules - Memory API"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/build.sh $MODE $BUILD $PROJECT_PATH

#Utilities Module
echo "Building Reyadeyat Modules - Utilities 0.0.0"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/utilities.0.0.0/build.sh $MODE $BUILD $PROJECT_PATH
echo "Building Reyadeyat Modules - Utilities API"
$PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/build.sh $MODE $BUILD $PROJECT_PATH

#Executables
echo "Building Reyadeyat-Executables"

$PROJECT_PATH/Reyadeyat-Executables/src/build.sh $MODE $BUILD $PROJECT_PATH
