#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void timer_handler(int sig) {
    printf("Timer expired\n");
}

int main() {
    struct itimerval timer;
    // Register signal handler for SIGALRM - called when timer expires
    signal(SIGALRM, timer_handler);

    // Configure timer structure
    // it_value: initial timer value (2 seconds)
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    // it_interval: periodic interval (0 = one-shot timer)
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    // Set interval timer using setitimer() - starts countdown
    // ITIMER_REAL: real-time timer, sends SIGALRM when expires
    setitimer(ITIMER_REAL, &timer, NULL);

    // pause() suspends process until signal is received
    pause();

    return 0;
}