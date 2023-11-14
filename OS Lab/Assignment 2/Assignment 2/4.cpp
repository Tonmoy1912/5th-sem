
//not working

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

// Define a shared memory structure for the note
struct shared_note {
    char message[100];
};

int main() {
    int shmid;
    struct shared_note *shared_data;
    pid_t child_pid;

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(struct shared_note), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process
    shared_data = (struct shared_note *)shmat(shmid, NULL, 0);
    if ((int)shared_data == -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process (receiver)

        while (1) {
            printf("Child waiting for a message from the mother...\n");
            sleep(2); // Wait for messages
            printf("Child received: %s\n", shared_data->message);
        }

        // Detach the shared memory segment from the child process (uncomment if needed)
        // shmdt(shared_data);
    } else {
        // Parent process (mother)

        while (1) {
            printf("Mother: Enter a message for the child (or type 'exit' to quit): ");
            fgets(shared_data->message, sizeof(shared_data->message), stdin);

            // Remove the newline character at the end of the message
            size_t len = strlen(shared_data->message);
            if (len > 0 && shared_data->message[len - 1] == '\n') {
                shared_data->message[len - 1] = '\0';
            }

            if (strcmp(shared_data->message, "exit") == 0) {
                // Detach and remove the shared memory segment before exiting
                shmdt(shared_data);
                shmctl(shmid, IPC_RMID, NULL);
                exit(0);
            }
        }
    }

    return 0;
}
