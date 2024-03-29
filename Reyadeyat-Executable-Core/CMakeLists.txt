cmake_minimum_required(VERSION 3.26)
include(${PROJECT_PATH}/CMakeFunctions.txt)
project(reyadeyat-c C ASM)
#set(PREFIX "")
#set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
#set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 23)

set(TENSORFLOW_INCLUDE_DIRECTORY "/linux/tensorflow/tensorflow/include")
set(TENSORFLOW_LIB_DIRECTORY "/linux/tensorflow/tensorflow/lib")

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

message("Defined User MODE is ${MODE}")
if (NOT DEFINED MODE)
    message("NO MODE defined, defaulting MODE to mode INCLUDE")
    #SET(MODE "LIBRARY")
    SET(MODE "INCLUDE")
endif()
if ("${MODE}" STREQUAL "LIBRARY")
    message("MODE is: LIBRARY")
    add_compile_definitions(MODE=1)
    #Copy Include Directory Header Files from Reyadeyat-Modules WITHOUT version headers
    set(LIB_SOURCE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Modules/src")
    set(INCLUDE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Executable-Core/include")
    INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY})
    COPY_FILE_LIST_FROM_TO("/reyadeyat/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} false)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/log/*" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} true)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/utilities/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} false)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/algorithms/*" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} true)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/data-structures/*" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} true)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/file/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} false)
    COPY_FILE_LIST_FROM_TO("/reyadeyat/memory/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} false)
    LINK_DIRECTORIES("${PROJECT_PATH}/Reyadeyat-Executable-Core/lib")
    set(SOURCE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Executable-Core")
    file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY_MAIN}/*.c" "${INCLUDE_DIRECTORY}/*.c")
    ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILE_LIST} ${SOURCE_DIRECTORY})

    #file(MAKE_DIRECTORY "./lib")
    #set(SOURCE_DIRECTORY "./src")
    #file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c" "${INCLUDE_DIRECTORY}/*.c")
    #message("source files in dir: ${SOURCE_DIRECTORY}")
    #foreach(SOURCE_FILE IN LISTS SOURCE_FILE_LIST)
    #    message("source file: ${SOURCE_FILE}")
    #endforeach()
    COPY_FILE_LIST_FROM_TO("*.so" "${PROJECT_PATH}/Reyadeyat-Modules/lib" "${PROJECT_PATH}/Reyadeyat-Executable-Core/lib" false)
elseif("${MODE}" STREQUAL "INCLUDE")
    message("MODE is: INCLUDE")
    add_compile_definitions(MODE=2)
    message("SOURCE_DIRECTORY  = ${PROJECT_PATH}/Reyadeyat-Executable-Core")
    message("INCLUDE_DIRECTORY = ${PROJECT_PATH}/Reyadeyat-Modules")
    set(SOURCE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Executable-Core")
    set(INCLUDE_DIRECTORY "${PROJECT_PATH}/Reyadeyat-Modules")
    file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c" "${INCLUDE_DIRECTORY}/*.c")
    file(GLOB_RECURSE EXCLUDED_FILES "${SOURCE_DIRECTORY}/bin/*.c" "${SOURCE_DIRECTORY}/build/*.c")
    list(REMOVE_ITEM SOURCE_FILE_LIST ${EXCLUDED_FILES})
    INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY} ${LINUX_NCLUDE_DIRECTORY} ${TENSORFLOW_INCLUDE_DIRECTORY})
    LINK_DIRECTORIES(${TENSORFLOW_LIB_DIRECTORY})
    ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILE_LIST} ${INCLUDE_FILE_LIST})
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} tensorflow)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_PATH}/Reyadeyat-Executable-Core/bin" COMPONENT Binaries)

