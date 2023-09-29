#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

// Function for child process X
void process_X(int iterations) {
    srand(time(nullptr)); // Seed the random number generator
    for (int i = 0; i < iterations; ++i) {
        double sleep_duration = (rand() % 5 + 1) / 10.0; // Random sleep between 0.1 and 0.5 seconds
        cout << "Process X - Iteration " << i + 1 << ", Sleeping for " << sleep_duration << " seconds" << endl;
        sleep(sleep_duration); // Sleep in second
    }
}

// Function for child process Y
void process_Y(int iterations) {
    srand(time(nullptr)); // Seed the random number generator
    for (int i = 0; i < iterations; ++i) {
        double sleep_duration = (rand() % 5 + 5) / 10.0; // Random sleep between 0.5 and 1.0 seconds
        cout << "Process Y - Iteration " << i + 1 << ", Sleeping for " << sleep_duration << " seconds" << endl;
        sleep(sleep_duration); // Sleep in second
    }
}

int main() {
    int iterations = 10;

    // Create child processes X and Y
    pid_t child_x, child_y;

    child_x = fork(); // Create child process X

    if (child_x == 0) { // In the child process X
        process_X(iterations);
        exit(0);
    } else if (child_x > 0) { // In the parent process
        child_y = fork(); // Create child process Y

        if (child_y == 0) { // In the child process Y
            process_Y(iterations);
            exit(0);
        } else if (child_y > 0) { // In the parent process
            // Wait for both child processes to finish
            int status;
            waitpid(child_x, &status, 0);
            waitpid(child_y, &status, 0);
            cout << "Both processes have finished." << endl;
        } else {
            cerr << "Error creating child process Y." << endl;
            exit(1);
        }
    } else {
        cerr << "Error creating child process X." << endl;
        exit(1);
    }

    return 0;
}
