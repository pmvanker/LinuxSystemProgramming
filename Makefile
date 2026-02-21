# Global Makefile for all C programs in Linux System Programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Define all C program directories
C_DIRS = Processes/C IPC/FIFOs/C IPC/MessageQueues/C IPC/Pipes/C IPC/Semaphores/C IPC/SharedMemory/C \
         MemoryMapping/C Permissions/C Signals/C Sockets/C SystemCalls/C Timers/C

# Default target
all: $(C_DIRS)

# Build each directory
Processes/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

IPC/FIFOs/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

IPC/MessageQueues/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

IPC/Pipes/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

IPC/Semaphores/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

IPC/SharedMemory/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

MemoryMapping/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

Permissions/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

Signals/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

Sockets/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

SystemCalls/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

Timers/C:
	$(MAKE) -C $@ CC=$(CC) CFLAGS="$(CFLAGS)"

# Clean all
clean:
	for dir in $(C_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

# Individual clean targets
clean-%:
	$(MAKE) -C $(subst clean-,,$@) clean

.PHONY: all clean $(C_DIRS) $(addprefix clean-,$(C_DIRS))