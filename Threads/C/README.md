# Threads Examples in C

This directory contains examples demonstrating thread management in Linux using C with pthreads.

## Concepts

- **pthread_create()**: Creates a new thread.
- **pthread_join()**: Waits for a thread to terminate.
- **pthread_mutex**: For synchronization.

## Examples

1. **thread_create.c**: Demonstrates creating and joining a thread.
2. **sync.c**: Shows synchronization using mutex to avoid race conditions.

## How to Run

1. Compile: `make`
2. Run examples:
   - `./thread_create`
   - `./sync`
3. Clean: `make clean`