#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

struct msgbuf {
    long mtype;  // Message type for prioritization
    char mtext[100];  // Message data
};

int main() {
    // Generate unique key using ftok() - creates key from pathname and project ID
    key_t key = ftok("/tmp", 'A');
    // Create message queue using msgget() - allocates queue with given key
    // IPC_CREAT: create if doesn't exist, 0666: permissions
    int msgid = msgget(key, 0666 | IPC_CREAT);

    pid_t pid = fork();
    if (pid == 0) { // Child
        struct msgbuf msg;
        // Receive message using msgrcv() - blocks until message of type 1 arrives
        msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);
        printf("Child received: %s\n", msg.mtext);
        // Remove message queue using msgctl() with IPC_RMID
        msgctl(msgid, IPC_RMID, NULL);
    } else { // Parent
        struct msgbuf msg;
        msg.mtype = 1;  // Set message type
        strcpy(msg.mtext, "Hello from parent");
        // Send message using msgsnd() - places message in queue
        msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
        wait(NULL);
    }

    return 0;
}