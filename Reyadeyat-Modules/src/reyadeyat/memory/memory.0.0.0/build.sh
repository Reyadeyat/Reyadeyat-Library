#! /bin/sh

if [ -z "$1" ]; then
  echo "Pass MODE { LIBRARY, INCLUDE }"
  exit 1
fi
if [ -z "$2" ]; then
  echo "Pass BUILD { DEBUG, RELEASE }"
  exit 1
fi

if [ -z "$3" ]; then
  echo "Pass PROJECT_PATHs"
  exit 1
fi

MODE=$1
BUILD=$2
PROJECT_PATH=$3

echo "Building $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0 MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0 -B$PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0 -DMODE=$MODE -DBUILD=$BUILD -DPROJECT_PATH=$PROJECT_PATH
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0 --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0 --prefix=$PROJECT_PATH/Reyadeyat-Modules
echo "Completed ..."
readelf -s $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-memory-lib.0.0.0.so
objdump -T $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-memory-lib.0.0.0.so