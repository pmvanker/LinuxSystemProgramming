#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok("/tmp", 'B');
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    pid_t pid = fork();
    if (pid == 0) { // Child
        struct sembuf sb = {0, -1, 0};
        semop(semid, &sb, 1);
        printf("Child: Critical section\n");
        sb.sem_op = 1;
        semop(semid, &sb, 1);
    } else { // Parent
        struct sembuf sb = {0, -1, 0};
        semop(semid, &sb, 1);
        printf("Parent: Critical section\n");
        sb.sem_op = 1;
        semop(semid, &sb, 1);
        wait(NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}