#include <unistd.h>
#include <iostream>

int main() {
    pid_t pid = getpid();
    std::cout << "Process ID: " << pid << std::endl;

    uid_t uid = getuid();
    std::cout << "User ID: " << uid << std::endl;

    return 0;
}