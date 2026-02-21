# FIFOs (Named Pipes)

## Problem Solved
FIFOs enable inter-process communication (IPC) between unrelated processes, allowing data to be passed in a first-in-first-out manner.

## What's Good
- Simple to use for one-way communication
- Persistent until deleted, allowing communication between independent processes
- Supports standard I/O operations

## Better Options
- For two-way communication, use sockets (see Sockets)
- For message-based IPC with types, use message queues (see MessageQueues)
- For shared memory access, use shared memory (see SharedMemory)