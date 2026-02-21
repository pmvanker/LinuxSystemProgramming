# System Calls

## Problem Solved
System calls provide the interface between user-space programs and the kernel, allowing access to system resources and services.

## What's Good
- Direct access to kernel functionality
- Essential for low-level system programming
- High performance and control

## Better Options
- For portability, use standard library functions that wrap syscalls
- For complex operations, use higher-level APIs
- For security, avoid direct syscalls when possible and use safe wrappers