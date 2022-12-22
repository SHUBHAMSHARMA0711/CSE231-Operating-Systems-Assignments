#include <time.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>

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

    struct sockaddr_un adderess;

    adderess.sun_family = AF_UNIX;
    strcpy(adderess.sun_path, "SOCKET");

    fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);

    if (fd != -1)
    {
        if (connect(fd, (struct sockaddr *)&adderess, sizeof(adderess)) != -1)
        {
            clock_gettime(CLOCK_REALTIME, &start_time);

            for (int i = 0; i < 50; i++)
            {
                if (send(fd, randomArray[i], sizeof(randomArray[i]), 0) != -1)
                {
                    if (recv(fd, &acknowledgement[0], sizeof(acknowledgement[0]), 0) != -1)
                    {
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
                    printf("Failed to Write Data\n");
                    exit(1);
                }
            }

            clock_gettime(CLOCK_REALTIME, &end_timeee);

            printf("Total Time: %lf Seconds\n", ((end_timeee.tv_sec - start_time.tv_sec) + (double)(end_timeee.tv_nsec - start_time.tv_nsec) / 1000000000));
        }

        else
        {
            printf("Connection Failed\n");
            exit(1);
        }

        close(fd);
    }

    else
    {
        printf("Failed to Create Socket\n");
        exit(1);
    }

    return 0;
}