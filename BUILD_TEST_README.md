# Build and Test Instructions

## Building C++ Programs

### Using CMake (Recommended)
```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Or build all at once
cmake --build .
```

This will build all C++ examples in their respective directories.

### Manual Build
Each C++ directory has its own CMakeLists.txt. You can build individual examples:
```bash
cd Processes/C++/build
cmake ..
make
```

## Building C Programs

### Using Global Makefile
```bash
# Build all C programs
make

# Build specific category
make Processes/C

# Clean all
make clean

# Clean specific
make clean-Processes/C
```

### Manual Build
Each C directory has its own Makefile:
```bash
cd Processes/C
make
```

## Testing Python Programs

### Setup
```bash
# Install pytest
pip install -r requirements-test.txt
```

### Run Tests
```bash
# Run all tests
pytest test_all.py

# Run specific test class
pytest test_all.py::TestFileIO

# Run with verbose output
pytest test_all.py -v

# Run specific test
pytest test_all.py::TestIPC::test_pipe_example
```

### Test Coverage
The test suite covers:
- File I/O operations
- Process management (fork, exec, wait)
- IPC mechanisms (pipes, FIFOs, message queues, semaphores, shared memory)
- Memory mapping
- File permissions
- Signal handling
- Network sockets (TCP/UDP)
- System calls
- Timers

Note: Some tests have timeouts since they involve forking processes or waiting for signals/network connections.