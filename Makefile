# Global Makefile for all C programs in Linux System Programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Define all C program directories
C_DIRS = Processes/C IPC/FIFOs/C IPC/MessageQueues/C IPC/Pipes/C IPC/Semaphores/C IPC/SharedMemory/C \
         MemoryMapping/C Permissions/C Signals/C Sockets/C SystemCalls/C Timers/C

# Default target
all: build_all

# Build all directories
build_all:
	@for dir in $(C_DIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir CC=$(CC) CFLAGS="$(CFLAGS)"; \
	done

# Clean all
clean:
	@for dir in $(C_DIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done

# Install all binaries to bin directory
install: build_all
	@echo "Creating bin directory..."
	@mkdir -p bin
	@echo "Installing binaries..."
	@for dir in $(C_DIRS); do \
		for exe in $$dir/*; do \
			if [ -f "$$exe" ] && [ -x "$$exe" ] && [ "$$exe" != "$$dir/Makefile" ]; then \
				cp "$$exe" bin/; \
			fi; \
		done; \
	done
	@echo "Installation complete. Binaries are in ./bin/"
	@ls -la bin/

.PHONY: all clean build_all install