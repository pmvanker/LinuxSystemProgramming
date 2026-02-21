CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: fork_example exec_example wait_example

fork_example: fork_example.c
	$(CC) $(CFLAGS) -o fork_example fork_example.c

exec_example: exec_example.c
	$(CC) $(CFLAGS) -o exec_example exec_example.c

wait_example: wait_example.c
	$(CC) $(CFLAGS) -o wait_example wait_example.c

clean:
	rm -f fork_example exec_example wait_example

.PHONY: all clean