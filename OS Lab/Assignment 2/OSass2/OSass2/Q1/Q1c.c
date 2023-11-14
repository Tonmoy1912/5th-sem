#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

// Define a semaphore
sem_t semaphore;

void child_process(char name, int iterations) {
    for (int i = 1; i <= iterations; ++i) {
        sem_wait(&semaphore); // Wait for the semaphore
        printf("%c: Iteration %d\n", name, i);
        sem_post(&semaphore); // Release the semaphore
        sleep(1);  // Sleep for 1 second
    }
}

int main() {
    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    pid_t pidX, pidY, pidZ;

    pidX = fork();
    if (pidX == 0) {
        child_process('X', 10);
        exit(EXIT_SUCCESS);
    }

    pidY = fork();
    if (pidY == 0) {
        child_process('Y', 10);
        exit(EXIT_SUCCESS);
    }

    pidZ = fork();
    if (pidZ == 0) {
        child_process('Z', 10);
        exit(EXIT_SUCCESS);
    }

    // Wait for all child processes to finish
    waitpid(pidX, NULL, 0);
    waitpid(pidY, NULL, 0);
    waitpid(pidZ, NULL, 0);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
