#! /bin/sh

echo "Running script $(realpath "$0")"

echo "Building $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file -B$PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file -DMODE="$MODE" -DBUILD="$BUILD" -DPROJECT_PATH="$PROJECT_PATH" -DCMAKE_C_COMPILER="$CMAKE_C_COMPILER" -DCMAKE_C_FLAGS="$CMAKE_C_FLAGS" -DCMAKE_C_FLAGS_DEBUG="$CMAKE_C_FLAGS_DEBUG" -DCMAKE_C_FLAGS_MINSIZEREL="$CMAKE_C_FLAGS_MINSIZEREL" -DCMAKE_C_FLAGS_RELEASE="$CMAKE_C_FLAGS_RELEASE" -DCMAKE_C_FLAGS_RELWITHDEBINFO="$CMAKE_C_FLAGS_RELWITHDEBINFO"
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file --prefix=$PROJECT_PATH/Reyadeyat-Modules
echo "Completed ..."

if [ "$MODE" = "LIBRARY" ]; then
  readelf -s $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-file-lib.so
  objdump -T $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-file-lib.so
else
  echo "Building MODE is INCLUDE no library API shall be generated"
fi

