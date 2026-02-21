#include <sys/time.h>
#include <csignal>
#include <iostream>
#include <unistd.h>

void timer_handler(int sig) {
    std::cout << "Timer expired" << std::endl;
}

int main() {
    std::signal(SIGALRM, timer_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    pause();

    return 0;
}