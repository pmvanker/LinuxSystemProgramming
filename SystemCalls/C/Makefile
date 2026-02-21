CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c99

TARGET = syscall_example

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean