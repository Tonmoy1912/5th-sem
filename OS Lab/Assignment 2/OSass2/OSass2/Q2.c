#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

// Define a structure for the message
struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;

    // Generate a unique key for the message queue
    key = ftok("progfile", 65);

    // Create a message queue and get its ID
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork()\n");
        exit(EXIT_FAILURE);
    }

    // Parent process (Mother)
    if (pid > 0) {
        struct msg_buffer mother_msg;

        // Message Type 1 for messages from Mother
        mother_msg.msg_type = 1;

        // Send a message to the child
        printf("Mother: ");
        fgets(mother_msg.msg_text, MAX_MSG_SIZE, stdin);

        // Send the message
        msgsnd(msgid, &mother_msg, sizeof(mother_msg), 0);

        // Wait for the child to send a message
        struct msg_buffer child_msg;
        msgrcv(msgid, &child_msg, sizeof(child_msg), 2, 0);

        // Display the received message from the child
        printf("Child: %s", child_msg.msg_text);
    }

    // Child process
    else {
        struct msg_buffer child_msg;

        // Message Type 2 for messages from Child
        child_msg.msg_type = 2;

        // Wait for the mother to send a message
        struct msg_buffer mother_msg;
        msgrcv(msgid, &mother_msg, sizeof(mother_msg), 1, 0);

        // Display the received message from the mother
        printf("Mother: %s", mother_msg.msg_text);

        // Send a message to the mother
        printf("Child: ");
        fgets(child_msg.msg_text, MAX_MSG_SIZE, stdin);
        msgsnd(msgid, &child_msg, sizeof(child_msg), 0);
    }

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
