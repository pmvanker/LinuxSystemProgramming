#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    // Create a named pipe (FIFO) using mkfifo - creates special file for IPC
    // 0666: permissions - readable/writable by all
    mkfifo(fifo, 0666);

    pid_t pid = fork();
    if (pid == 0) { // Child
        // Open FIFO for reading using open() with O_RDONLY - blocks until writer opens
        int fd = open(fifo, O_RDONLY);
        char buffer[100];
        // Read from FIFO using read() - reads data written by parent
        read(fd, buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        // Close file descriptor
        close(fd);
        // Remove FIFO file using unlink - cleans up the special file
        unlink(fifo);
    } else { // Parent
        // Open FIFO for writing using open() with O_WRONLY - blocks until reader opens
        int fd = open(fifo, O_WRONLY);
        const char *msg = "Hello from parent";
        // Write to FIFO using write() - sends data to child
        write(fd, msg, strlen(msg) + 1);
        // Close file descriptor
        close(fd);
        // Wait for child
        wait(NULL);
    }

    return 0;
}