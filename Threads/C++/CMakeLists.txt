cmake_minimum_required(VERSION 3.10)
project(ThreadsExamples)
set(CMAKE_CXX_STANDARD 17)

add_executable(thread_create thread_create.cpp)
add_executable(sync sync.cpp)