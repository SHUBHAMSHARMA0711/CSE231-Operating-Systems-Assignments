#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int forks[5];

void *Table(void *argument)
{
    int *arg = argument;

    while (1)
    {
        printf("\nPhilosopher %d is Thinking\n\n", *arg + 1);

        if (!forks[*arg])
        {
            forks[*arg] = 1;
            printf("Philosopher %d Takes Left  Side Fork\n", *arg + 1);
        }

        if (!forks[(*arg + 1) % 5])
        {
            forks[(*arg + 1) % 5] = 1;
            printf("Philosopher %d Takes Right Side Fork\n", *arg + 1);
        }

        else
        {
            forks[*arg] = 0;
        }

        printf("\nPhilosopher %d is Eating\n\n", *arg + 1);
        sleep(3);

        forks[*arg] = 0;
        printf("Philosopher %d Puts  Left  Side Fork\n", *arg + 1);

        forks[(*arg + 1) % 5] = 0;
        printf("Philosopher %d Puts  Right Side Fork\n", *arg + 1);
    }
}

int main()
{
    forks[0] = 0;
    forks[1] = 0;
    forks[2] = 0;
    forks[3] = 0;
    forks[4] = 0;

    int philID_1 = 0;
    int philID_2 = 1;
    int philID_3 = 2;
    int philID_4 = 3;
    int philID_5 = 4;

    pthread_t philosopher_1;
    pthread_t philosopher_2;
    pthread_t philosopher_3;
    pthread_t philosopher_4;
    pthread_t philosopher_5;

    pthread_create(&philosopher_1, NULL, Table, &philID_1);
    pthread_create(&philosopher_2, NULL, Table, &philID_2);
    pthread_create(&philosopher_3, NULL, Table, &philID_3);
    pthread_create(&philosopher_4, NULL, Table, &philID_4);
    pthread_create(&philosopher_5, NULL, Table, &philID_5);

    pthread_join(philosopher_1, NULL);
    pthread_join(philosopher_2, NULL);
    pthread_join(philosopher_3, NULL);
    pthread_join(philosopher_4, NULL);
    pthread_join(philosopher_5, NULL);

    return 0;
}