#include <time.h>
#include <stdio.h>
#include <pthread.h>

int i = 9;
double time1;
double time2;
double time3;

void *countA(void *arguments)
{
    struct sched_param priority;

    struct timespec launchh_time;
    struct timespec joining_time;

    priority.sched_priority = 0;

    printf("Thread A Current Priority: %d\n", priority.sched_priority);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &launchh_time);

    pthread_setschedparam(pthread_self(), SCHED_OTHER, &priority);

    for (long int i = 1; i <= 4294967296; i++) {}

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &joining_time);

    time1 = (joining_time.tv_sec - launchh_time.tv_sec) + (double)(joining_time.tv_nsec - launchh_time.tv_nsec) / 1000000000;
    printf("Thread A: %lf\n", time1);
}

void *countB(void *arguments)
{
    struct sched_param priority;

    struct timespec launchh_time;
    struct timespec joining_time;

    priority.sched_priority = i;

    printf("Thread B Current Priority: %d\n", priority.sched_priority);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &launchh_time);

    pthread_setschedparam(pthread_self(), SCHED_RR, &priority);

    for (long int i = 1; i <= 4294967296; i++) {}

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &joining_time);

    time2 = (joining_time.tv_sec - launchh_time.tv_sec) + (double)(joining_time.tv_nsec - launchh_time.tv_nsec) / 1000000000;
    printf("Thread B: %lf\n", time2);
}

void *countC(void *arguments)
{
    struct sched_param priority;

    struct timespec launchh_time;
    struct timespec joining_time;

    priority.sched_priority = i;

    printf("Thread C Current Priority: %d\n", priority.sched_priority);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &launchh_time);

    pthread_setschedparam(pthread_self(), SCHED_FIFO, &priority);

    for (long int i = 1; i <= 4294967296; i++) {}

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &joining_time);

    time3 = (joining_time.tv_sec - launchh_time.tv_sec) + (double)(joining_time.tv_nsec - launchh_time.tv_nsec) / 1000000000;
    printf("Thread C: %lf\n", time3);
}

int main()
{
    FILE *file;
    file = fopen("question_1_1_Time.txt", "w");

    for (int j = 0; j < 10; j++)
    {
        pthread_t Thr_A;
        pthread_t Thr_B;
        pthread_t Thr_C;

        pthread_attr_t Thr_A_attr;
        pthread_attr_t Thr_B_attr;
        pthread_attr_t Thr_C_attr;

        pthread_attr_init(&Thr_A_attr);
        pthread_attr_init(&Thr_B_attr);
        pthread_attr_init(&Thr_C_attr);

        printf("\n");

        pthread_create(&Thr_A, &Thr_A_attr, countA, NULL);
        pthread_create(&Thr_B, &Thr_B_attr, countB, NULL);
        pthread_create(&Thr_C, &Thr_C_attr, countC, NULL);

        pthread_join(Thr_A, NULL);
        pthread_join(Thr_B, NULL);
        pthread_join(Thr_C, NULL);

        printf("\n");

        fprintf(file, "%lf, ", time1);
        fprintf(file, "%lf, ", time2);
        fprintf(file, "%lf, ", time3);

        i = i + 10;
    }

    fclose(file);

    return 0;
}