cmake_minimum_required(VERSION 3.6)
project(AlgorithmsAndDataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ext")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_LIST_DIR}/cmake"
    "${CMAKE_CURRENT_LIST_DIR}/ext/cmake"
    "${CMAKE_CURRENT_LIST_DIR}/ext/lib/cmake")

include_directories(BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/ext/include")

add_subdirectory(app)
add_subdirectory(core/stack)
add_subdirectory(test)
add_subdirectory(ext EXCLUDE_FROM_ALL)
