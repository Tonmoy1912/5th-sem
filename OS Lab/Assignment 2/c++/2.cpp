#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define a structure for the message
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    // Message queue key
    key_t key;
    int msg_id;

    // Generate a unique key
    key = ftok("progfile", 65);

    // Create a message queue
    msg_id = msgget(key, 0666 | IPC_CREAT);

    if (msg_id == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process (receiver)

        struct msg_buffer rcv_message;

        // Receive the message from the mother
        if (msgrcv(msg_id, &rcv_message, sizeof(rcv_message), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Child received: %s\n", rcv_message.msg_text);
    } else {
        // Parent process (mother)

        struct msg_buffer snd_message;
        snd_message.msg_type = 1;

        // Send a message to the child
        printf("Mother: Enter a message for the child: ");
        fgets(snd_message.msg_text, sizeof(snd_message.msg_text), stdin);

        // Remove the newline character at the end of the message
        size_t len = strlen(snd_message.msg_text);
        if (len > 0 && snd_message.msg_text[len - 1] == '\n') {
            snd_message.msg_text[len - 1] = '\0';
        }

        if (msgsnd(msg_id, &snd_message, sizeof(snd_message), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Mother sent: %s\n", snd_message.msg_text);
    }

    // Remove the message queue
    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}


/*

In this program:

We define a msg_buffer structure to hold the message. It includes a message type (msg_type) and a character array (msg_text) to store the message itself.

We generate a unique key using ftok for the message queue.

We create a message queue using msgget with read/write permissions (0666) and the IPC_CREAT flag.

We fork a child process using fork. The child process will receive messages, and the parent process (mother) will send messages.

In the child process, we use msgrcv to receive a message from the mother.

In the parent process, we use msgsnd to send a message to the child.

We remove the message queue using msgctl when the program exits.

Compile the program with a C/C++ compiler, and you can run it to see how the mother and child processes communicate using Message Queues.

*/
