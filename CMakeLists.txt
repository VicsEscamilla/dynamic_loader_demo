cmake_minimum_required(VERSION 3.0)
project(dynamic_loader_demo)

set(COMMON_LIBS
    src/dynamic_loader.cpp
    src/zmq_wrapper.cpp)

set(SERVER
    src/server.cpp
    ${COMMON_LIBS})

set(CLIENT
    src/client.cpp
    ${COMMON_LIBS})

add_executable(server ${SERVER})
add_executable(client ${CLIENT})

target_link_libraries(server dl)
target_link_libraries(client dl)
