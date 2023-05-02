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

echo "Cleaning Reyadeyat-Executables"
rm -rf $PROJECT_PATH/Reyadeyat-Executables/bin
rm -rf $PROJECT_PATH/Reyadeyat-Executables/build
rm -rf $PROJECT_PATH/Reyadeyat-Executables/include
rm -rf $PROJECT_PATH/Reyadeyat-Executables/lib

echo "Building $PROJECT_PATH/Reyadeyat-Library/src MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Executables -B$PROJECT_PATH/Reyadeyat-Executables/build -DMODE=$MODE -DBUILD=$BUILD  -DPROJECT_PATH=$PROJECT_PATH
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Executables/build --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Executables/build --prefix=$PROJECT_PATH/Reyadeyat-Executables/
echo "Completed ..."
echo "Finished $PROJECT_PATH/Reyadeyat-Executables/bin/reyadeyat-c"
read -p "Run Program? (y/n) " CHOICE
if [ "$CHOICE" = "y" ] || [ "$CHOICE" = "yes" ]; then
  echo "Done, Programm is now running ..."
  $PROJECT_PATH/Reyadeyat-Executables/bin/reyadeyat-c
  echo "Done, Programm has finished executing ..."
else
  echo "Done, Programm doesn't run ..."
fi
