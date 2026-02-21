cmake_minimum_required(VERSION 3.10)
project(LinuxSystemProgramming)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all C++ subdirectories
add_subdirectory(Processes/C++)
add_subdirectory(IPC/FIFOs/C++)
add_subdirectory(IPC/MessageQueues/C++)
add_subdirectory(IPC/Pipes/C++)
add_subdirectory(IPC/Semaphores/C++)
add_subdirectory(IPC/SharedMemory/C++)
add_subdirectory(MemoryMapping/C++)
add_subdirectory(Permissions/C++)
add_subdirectory(Signals/C++)
add_subdirectory(Sockets/C++)
add_subdirectory(SystemCalls/C++)
add_subdirectory(Timers/C++)