#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t bowls[2];
sem_t forks[5];

void *Table(void *argument)
{
    int *arg = argument;

    while (1)
    {
        printf("\nPhilosopher %d is Thinking\n\n", *arg + 1);

        sem_wait(&bowls[*arg % 2]);
        printf("Philosopher %d Takes Bowl No. %d\n", *arg + 1, (*arg % 2) + 1);

        if (*arg % 2 == 0)
        {
            sem_wait(&forks[*arg]);
            printf("Philosopher %d Takes Left  Side Fork\n", *arg + 1);

            sem_wait(&forks[(*arg + 1) % 5]);
            printf("Philosopher %d Takes Right Side Fork\n", *arg + 1);
        }

        else
        {
            sem_wait(&forks[(*arg + 1) % 5]);
            printf("Philosopher %d Takes Right Side Fork\n", *arg + 1);

            sem_wait(&forks[*arg]);
            printf("Philosopher %d Takes Left  Side Fork\n", *arg + 1);
        }

        printf("\nPhilosopher %d is Eating\n\n", *arg + 1);
        sleep(3);

        sem_post(&forks[*arg]);
        printf("Philosopher %d Puts  Left  Side Fork\n", *arg + 1);

        sem_post(&forks[(*arg + 1) % 5]);
        printf("Philosopher %d Puts  Right Side Fork\n", *arg + 1);

        sem_post(&bowls[*arg % 2]);
        printf("Philosopher %d Puts Bowl No. %d\n", *arg + 1, (*arg % 2) + 1);
    }
}

int main()
{
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

    sem_init(&bowls[0], 0, 1);
    sem_init(&bowls[1], 0, 1);

    sem_init(&forks[0], 0, 1);
    sem_init(&forks[1], 0, 1);
    sem_init(&forks[2], 0, 1);
    sem_init(&forks[3], 0, 1);
    sem_init(&forks[4], 0, 1);

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