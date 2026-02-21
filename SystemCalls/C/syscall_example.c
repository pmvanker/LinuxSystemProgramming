#include <unistd.h>
#include <stdio.h>

int main() {
    // Get process ID using getpid() - returns ID of calling process
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    // Get user ID using getuid() - returns real user ID of calling process
    uid_t uid = getuid();
    printf("User ID: %d\n", uid);

    return 0;
}