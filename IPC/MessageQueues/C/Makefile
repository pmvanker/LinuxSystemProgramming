CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c99

TARGET = msg_queue_example

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean