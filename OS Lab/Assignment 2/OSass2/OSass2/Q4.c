#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MSG_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *shared_memory;

    // Generate a unique key for the shared memory
    key = ftok("progfile", 65);

    // Create a shared memory segment and get its ID
    shmid = shmget(key, MAX_MSG_SIZE, 0666 | IPC_CREAT);

    // Attach the shared memory segment to the process
    shared_memory = (char *)shmat(shmid, NULL, 0);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Parent process (Mother)
    if (pid > 0) {
        char mother_msg[MAX_MSG_SIZE];

        // Send a message to the child
        printf("Mother: ");
        fgets(mother_msg, MAX_MSG_SIZE, stdin);
        strcpy(shared_memory, mother_msg);

        // Wait for the child to send a message
        while (strlen(shared_memory) == 0) {
            sleep(1);  // Wait for the child to write to shared memory
        }

        // Display the received message from the child
        printf("Child: %s", shared_memory);

        // Detach the shared memory segment from the process
        shmdt(shared_memory);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    // Child process
    else {
        char child_msg[MAX_MSG_SIZE];

        // Wait for the mother to send a message
        while (strlen(shared_memory) == 0) {
            sleep(1);  // Wait for the mother to write to shared memory
        }

        // Display the received message from the mother
        printf("Mother: %s", shared_memory);

        // Send a message to the mother
        printf("Child: ");
        fgets(child_msg, MAX_MSG_SIZE, stdin);
        strcpy(shared_memory, child_msg);

        // Detach the shared memory segment from the process
        shmdt(shared_memory);
    }

    return 0;
}
