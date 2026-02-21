# Memory Mapping

## Problem Solved
Memory mapping allows files to be mapped into process address space, enabling efficient file access as if it were memory.

## What's Good
- Efficient for large file operations
- Lazy loading and page-level access
- Shared mappings allow inter-process communication

## Better Options
- For small files, use standard file I/O
- For dynamic data structures, use heap allocation
- For network files, consider distributed file systems