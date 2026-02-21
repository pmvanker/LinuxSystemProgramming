#include <sys/shm.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

int main() {
    key_t key = ftok("/tmp", 'C');
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);

    pid_t pid = fork();
    if (pid == 0) { // Child
        std::cout << "Child reads: " << str << std::endl;
        shmdt(str);
    } else { // Parent
        strcpy(str, "Hello from parent");
        sleep(1);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
        wait(NULL);
    }

    return 0;
}