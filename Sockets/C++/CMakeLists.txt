cmake_minimum_required(VERSION 3.10)
project(SocketExamples)

add_executable(socket_server socket_server.cpp)
add_executable(socket_client socket_client.cpp)
add_executable(udp_server udp_server.cpp)
add_executable(udp_client udp_client.cpp)