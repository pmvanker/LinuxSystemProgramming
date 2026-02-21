#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    // Generate unique key for shared memory
    key_t key = ftok("/tmp", 'C');
    // Allocate shared memory segment using shmget() - creates segment of 1024 bytes
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    // Attach shared memory to process address space using shmat()
    // NULL: let system choose address, 0: read/write permissions
    char *str = (char*) shmat(shmid, NULL, 0);

    pid_t pid = fork();
    if (pid == 0) { // Child
        printf("Child reads: %s\n", str);
        // Detach shared memory using shmdt() - removes from address space
        shmdt(str);
    } else { // Parent
        strcpy(str, "Hello from parent");
        sleep(1); // Wait for child to read
        // Detach shared memory
        shmdt(str);
        // Remove shared memory segment using shmctl() with IPC_RMID
        shmctl(shmid, IPC_RMID, NULL);
        wait(NULL);
    }

    return 0;
}