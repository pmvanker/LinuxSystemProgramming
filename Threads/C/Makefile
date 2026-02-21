CC=gcc
CFLAGS=-Wall -Wextra -pthread

all: thread_create sync

thread_create: thread_create.c
	$(CC) $(CFLAGS) -o thread_create thread_create.c

sync: sync.c
	$(CC) $(CFLAGS) -o sync sync.c

clean:
	rm -f thread_create sync

.PHONY: all clean