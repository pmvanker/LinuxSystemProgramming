#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = ftok("/tmp", 'A');
    int msgid = msgget(key, 0666 | IPC_CREAT);

    pid_t pid = fork();
    if (pid == 0) { // Child
        struct msgbuf msg;
        msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);
        std::cout << "Child received: " << msg.mtext << std::endl;
        msgctl(msgid, IPC_RMID, NULL);
    } else { // Parent
        struct msgbuf msg;
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello from parent");
        msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
        wait(NULL);
    }

    return 0;
}