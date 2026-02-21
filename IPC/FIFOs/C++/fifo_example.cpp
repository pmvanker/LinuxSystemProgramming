#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666);

    pid_t pid = fork();
    if (pid == 0) { // Child
        int fd = open(fifo, O_RDONLY);
        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        std::cout << "Child received: " << buffer << std::endl;
        close(fd);
        unlink(fifo);
    } else { // Parent
        int fd = open(fifo, O_WRONLY);
        const char *msg = "Hello from parent";
        write(fd, msg, strlen(msg) + 1);
        close(fd);
        wait(NULL);
    }

    return 0;
}