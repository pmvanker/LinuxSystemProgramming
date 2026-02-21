#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    const char *msg = "Hello from client";

    // Create socket using socket() - creates endpoint for communication
    // AF_INET: IPv4, SOCK_STREAM: TCP, 0: default protocol
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Configure server address
    serv_addr.sin_family = AF_INET;  // Address family
    serv_addr.sin_port = htons(8080);  // Port, host to network byte order

    // Convert IP address from text to binary using inet_pton()
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    // Connect to server using connect() - establishes TCP connection
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Send message to server using send()
    send(sock, msg, strlen(msg), 0);
    printf("Message sent: %s\n", msg);

    // Receive response using read()
    read(sock, buffer, 1024);
    printf("Received: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}