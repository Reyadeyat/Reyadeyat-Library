cmake_minimum_required(VERSION 3.27)
project(reyadeyat-computer-lib.0.0.0 C)
#set(PREFIX "")
#set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
#set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 23)
message("Parameters MODE = ${MODE} - BUILD = ${BUILD} - PROJECT_PATH = ${PROJECT_PATH}")
if ("${BUILD}" STREQUAL "DEBUG")
    message("Compiling DEBUG mode")
    set(CMAKE_BUILD_TYPE Debug)
elseif ("${BUILD}" STREQUAL "RELEASE")
    message("Compiling RELESE mode")
    set(CMAKE_BUILD_TYPE Release)
endif()
message("CMAKE_C_COMPILER ${CMAKE_C_COMPILER}")
message("CMAKE_C_FLAGS ${CMAKE_C_FLAGS}")
message("CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_MINSIZEREL ${CMAKE_C_FLAGS_MINSIZEREL}")
message("CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE}")
message("CMAKE_C_FLAGS_RELWITHDEBINFO ${CMAKE_C_FLAGS_RELWITHDEBINFO}")

set(SOURCE_DIRECTORY ".")
set(SOURCE_DIRECTORY_LOG "../../log")
file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c" "${SOURCE_DIRECTORY_LOG}/*.c")
message("source files in dir: ${SOURCE_DIRECTORY}")
foreach(SOURCE_FILE IN LISTS SOURCE_FILE_LIST)
    message("source file: ${SOURCE_FILE}")
endforeach()

set(INCLUDE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Modules")
INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY})

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})

set_target_properties("${PROJECT_NAME}" PROPERTIES LINKER_LANGUAGE C)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
