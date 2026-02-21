# Linux System Programming Examples

This project contains comprehensive examples of Linux system programming concepts implemented in C, C++, and Python.

## Structure

The project is organized by topic, with subdirectories for each programming language:

- **Processes**: Fork, exec, wait operations
- **Threads**: Thread creation and synchronization
- **IPC**: Inter-process communication methods
  - Pipes
  - FIFOs (Named Pipes)
  - Shared Memory
  - Message Queues
  - Semaphores
- **Signals**: Signal handling
- **FileIO**: File input/output operations
- **MemoryMapping**: Memory-mapped files
- **Sockets**: Network socket programming
- **SystemCalls**: Basic system calls
- **Permissions**: File permissions and user/group operations
- **Timers**: Timer and alarm functions

## Languages

- **C**: Uses standard C libraries and POSIX APIs
- **C++**: Modern C++ with standard libraries where possible, POSIX for system calls
- **Python**: Uses `os`, `multiprocessing`, `threading`, and other standard modules

## Building and Running

### C Examples
Each C directory contains a `Makefile`. Run `make` to build, then execute the binaries.

### C++ Examples
Each C++ directory contains a `CMakeLists.txt`. Use CMake to build:
```bash
mkdir build
cd build
cmake ..
make
```

### Python Examples
Run directly with `python example.py`. No build required.

## Requirements

- Linux operating system
- GCC for C compilation
- CMake for C++ building
- Python 3 for Python examples

## Learning Resources

These examples demonstrate core Linux system programming concepts. Study the code, run the examples, and modify them to deepen understanding.