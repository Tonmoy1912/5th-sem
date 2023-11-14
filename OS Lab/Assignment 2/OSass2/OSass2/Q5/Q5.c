#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 20
#define NUM_PRODUCERS 5
#define NUM_CONSUMERS 10
#define PRODUCER_ITERATIONS 10
#define CONSUMER_ITERATIONS 4
#define MAX_RANDOM 50

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t full, empty, mutex;

int GRAND = 0;

// Array to track generated numbers
int generated_numbers[MAX_RANDOM + 1] = {0};

// Function to generate a unique random number
int generate_unique_random() {
    int random_number;
    do {
        random_number = (rand() % MAX_RANDOM) + 1;
    } while (generated_numbers[random_number] == 1);

    generated_numbers[random_number] = 1;
    return random_number;
}

void *producer(void *id) {
    int producer_id = *(int *)id;

    FILE *file;
    char filename[20];
    sprintf(filename, "producer_%d.txt", producer_id);
    file = fopen(filename, "w");

    for (int i = 0; i < PRODUCER_ITERATIONS; i++) {
        int item = generate_unique_random();

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer %d produced: %d\n", producer_id, item);
        fprintf(file, "Producer %d produced: %d\n", producer_id, item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }

    fclose(file);
    pthread_exit(NULL);
}

void *consumer(void *id) {
    int consumer_id = *(int *)id;

    FILE *file;
    char filename[20];
    sprintf(filename, "consumer_%d.txt", consumer_id);
    file = fopen(filename, "w");

    for (int i = 0; i < CONSUMER_ITERATIONS; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer %d consumed: %d\n", consumer_id, item);
        fprintf(file, "Consumer %d consumed: %d\n", consumer_id, item);
        GRAND += item;
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    }

    fclose(file);
    pthread_exit(NULL);
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i;
        pthread_create(&producers[i], NULL, producer, (void *)&producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i;
        pthread_create(&consumers[i], NULL, consumer, (void *)&consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("GRAND total: %d\n", GRAND);

    return 0;
}
