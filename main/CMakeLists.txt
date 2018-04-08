set(SRC_FILES main.cpp)

add_executable(mvc ${SRC_FILES})
target_link_libraries(mvc model)