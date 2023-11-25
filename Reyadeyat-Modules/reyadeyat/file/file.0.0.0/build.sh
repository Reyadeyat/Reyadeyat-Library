#! /bin/sh

echo "Running script $(realpath "$0")"

echo "Building $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/file.0.0.0 MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/file/file.0.0.0 -B$PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file/file.0.0.0 -DMODE="$MODE" -DBUILD="$BUILD" -DPROJECT_PATH="$PROJECT_PATH" -DCMAKE_C_COMPILER="$CMAKE_C_COMPILER" -DCMAKE_C_FLAGS="$CMAKE_C_FLAGS" -DCMAKE_C_FLAGS_DEBUG="$CMAKE_C_FLAGS_DEBUG" -DCMAKE_C_FLAGS_MINSIZEREL="$CMAKE_C_FLAGS_MINSIZEREL" -DCMAKE_C_FLAGS_RELEASE="$CMAKE_C_FLAGS_RELEASE" -DCMAKE_C_FLAGS_RELWITHDEBINFO="$CMAKE_C_FLAGS_RELWITHDEBINFO"
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file/file.0.0.0 --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Modules/build/reyadeyat/file/file.0.0.0 --prefix=$PROJECT_PATH/Reyadeyat-Modules
echo "Completed ..."
readelf -s $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-file-lib.0.0.0.so
objdump -T $PROJECT_PATH/Reyadeyat-Modules/lib/reyadeyat-file-lib.0.0.0.so
