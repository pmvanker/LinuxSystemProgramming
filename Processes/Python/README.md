# Processes Examples in Python

This directory contains examples demonstrating process management in Linux using Python.

## Concepts

- **os.fork()**: Creates a new process by duplicating the calling process.
- **os.execvp()**: Replaces the current process image with a new one.
- **os.wait()**: Waits for a child process to terminate.

## Examples

1. **fork_example.py**: Demonstrates forking a child process and printing PIDs.
2. **exec_example.py**: Shows forking and executing a new program in the child.
3. **wait_example.py**: Illustrates waiting for a child process and checking its exit status.

## How to Run

Run examples directly:

- `python3 fork_example.py`
- `python3 exec_example.py`
- `python3 wait_example.py`