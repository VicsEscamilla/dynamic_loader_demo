cmake_minimum_required(VERSION 3.0)
project(dynamic_loader_demo)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++0x")

set(ZMQ_WRAPPER_LIB_SRC
    src/zmq_wrapper.cpp)

set(COMMON_LIBS
    src/dynamic_loader.cpp)

set(SERVER
    src/server.cpp
    src/zmq_wrapper_interface.h
    ${COMMON_LIBS})

set(CLIENT
    src/client.cpp
    src/zmq_wrapper_interface.h
    ${COMMON_LIBS})

add_library(zmq_wrapper SHARED ${ZMQ_WRAPPER_LIB_SRC})
add_executable(server ${SERVER})
add_executable(client ${CLIENT})

find_library(ZMQ_LIBRARY NAMES zmq)
target_link_libraries(zmq_wrapper ${ZMQ_LIBRARY})

# server and client aren't linked to zmq nor zmq_wrapper... yet
target_link_libraries(server dl)
target_link_libraries(client dl)
