#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

int main()
{
    int fd;
    void *SHM;

    struct timespec start_time;
    struct timespec end_timeee;

    srand(time(NULL));

    char acknowledgement[1];
    char randomArray[50][6];

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            randomArray[j][0] = j;
            randomArray[j][i] = rand() % 26 + 65;
        }
    }

    sem_t *sem1 = sem_open("SEM11", O_CREAT, 0666, 1);
    sem_t *sem2 = sem_open("SEM22", O_CREAT, 0666, 0);
    sem_t *sem3 = sem_open("SEM33", O_CREAT, 0666, 0);

    fd = shm_open("SHMM", O_CREAT | O_RDWR, 0666);

    ftruncate(fd, 4096);

    SHM = mmap(0, 4096, PROT_WRITE, MAP_SHARED, fd, 0);

    if (fd != -1)
    {
        clock_gettime(CLOCK_REALTIME, &start_time);

        for (int i = 0; i < 50; i++)
        {
            sem_wait(sem1);

            sprintf(SHM, "%s", randomArray[i]);

            sem_post(sem2);

            sem_wait(sem3);

            strcpy(&acknowledgement[0], (char *)SHM);

            if ((acknowledgement[0] + 1) % 5 == 0)
            {
                printf("Received Acknowledgement Packet ID from Process P2: %d\n\n", (acknowledgement[0] + 1));
            }

            memset(SHM, 0, 4096);
        }

        clock_gettime(CLOCK_REALTIME, &end_timeee);

        sem_unlink("SEM11");
        sem_unlink("SEM22");
        sem_unlink("SEM33");

        unlink("SHMM");

        printf("Total Time: %lf Seconds\n", ((end_timeee.tv_sec - start_time.tv_sec) + (double)(end_timeee.tv_nsec - start_time.tv_nsec) / 1000000000));
    }

    else
    {
        printf("Failed to Create Shared Memory Segment\n");
        exit(1);
    }

    return 0;
}