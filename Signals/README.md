# Signals

## Problem Solved
Signals provide a way to notify processes of events, such as interrupts or termination requests, enabling asynchronous event handling.

## What's Good
- Lightweight mechanism for process control
- Supports various standard signals (SIGINT, SIGTERM, etc.)
- Can be customized with handlers

## Better Options
- For complex inter-process communication, use pipes or sockets
- For thread synchronization, use condition variables
- For real-time systems, consider real-time signals