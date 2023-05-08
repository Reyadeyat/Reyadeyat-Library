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

echo "Building $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/memory -B$PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory -DMODE=$MODE -DBUILD=$BUILD -DPROJECT_PATH=$PROJECT_PATH
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/memory --prefix=$PROJECT_PATH/Reyadeyat-Modules
echo "Completed ..."

if [ "$MODE" = "LIBRARY" ]; then
  readelf -s $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-memory-lib.so
  objdump -T $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-memory-lib.so
else
  echo "Building MODE is INCLUDE no library API shall be generated"
fi
