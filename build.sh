#! /bin/sh
clear
echo "########### Running Main script $(realpath "$0")"

PROJECT_PATH=$(pwd)
echo "########### Current Build Path $PROJECT_PATH"
source $PROJECT_PATH/build-main-validate.sh
returned_code=$?

if [ $returned_code = 1 ]; then
  echo "########### build-main-validate.sh failed, exit..."
  exit 1;
fi

MODE=$DEFAULT_MODE
BUILD=$DEFAULT_BUILD

clear
pwd
echo "-----------------------------------------------------------------------------------"

#CMAKE_C_COMPILER="/usr/bin/clang"
CMAKE_C_COMPILER="/usr/bin/gcc"
if [ $BUILD == "DEBUG" ]; then
    CMAKE_C_FLAGS="-m64 -g -Wall -Werror -fPIC -fPIE -pie -fstack-protector --save-temps -x 'none'"
    CMAKE_C_FLAGS_DEBUG="-g"
else
    CMAKE_C_FLAGS="-m64 -Wall -Werror -fPIC -fPIE -pie -O2 -fstack-protector --save-temps -x 'none'"
    CMAKE_C_FLAGS_MINSIZEREL="-Os -DNDEBUG"
    CMAKE_C_FLAGS_RELEASE="-O2 -DNDEBUG"
    CMAKE_C_FLAGS_RELWITHDEBINFO="-O2 -g"
fi

#Reyadeyat-Library
echo "########### Building Reyadeyat-Library MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"

#Reyadeyat-Modules
echo "########### Cleaning Reyadeyat-Module"

rm -rf $PROJECT_PATH/Reyadeyat-Executable-Core/bin
rm -rf $PROJECT_PATH/Reyadeyat-Executable-Core/build
rm -rf $PROJECT_PATH/Reyadeyat-Executable-Core/lib

rm -rf $PROJECT_PATH/Reyadeyat-Module/bin
rm -rf $PROJECT_PATH/Reyadeyat-Module/build
rm -rf $PROJECT_PATH/Reyadeyat-Module/lib

if [ $BUILD == "LIIBRARY" ]; then
  echo "########### Building Reyadeyat Library Modules Mode"

  #Algorithms Module
  echo "########### Building Reyadeyat Modules - Algorithms 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/algorithms/algorithms.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - Algorithms API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/algorithms/build.sh

  #Data Structures Module
  echo "########### Building Reyadeyat Modules - Data Structures 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/data-structures/data-structures.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - Data Structures API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/data-structures/build.sh

  #File Module
  echo "########### Building Reyadeyat Modules - File 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/file.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - File API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/build.sh

  #Memory Module
  echo "########### Building Reyadeyat Modules - Memory 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - Memory API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/build.sh

  #Utilities Module
  echo "########### Building Reyadeyat Modules - Utilities 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/utilities.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - Utilities API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/build.sh

  #Computer Module
  echo "########### Building Reyadeyat Modules - Computer 0.0.0"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/computer/computer.0.0.0/build.sh
  echo "########### Building Reyadeyat Modules - Computer API"
  source $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/computer/build.sh
else
  echo "########### Building Reyadeyat Include Modules Mode"
fi
#Executable-Core
echo "########### Building Reyadeyat-Executable-Core"
source $PROJECT_PATH/Reyadeyat-Executable-Core/build.sh
