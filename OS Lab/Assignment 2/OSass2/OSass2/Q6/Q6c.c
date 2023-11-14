#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t mutex, readBlock, writeBlock;
int data = 0, readersCount = 0, activeWriters = 0;

void *reader(void *arg) {
    while (1) {
        sem_wait(&readBlock);
        sem_wait(&mutex);
        readersCount++;
        if (readersCount == 1) {
            sem_wait(&writeBlock);
        }
        sem_post(&mutex);
        sem_post(&readBlock);

        // Reading section
        printf("Reader %d read data: %d\n", *((int *)arg), data);
        sleep(1); // Simulating reading time

        sem_wait(&mutex);
        readersCount--;
        if (readersCount == 0) {
            sem_post(&writeBlock);
        }
        sem_post(&mutex);

        // Optional: Sleep to simulate some delay before the next read
        sleep(2);
    }
}

void *writer(void *arg) {
    while (1) {
        sem_wait(&mutex);
        activeWriters++;
        if (activeWriters == 1) {
            sem_wait(&readBlock);
        }
        sem_post(&mutex);

        sem_wait(&writeBlock);

        // Writing section
        data++;
        printf("Writer %d wrote data: %d\n", *((int *)arg), data);
        sleep(2); // Simulating writing time

        sem_post(&writeBlock);

        sem_wait(&mutex);
        activeWriters--;
        if (activeWriters == 0) {
            sem_post(&readBlock);
        }
        sem_post(&mutex);

        // Optional: Sleep to simulate some delay before the next write
        sleep(3);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&readBlock, 0, 1);
    sem_init(&writeBlock, 0, 1);

    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];

    for (int i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, (void *)&readerIds[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, (void *)&writerIds[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&readBlock);
    sem_destroy(&writeBlock);

    return 0;
}
