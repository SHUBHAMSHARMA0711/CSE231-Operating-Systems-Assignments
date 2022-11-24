#include <time.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int s1;
    int s2;
    int s3;

    struct sched_param classA;
    struct sched_param classB;
    struct sched_param classC;

    struct timespec process_A_start_time;
    struct timespec process_A_enddd_time;

    struct timespec process_B_start_time;
    struct timespec process_B_enddd_time;

    struct timespec process_C_start_time;
    struct timespec process_C_enddd_time;

    clock_gettime(1, &process_A_start_time);

    pid_t f1 = fork();

    if (f1 == -1)
    {
        printf("Fork Error (Child Process Not Created)");
        exit(1);
    }

    else if (f1 == 0)
    {
        printf("Process A Started\n");

        classA.sched_priority = 0;

        sched_setscheduler(f1, SCHED_OTHER, &classA);

        chdir("/home/shubham/ProcessA");

        char *test[] = {"/home/shubham/./bashScript.sh", NULL};
        execvp(test[0], test);

        return 0;
    }

    clock_gettime(1, &process_B_start_time);

    pid_t f2 = fork();

    if (f2 == -1)
    {
        printf("Fork Error (Child Process Not Created)");
        exit(1);
    }

    else if (f2 == 0)
    {
        printf("Process B Started\n");

        classB.sched_priority = 50;

        sched_setscheduler(f2, SCHED_RR, &classB);

        chdir("/home/shubham/ProcessB");

        char *test[] = {"/home/shubham/./bashScript.sh", NULL};
        execvp(test[0], test);

        return 0;
    }

    clock_gettime(1, &process_C_start_time);

    pid_t f3 = fork();

    if (f3 == -1)
    {
        printf("Fork Error (Child Process Not Created)");
        exit(1);
    }

    else if (f3 == 0)
    {
        printf("Process C Started\n");

        classC.sched_priority = 50;

        sched_setscheduler(f3, SCHED_FIFO, &classC);

        chdir("/home/shubham/ProcessC");

        char *test[] = {"/home/shubham/./bashScript.sh", NULL};
        execvp(test[0], test);

        return 0;
    }

    printf("\n");

    pid_t a = waitpid(-1, &s1, 0);

    if (a == f1)
    {
        clock_gettime(1, &process_A_enddd_time);
        printf("\n\nProcess A Ended\n\n");
    }

    else if (a == f2)
    {
        clock_gettime(1, &process_B_enddd_time);
        printf("\n\nProcess B Ended\n\n");
    }

    else if (a == f3)
    {
        clock_gettime(1, &process_C_enddd_time);
        printf("\n\nProcess C Ended\n\n");
    }

    pid_t b = waitpid(-1, &s2, 0);

    if (b == f1)
    {
        clock_gettime(1, &process_A_enddd_time);
        printf("\n\nProcess A Ended\n\n");
    }

    else if (b == f2)
    {
        clock_gettime(1, &process_B_enddd_time);
        printf("\n\nProcess B Ended\n\n");
    }

    else if (b == f3)
    {
        clock_gettime(1, &process_C_enddd_time);
        printf("\n\nProcess C Ended\n\n");
    }

    pid_t c = waitpid(-1, &s3, 0);

    if (c == f1)
    {
        clock_gettime(1, &process_A_enddd_time);
        printf("\n\nProcess A Ended\n\n");
    }

    else if (c == f2)
    {
        clock_gettime(1, &process_B_enddd_time);
        printf("\n\nProcess B Ended\n\n");
    }

    else if (c == f3)
    {
        clock_gettime(1, &process_C_enddd_time);
        printf("\n\nProcess C Ended\n\n");
    }

    printf("\n\n");

    double time1 = (process_A_start_time.tv_sec - process_A_enddd_time.tv_sec) + (double)(process_A_start_time.tv_nsec - process_A_enddd_time.tv_nsec) / 1000000000;
    printf("Process A Time (SCHED_OTHER): %lf\n", -time1);

    double time2 = (process_B_start_time.tv_sec - process_B_enddd_time.tv_sec) + (double)(process_B_start_time.tv_nsec - process_B_enddd_time.tv_nsec) / 1000000000;
    printf("Process B Time (SCHED_RR)   : %lf\n", -time2);

    double time3 = (process_C_start_time.tv_sec - process_C_enddd_time.tv_sec) + (double)(process_C_start_time.tv_nsec - process_C_enddd_time.tv_nsec) / 1000000000;
    printf("Process C Time (SCHED_FIFO) : %lf\n", -time3);

    printf("\n\n");

    FILE *file;
    file = fopen("question_1_2_Time.txt", "w");

    fprintf(file, "%lf, ", -time1);
    fprintf(file, "%lf, ", -time2);
    fprintf(file, "%lf ", -time3);

    fclose(file);

    return 0;
}