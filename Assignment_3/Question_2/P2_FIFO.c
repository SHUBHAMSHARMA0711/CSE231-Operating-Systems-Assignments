#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    int fd;

    int acknowledgement[1];
    char randomArray[50][6];

    mkfifo("FIFO", 0666);

    for (int i = 0; i < 50; i++)
    {
        fd = open("FIFO", O_RDONLY);

        if (fd != -1)
        {
            if (read(fd, randomArray[i], sizeof(randomArray[i])) != -1)
            {
                close(fd);

                printf("ID (Index) of the String Sent by Process P1: %d\n", (randomArray[i][0] + 1));

                printf("String Sent By Process P1: ");

                for (int j = 1; j < 6; j++)
                {
                    printf("%c", randomArray[i][j]);
                }

                printf("\n\n");

                acknowledgement[0] = randomArray[i][0];

                fd = open("FIFO", O_WRONLY);

                if (fd != -1)
                {
                    if (write(fd, acknowledgement, sizeof(acknowledgement)) != -1)
                    {
                        close(fd);
                    }

                    else
                    {
                        printf("Process P2 Failed to Write Acknowledgement\n");
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
                printf("Failed to Read From FIFO\n");
                exit(1);
            }
        }

        else
        {
            printf("Failed to Open FIFO\n");
            exit(1);
        }
    }

    return 0;
}