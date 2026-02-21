# Threads Examples in C++

This directory contains examples demonstrating thread management in Linux using modern C++.

## Concepts

- **std::thread**: For creating threads.
- **std::mutex**: For synchronization.

## Examples

1. **thread_create.cpp**: Demonstrates creating and joining a thread.
2. **sync.cpp**: Shows synchronization using mutex to avoid race conditions.

## How to Run

1. Create build directory: `mkdir build && cd build`
2. Configure: `cmake ..`
3. Build: `make`
4. Run examples:
   - `./thread_create`
   - `./sync`