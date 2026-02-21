# Semaphores

## Problem Solved
Semaphores provide synchronization mechanisms to control access to shared resources, preventing race conditions in concurrent programs.

## What's Good
- Effective for mutual exclusion and signaling
- Supports counting semaphores for resource management
- System-wide synchronization possible

## Better Options
- For thread synchronization within a process, use mutexes or condition variables
- For more complex synchronization, consider monitors or higher-level constructs
- For message passing, use message queues