#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void child_process(char name, int iterations) {
    srand(time(NULL));
    for (int i = 1; i <= iterations; ++i) {
        printf("%c: Iteration %d\n", name, i);
        int sleep_duration = rand() % 3 + 1;  // Sleep for a random duration between 1 and 3 seconds
        sleep(sleep_duration);
    }
}

int main() {
    pid_t pidX, pidY;

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

    // Wait for both child processes to finish
    waitpid(pidX, NULL, 0);
    waitpid(pidY, NULL, 0);

    return 0;
}
