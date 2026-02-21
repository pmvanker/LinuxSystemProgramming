#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    // Create a pipe using pipe() - creates unidirectional communication channel
    // pipefd[0] is read end, pipefd[1] is write end
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork a child process using fork() - creates duplicate process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        // Close write end in child - child only reads
        close(pipefd[1]);
        // Read from pipe using read() - blocks until data available
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        // Close read end
        close(pipefd[0]);
    } else { // Parent process
        // Close read end in parent - parent only writes
        close(pipefd[0]);
        const char *msg = "Hello from parent";
        // Write to pipe using write() - sends data to child
        write(pipefd[1], msg, strlen(msg) + 1);
        // Close write end
        close(pipefd[1]);
        // Wait for child to finish using wait() - prevents zombie processes
        wait(NULL);
    }

    return 0;
}