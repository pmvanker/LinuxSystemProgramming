#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        execlp("echo", "echo", "Hello from exec", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent: exec finished\n");
    }
    return 0;
}