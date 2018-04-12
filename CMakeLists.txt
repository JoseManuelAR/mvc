cmake_minimum_required (VERSION 3.5.1)
project (mvc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER /usr/bin/gcc-7)
set(CMAKE_CXX_COMPILER /usr/bin/g++-7)

add_subdirectory(model)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(event)
target_include_directories(event PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(view)
target_include_directories(view PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(rest)
target_include_directories(rest PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(controller)
target_include_directories(controller PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(mvc)
target_include_directories(mvc PUBLIC ${CMAKE_CURRENT_LIST_DIR})
