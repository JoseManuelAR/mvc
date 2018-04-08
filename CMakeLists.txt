cmake_minimum_required (VERSION 3.5.1)
project (mvc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER /usr/bin/gcc-7)
set(CMAKE_CXX_COMPILER /usr/bin/g++-7)

add_subdirectory(model)
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(main)