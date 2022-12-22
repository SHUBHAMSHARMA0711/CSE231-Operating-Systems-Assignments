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

    int acknowledgement[1];
    char randomArray[50][6];

    struct sockaddr_un address;

    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "SOCKET");

    fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);

    if (fd != -1)
    {
        unlink("SOCKET");

        if (bind(fd, (struct sockaddr *)&address, sizeof(address)) != -1)
        {
            if (listen(fd, 100) != -1)
            {
                fd = accept(fd, NULL, NULL);

                if (fd != -1)
                {
                    for (int i = 0; i < 50; i++)
                    {
                        if (recv(fd, randomArray[i], sizeof(randomArray[i]), 0) != -1)
                        {
                            printf("ID (Index) of the String Sent by Process P1: %d\n", (randomArray[i][0] + 1));

                            printf("String Sent By Process P1: ");

                            for (int j = 1; j < 6; j++)
                            {
                                printf("%c", randomArray[i][j]);
                            }

                            printf("\n\n");

                            acknowledgement[0] = randomArray[i][0];

                            if (send(fd, acknowledgement, sizeof(acknowledgement), 0) == -1)
                            {
                                printf("Failed to Send Acknowledgement to Process P1\n");
                                exit(1);
                            }
                        }

                        else
                        {
                            printf("Failed to Read Data Sent by Process P1\n");
                            exit(1);
                        }
                    }
                }

                else
                {
                    printf("Failed to Accept\n");
                    exit(1);
                }
            }

            else
            {
                printf("Failed to Listen\n");
                exit(1);
            }
        }

        else
        {
            printf("Failed to Bind\n");
            exit(1);
        }

        close(fd);
    }

    else
    {
        printf("Failed to Make Socket\n");
        exit(1);
    }

    return 0;
}