#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 20
#define TIME_SLICE 15

typedef struct {
    int job_id;
    int priority;
    int arrival_time;
    int *burst_times;
    int burst_count;
} Job;

typedef struct {
    Job *jobs[MAX_JOBS];
    int job_count;
} JobQueue;

void initialize_job_queue(JobQueue *queue) {
    queue->job_count = 0;
}

void enqueue_job(JobQueue *queue, Job *job) {
    if (queue->job_count < MAX_JOBS) {
        queue->jobs[queue->job_count++] = job;
    } else {
        printf("Job queue is full. Cannot enqueue more jobs.\n");
    }
}

Job *dequeue_job(JobQueue *queue) {
    if (queue->job_count > 0) {
        Job *job = queue->jobs[0];
        for (int i = 0; i < queue->job_count - 1; ++i) {
            queue->jobs[i] = queue->jobs[i + 1];
        }
        queue->job_count--;
        return job;
    } else {
        return NULL;
    }
}

void read_job_profile(FILE *file, Job *job) {
    fscanf(file, "%d %d %d", &job->job_id, &job->priority, &job->arrival_time);

    job->burst_count = 0;
    job->burst_times = malloc(sizeof(int) * 100);  // Assuming a maximum of 100 burst times

    int burst_time;
    while (fscanf(file, "%d", &burst_time) == 1 && burst_time != -1) {
        job->burst_times[job->burst_count++] = burst_time;
    }
}

void print_job_profile(Job *job) {
    printf("Job %d (Priority: %d, Arrival Time: %d, Burst Times: ", job->job_id, job->priority, job->arrival_time);
    for (int i = 0; i < job->burst_count; ++i) {
        printf("%d ", job->burst_times[i]);
    }
    printf(")\n");
}

void schedule_priority(JobQueue *job_queue) {
    // Implement Priority Scheduling Algorithm
    // Sort jobs based on priority (lower priority numbers have higher priority)
    for (int i = 0; i < job_queue->job_count - 1; ++i) {
        for (int j = 0; j < job_queue->job_count - i - 1; ++j) {
            if (job_queue->jobs[j]->priority > job_queue->jobs[j + 1]->priority) {
                // Swap jobs
                Job *temp = job_queue->jobs[j];
                job_queue->jobs[j] = job_queue->jobs[j + 1];
                job_queue->jobs[j + 1] = temp;
            }
        }
    }

    // Process jobs in sorted order
    for (int i = 0; i < job_queue->job_count; ++i) {
        Job *current_job = job_queue->jobs[i];

        if (current_job->burst_count > 0) {
            int burst_time = current_job->burst_times[0];
            printf("Processing Job %d with priority %d for burst time %d\n", current_job->job_id, current_job->priority, burst_time);

            // Reduce burst time based on the burst time
            current_job->burst_times[0] = 0;

            printf("Job %d completed.\n", current_job->job_id);
            free(current_job->burst_times);
            free(current_job);
        }
    }
}


void schedule_round_robin(JobQueue *job_queue) {
    while (job_queue->job_count > 0) {
        Job *current_job = dequeue_job(job_queue);

        if (current_job->burst_count > 0) {
            int time_slice = (current_job->burst_times[0] > TIME_SLICE) ? TIME_SLICE : current_job->burst_times[0];
            printf("Processing Job %d for time slice %d\n", current_job->job_id, time_slice);

            // Reduce burst time based on the time slice
            current_job->burst_times[0] -= time_slice;

            // If the job still has burst time left, enqueue it for the next round
            if (current_job->burst_times[0] > 0) {
                enqueue_job(job_queue, current_job);
            } else {
                printf("Job %d completed.\n", current_job->job_id);
                free(current_job->burst_times);
                free(current_job);
            }
        } else {
            free(current_job->burst_times);
            free(current_job);
        }
    }
}


int main() {
    FILE *file = fopen("job_profiles.txt", "r");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    JobQueue job_queue;
    initialize_job_queue(&job_queue);

    while (job_queue.job_count < MAX_JOBS) {
        Job *new_job = malloc(sizeof(Job));
        read_job_profile(file, new_job);
        if (feof(file)) {
            free(new_job);
            break;
        }
        enqueue_job(&job_queue, new_job);
    }

    fclose(file);

    // Choose scheduling algorithm
    int choice;
    printf("Choose scheduling algorithm:\n");
    printf("1. Priority Scheduling\n");
    printf("2. Round Robin Scheduling\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            schedule_priority(&job_queue);
            break;
        case 2:
            schedule_round_robin(&job_queue);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
