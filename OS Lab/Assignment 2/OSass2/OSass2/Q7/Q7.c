#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];
pthread_cond_t can_eat[NUM_PHILOSOPHERS];

// typedef struct {
//     bool is_eating;
// } Philosopher;

// Philosopher philosophers[NUM_PHILOSOPHERS];

void init() {
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&chopsticks[i], NULL);
        pthread_cond_init(&can_eat[i], NULL);
    }
}

void take_chopsticks(int philosopher_id,int id) {
    if(id%2){
        pthread_mutex_lock(&chopsticks[philosopher_id]);
        pthread_mutex_lock(&chopsticks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
    }
    else{
        pthread_mutex_lock(&chopsticks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
        pthread_mutex_lock(&chopsticks[philosopher_id]);
    }
}

void put_chopsticks(int philosopher_id) {
    pthread_mutex_unlock(&chopsticks[philosopher_id]);
    pthread_mutex_unlock(&chopsticks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
}

void *philosopher_thread(void *arg) {
    int philosopher_id = *(int *)arg;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopher_id);

        take_chopsticks(philosopher_id,philosopher_id);

        printf("Philosopher %d is eating\n", philosopher_id);
        sleep(1);  // Simulating eating time

        put_chopsticks(philosopher_id);

        // Optional: Sleep to simulate some delay before the next cycle
        sleep(1);
    }
}

int main() {
    init();

    pthread_t philosophers_threads[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers_threads[i], NULL, philosopher_thread, (void *)&philosopher_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers_threads[i], NULL);
    }

    return 0;
}
