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
        execlp("echo", "echo", "Hello from exec", nullptr);
        std::cerr << "execlp failed" << std::endl;
        return 1;
    } else {
        wait(nullptr);
        std::cout << "Parent: exec finished" << std::endl;
    }
    return 0;
}