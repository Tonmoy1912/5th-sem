import multiprocessing
import random
import time

# Function for child process X
def process_X(iterations):
    for i in range(iterations):
        sleep_duration = random.uniform(0.1, 0.5)  # Random sleep between 0.1 and 0.5 seconds
        print(f"Process X - Iteration {i+1}, Sleeping for {sleep_duration:.2f} seconds")
        time.sleep(sleep_duration)

# Function for child process Y
def process_Y(iterations):
    for i in range(iterations):
        sleep_duration = random.uniform(0.5, 1.0)  # Random sleep between 0.5 and 1.0 seconds
        print(f"Process Y - Iteration {i+1}, Sleeping for {sleep_duration:.2f} seconds")
        time.sleep(sleep_duration)

if __name__ == '__main__':
    iterations = 10

    # Create child processes X and Y
    process_x = multiprocessing.Process(target=process_X, args=(iterations,))
    process_y = multiprocessing.Process(target=process_Y, args=(iterations,))

    # Start the child processes
    process_x.start()
    process_y.start()

    # Wait for both processes to finish
    process_x.join()
    process_y.join()

    print("Both processes have finished.")
