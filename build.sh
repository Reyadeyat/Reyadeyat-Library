#! /bin/sh

if [ -z "$1" ] || [ "${1,,}" = "default" ]; then
  echo "Setting default MODE = INCLUDE-MODE and BUILD-MODE = DEBUG parameters [MODE { LIBRARY, INCLUDE }, BUILD { DEBUG, RELEASE }]"
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
fi

MODE=$DEFAULT_MODE
BUILD=$DEFAULT_BUILD

clear
pwd
echo "-----------------------------------------------------------------------------------"
echo "MODE = $MODE - BUILD = $BUILD"
#cd ../Reyadeyat-Modules/Reyadeyat-Modules

echo "Cleaning Reyadeyat Machine"
rm -rf ./Reyadeyat-Modules/build
rm -rf ./Reyadeyat-Modules/lib

echo "Building ./Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0"
echo "Configuration ..."
cmake ./Reyadeyat-Modules/src/reyadeyat/memory/memory.0.0.0 -B./Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0
echo "Buildinging ..."
cmake --build ./Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0 --target all -j 4
echo "Installing ..."
cmake --install ./Reyadeyat-Modules/build/reyadeyat/memory/memory.0.0.0 --prefix=./Reyadeyat-Modules
echo "Completed ..."
readelf -s ./Reyadeyat-Modules/lib/reyadeyat-memory-lib.0.0.0.so
objdump -T ./Reyadeyat-Modules/lib/reyadeyat-memory-lib.0.0.0.so

echo "Building reyadeyat-memory-lib/src/reyadeyat/memory MODE = $MODE - BUILD = $BUILD"
echo "Configuration ..."
cmake ./Reyadeyat-Modules -B./Reyadeyat-Modules/build/reyadeyat/memory -DMODE=$MODE -DBUILD=$BUILD
echo "Buildinging ..."
cmake --build ./Reyadeyat-Modules/build/reyadeyat/memory --target all -j 4
echo "Installing ..."
cmake --install ./Reyadeyat-Modules/build/reyadeyat/memory --prefix=./Reyadeyat-Modules
echo "Completed ..."
readelf -s ./Reyadeyat-Modules/lib/reyadeyat-memory-lib.so
objdump -T ./Reyadeyat-Modules/lib/reyadeyat-memory-lib.so

echo "Cleaning Reyadeyat-Executables"
rm -rf ./Reyadeyat-Executables/bin
rm -rf ./Reyadeyat-Executables/build
rm -rf ./Reyadeyat-Executables/include
rm -rf ./Reyadeyat-Executables/lib

echo "Building Reyadeyat-Executables MODE = $MODE - BUILD = $BUILD"
echo "Configuration ..."
cmake ./Reyadeyat-Executables -B./Reyadeyat-Executables/build -DMODE=$MODE -DBUILD=$BUILD
echo "Buildinging ..."
cmake --build ./Reyadeyat-Executables/build --target all -j 4
echo "Installing ..."
cmake --install ./Reyadeyat-Executables/build --prefix=./Reyadeyat-Executables/
echo "Completed ..."
read -p "Run Program? (y/n) " CHOICE
if [ "$CHOICE" = "y" ] || [ "$CHOICE" = "yes" ]; then
  echo "Done, Programm is now running ..."
  ./Reyadeyat-Executables/bin/reyadeyat-c
  echo "Done, Programm has finished executing ..."
else
  echo "Done, Programm doesn't run ..."
fi
