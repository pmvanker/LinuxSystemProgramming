# Processes Examples in C

This directory contains examples demonstrating process management in Linux using C.

## Concepts

- **fork()**: Creates a new process by duplicating the calling process.
- **exec()**: Replaces the current process image with a new one.
- **wait()**: Waits for a child process to terminate.

## Examples

1. **fork_example.c**: Demonstrates forking a child process and printing PIDs.
2. **exec_example.c**: Shows forking and executing a new program in the child.
3. **wait_example.c**: Illustrates waiting for a child process and checking its exit status.

## How to Run

1. Compile: `make`
2. Run examples:
   - `./fork_example`
   - `./exec_example`
   - `./wait_example`
3. Clean: `make clean`