#! /bin/sh

echo "Running script $(realpath "$0")"

echo "Building $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/utilities.0.0.0 MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Modules/src/reyadeyat/utilities/utilities.0.0.0 -B./Reyadeyat-Modules/build/reyadeyat/utilities/utilities.0.0.0 -DMODE="$MODE" -DBUILD="$BUILD" -DPROJECT_PATH="$PROJECT_PATH" -DCMAKE_C_COMPILER="$CMAKE_C_COMPILER" -DCMAKE_C_FLAGS="$CMAKE_C_FLAGS" -DCMAKE_C_FLAGS_DEBUG="$CMAKE_C_FLAGS_DEBUG" -DCMAKE_C_FLAGS_MINSIZEREL="$CMAKE_C_FLAGS_MINSIZEREL" -DCMAKE_C_FLAGS_RELEASE="$CMAKE_C_FLAGS_RELEASE" -DCMAKE_C_FLAGS_RELWITHDEBINFO="$CMAKE_C_FLAGS_RELWITHDEBINFO"
echo "Buildinging ..."
cmake --build ./Reyadeyat-Modules/build/reyadeyat/utilities/utilities.0.0.0 --target all -j 4
echo "Installing ..."
cmake --install ./Reyadeyat-Modules/build/reyadeyat/utilities/utilities.0.0.0 --prefix=./Reyadeyat-Modules
echo "Completed ..."
readelf -s ./Reyadeyat-Modules/lib/reyadeyat-utilities-lib.0.0.0.so
objdump -T ./Reyadeyat-Modules/lib/reyadeyat-utilities-lib.0.0.0.so
