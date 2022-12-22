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

    char acknowledgement[1];
    char randomArray[50][6];

    sem_t *sem1 = sem_open("SEM11", O_EXCL);
    sem_t *sem2 = sem_open("SEM22", O_EXCL);
    sem_t *sem3 = sem_open("SEM33", O_EXCL);

    fd = shm_open("SHMM", O_RDONLY | O_CREAT | O_RDWR, 0666);
    
    SHM = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (fd != -1)
    {
        for (int i = 0; i < 50; i++)
        {
            sem_wait(sem2);

            strcpy(randomArray[i], (char *)SHM);

            printf("ID (Index) of the String Sent by Process P1: %d\n", (randomArray[i][0] + 1));

            printf("String Sent By Process P1: ");

            for (int j = 1; j < 6; j++)
            {
                printf("%c", randomArray[i][j]);
            }

            printf("\n\n");

            acknowledgement[0] = randomArray[i][0];

            sem_post(sem1);

            memset(SHM, 0, 4096);

            sprintf(SHM, "%s", acknowledgement);

            sem_post(sem3);
        }

        sem_unlink("SEM11");
        sem_unlink("SEM22");
        sem_unlink("SEM33");

        unlink("SHMM");
    }

    return 0;
}