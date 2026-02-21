CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c99

TARGETS = socket_server socket_client udp_server udp_client

all: $(TARGETS)

socket_server: socket_server.c
	$(CC) $(CFLAGS) -o $@ $<

socket_client: socket_client.c
	$(CC) $(CFLAGS) -o $@ $<

udp_server: udp_server.c
	$(CC) $(CFLAGS) -o $@ $<

udp_client: udp_client.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean