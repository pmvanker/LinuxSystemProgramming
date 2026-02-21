cmake_minimum_required(VERSION 3.10)
project(ProcessesExamples)
set(CMAKE_CXX_STANDARD 17)

add_executable(fork_example fork_example.cpp)
add_executable(exec_example exec_example.cpp)
add_executable(wait_example wait_example.cpp)