#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    const char *msg = "Hello from UDP client";

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Message sent: " << msg << std::endl;

    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    std::cout << "Received: " << buffer << std::endl;

    close(sockfd);
    return 0;
}