#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main() {
    int pipe_fd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Parent process (Mother)
    if (pid > 0) {
        close(pipe_fd[0]);  // Close the read end of the pipe in the parent

        char mother_msg[MAX_MSG_SIZE];

        // Send a message to the child
        printf("Mother: ");
        fgets(mother_msg, MAX_MSG_SIZE, stdin);
        write(pipe_fd[1], mother_msg, strlen(mother_msg) + 1);

        // Wait for the child to send a message
        char child_msg[MAX_MSG_SIZE];
        read(pipe_fd[0], child_msg, sizeof(child_msg));

        // Display the received message from the child
        printf("Child: %s", child_msg);

        close(pipe_fd[1]);  // Close the write end of the pipe in the parent
    }

    // Child process
    else {
        close(pipe_fd[1]);  // Close the write end of the pipe in the child

        char child_msg[MAX_MSG_SIZE];

        // Wait for the mother to send a message
        char mother_msg[MAX_MSG_SIZE];
        read(pipe_fd[0], mother_msg, sizeof(mother_msg));

        // Display the received message from the mother
        printf("Mother: %s", mother_msg);

        // Send a message to the mother
        printf("Child: ");
        fgets(child_msg, MAX_MSG_SIZE, stdin);
        write(pipe_fd[1], child_msg, strlen(child_msg) + 1);

        close(pipe_fd[0]);  // Close the read end of the pipe in the child
    }

    return 0;
}
