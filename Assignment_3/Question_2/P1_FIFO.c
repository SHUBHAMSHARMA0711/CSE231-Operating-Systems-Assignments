#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    int fd;

    struct timespec start_time;
    struct timespec end_timeee;

    srand(time(NULL));

    int acknowledgement[1];
    char randomArray[50][6];

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            randomArray[j][0] = j;
            randomArray[j][i] = rand() % 26 + 65;
        }
    }

    mkfifo("FIFO", 0666);

    clock_gettime(CLOCK_REALTIME, &start_time);

    for (int i = 0; i < 50; i++)
    {
        fd = open("FIFO", O_WRONLY);

        if (fd != -1)
        {
            if (write(fd, randomArray[i], sizeof(randomArray[i])) != -1)
            {
                close(fd);

                fd = open("FIFO", O_RDONLY);

                if (fd != -1)
                {
                    if (read(fd, &acknowledgement[0], sizeof(acknowledgement[0])) != -1)
                    {
                        close(fd);

                        if ((acknowledgement[0] + 1) % 5 == 0)
                        {
                            printf("Received Acknowledgement Packet ID from Process P2: %d\n\n", (acknowledgement[0] + 1));
                        }
                    }

                    else
                    {
                        printf("Failed to Read Acknowledgement\n");
                        exit(1);
                    }
                }

                else
                {
                    printf("Failed to Open FIFO\n");
                    exit(1);
                }
            }

            else
            {
                printf("Process P1 Failed to Write in FIFO\n");
                exit(1);
            }
        }

        else
        {
            printf("Failed to Open FIFO\n");
            exit(1);
        }
    }

    clock_gettime(CLOCK_REALTIME, &end_timeee);

    printf("Total Time: %lf Seconds\n", ((end_timeee.tv_sec - start_time.tv_sec) + (double)(end_timeee.tv_nsec - start_time.tv_nsec) / 1000000000));

    return 0;
}