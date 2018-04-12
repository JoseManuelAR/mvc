set(SRC_FILES main.cpp app.cpp)

add_executable(mvc ${SRC_FILES})
target_link_libraries(
    mvc 
    rest 
    controller 
    view 
    model
    event
    nghttp2_asio 
    ssl crypto 
    boost_system
    )