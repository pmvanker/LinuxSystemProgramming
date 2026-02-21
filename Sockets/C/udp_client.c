#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    const char *msg = "Hello from UDP client";

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    // Send message using sendto() - sends data without establishing connection
    sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Message sent: %s\n", msg);

    // Receive response using recvfrom()
    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}