#! /bin/sh

echo "Cleaning Reyadeyat-Executables"
rm -rf $PROJECT_PATH/Reyadeyat-Executables/bin
rm -rf $PROJECT_PATH/Reyadeyat-Executables/build
rm -rf $PROJECT_PATH/Reyadeyat-Executables/include
rm -rf $PROJECT_PATH/Reyadeyat-Executables/lib

echo "Building $PROJECT_PATH/Reyadeyat-Library/src MODE = $MODE - BUILD = $BUILD - PROJECT_PATH = $PROJECT_PATH"
echo "Configuration ..."
cmake $PROJECT_PATH/Reyadeyat-Executables -B$PROJECT_PATH/Reyadeyat-Executables/build -DMODE="$MODE" -DBUILD="$BUILD" -DPROJECT_PATH="$PROJECT_PATH" -DCMAKE_C_COMPILER="$CMAKE_C_COMPILER" -DCMAKE_C_FLAGS="$CMAKE_C_FLAGS" -DCMAKE_C_FLAGS_DEBUG="$CMAKE_C_FLAGS_DEBUG" -DCMAKE_C_FLAGS_MINSIZEREL="$CMAKE_C_FLAGS_MINSIZEREL" -DCMAKE_C_FLAGS_RELEASE="$CMAKE_C_FLAGS_RELEASE" -DCMAKE_C_FLAGS_RELWITHDEBINFO="$CMAKE_C_FLAGS_RELWITHDEBINFO"
echo "Buildinging ..."
cmake --build $PROJECT_PATH/Reyadeyat-Executables/build --target all -j 4
echo "Installing ..."
cmake --install $PROJECT_PATH/Reyadeyat-Executables/build --prefix=$PROJECT_PATH/Reyadeyat-Executables/
echo "Completed ..."
echo "Finished $PROJECT_PATH/Reyadeyat-Executables/bin/reyadeyat-c"
read -p "Run Program? (y/n) " CHOICE
if [ "$CHOICE" = "y" ] || [ "$CHOICE" = "yes" ]; then
  read -p "Clear consol? " CHOICE
  if [ "$CHOICE" = "y" ] || [ "$CHOICE" = "yes" ]; then
    clear
  fi
  echo "Done, Programm is now running ..."
  $PROJECT_PATH/Reyadeyat-Executables/bin/reyadeyat-c
  echo "Done, Programm has finished executing ..."
else
  echo "Done, Programm doesn't run ..."
fi
