# Pipes

## Problem Solved
Pipes allow for unidirectional data flow between related processes (parent-child), useful for chaining commands or process communication.

## What's Good
- Simple and efficient for related processes
- No need for external files or complex setup
- Supports standard I/O redirection

## Better Options
- For unrelated processes, use named pipes (FIFOs) or sockets
- For bidirectional communication, use sockets
- For complex message passing, use message queues