#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create a socket using socket() - creates endpoint for communication
    // AF_INET: IPv4, SOCK_STREAM: TCP, 0: default protocol
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address structure
    address.sin_family = AF_INET;  // Address family
    address.sin_addr.s_addr = INADDR_ANY;  // Accept connections on any interface
    address.sin_port = htons(8080);  // Port 8080, host to network byte order

    // Bind socket to address using bind() - assigns address to socket
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    // Listen for connections using listen() - marks socket as passive, queue up to 3 connections
    listen(server_fd, 3);

    // Accept connection using accept() - extracts first connection from queue
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    // Read data from client using read() - receives data from socket
    read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    // Send data back using send() - transmits data to client
    send(new_socket, buffer, strlen(buffer), 0);

    // Close client socket
    close(new_socket);
    // Close server socket
    close(server_fd);

    return 0;
}