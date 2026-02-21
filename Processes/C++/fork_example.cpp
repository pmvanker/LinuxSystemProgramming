#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdlib>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        std::cout << "Child process: PID = " << getpid() << ", Parent PID = " << getppid() << std::endl;
    } else {
        std::cout << "Parent process: PID = " << getpid() << ", Child PID = " << pid << std::endl;
        wait(nullptr);
        std::cout << "Child finished" << std::endl;
    }
    return 0;
}