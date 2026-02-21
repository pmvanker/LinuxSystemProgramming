#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    socklen_t len = sizeof(cliaddr);

    // Create UDP socket using socket() - SOCK_DGRAM for UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    // Bind socket to address using bind()
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("UDP Server listening on port 8080...\n");

    while (1) {
        // Receive message using recvfrom() - receives data and sender address
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);

        // Send response using sendto() - sends data to specific address
        sendto(sockfd, buffer, n, 0, (struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}