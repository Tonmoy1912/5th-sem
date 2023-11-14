#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2]; // File descriptors for the pipe
    pid_t child_pid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process (receiver)

        close(pipe_fd[1]); // Close write end of the pipe

        char received_message[100];
        ssize_t bytes_read = read(pipe_fd[0], received_message, sizeof(received_message));

        if (bytes_read == -1) {
            perror("read");
            exit(1);
        }

        received_message[bytes_read] = '\0'; // Null-terminate the received message

        printf("Child received: %s\n", received_message);

        close(pipe_fd[0]); // Close read end of the pipe
    } else {
        // Parent process (mother)

        close(pipe_fd[0]); // Close read end of the pipe

        char message_to_send[100];
        printf("Mother: Enter a message for the child: ");
        fgets(message_to_send, sizeof(message_to_send), stdin);

        // Remove the newline character at the end of the message
        size_t len = strlen(message_to_send);
        if (len > 0 && message_to_send[len - 1] == '\n') {
            message_to_send[len - 1] = '\0';
        }

        ssize_t bytes_written = write(pipe_fd[1], message_to_send, strlen(message_to_send));

        if (bytes_written == -1) {
            perror("write");
            exit(1);
        }

        printf("Mother sent: %s\n", message_to_send);

        close(pipe_fd[1]); // Close write end of the pipe
    }

    return 0;
}

/*

In this program:

We create a pipe using the pipe function. The pipe_fd array contains two file descriptors: pipe_fd[0] for reading and pipe_fd[1] for writing.

We fork a child process using fork. The child process will receive messages, and the parent process (mother) will send messages.

In the child process, we close the write end of the pipe (pipe_fd[1]) since it won't be used for writing in the child process. Then, we read from the read end of the pipe (pipe_fd[0]) to receive the message.

In the parent process, we close the read end of the pipe (pipe_fd[0]) since it won't be used for reading in the parent process. Then, we use fgets to get a message from the user and write it to the write end of the pipe (pipe_fd[1]) to send it to the child process.

We close the appropriate pipe ends to release system resources.

Compile the program with a C/C++ compiler, and you can run it to see how the mother and child processes communicate using pipes

*/