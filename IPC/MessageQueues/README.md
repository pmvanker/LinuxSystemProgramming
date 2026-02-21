# Message Queues

## Problem Solved
Message queues provide a way for processes to exchange messages asynchronously, with support for message types and priorities.

## What's Good
- Asynchronous communication without blocking
- Supports message prioritization and types
- Reliable delivery of messages

## Better Options
- For high-performance IPC, use shared memory (see SharedMemory)
- For network communication, use sockets (see Sockets)
- For simple data passing, use pipes (see Pipes)