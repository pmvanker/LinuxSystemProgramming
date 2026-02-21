#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    // Register signal handler using signal() - sets function to handle SIGINT
    // SIGINT: interrupt signal (Ctrl+C), signal_handler: function to call
    signal(SIGINT, signal_handler);
    printf("Press Ctrl+C to send SIGINT\n");
    while (1) {
        // sleep() suspends execution for 1 second - allows signal to be delivered
        sleep(1);
    }
    return 0;
}