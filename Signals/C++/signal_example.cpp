#include <csignal>
#include <iostream>
#include <unistd.h>

void signal_handler(int sig) {
    std::cout << "Received signal " << sig << std::endl;
}

int main() {
    std::signal(SIGINT, signal_handler);
    std::cout << "Press Ctrl+C to send SIGINT" << std::endl;
    while (true) {
        sleep(1);
    }
    return 0;
}