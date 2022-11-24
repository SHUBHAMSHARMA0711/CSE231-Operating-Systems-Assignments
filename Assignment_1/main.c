#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <pthread.h>

int main()
{
    printf("\n\n******************** WELCOME TO MY SHELL ********************\n\n");

    char original_directory[10000];
    getcwd(original_directory, 10000);

    while (1)
    {
        char cwd[10000];
        getcwd(cwd, 10000);

        printf("\nshubham21099@DESKTOP-IP0PV11:%s $ ", cwd);

        char input[10000];
        fgets(input, sizeof(input), stdin);

        int i = 0;
        char *cmdArr[10000];
        char *cmd = strtok(input, " ");

        while (cmd != NULL)
        {
            cmdArr[i] = cmd;
            cmd = strtok(NULL, " ");
            i++;
        }

        void *function(void *arguments)
        {
            system(arguments);
        }

        char arrr[20000];
        char path[20000];

        if (!strcmp(cmdArr[0], "cd\n") || !strcmp(cmdArr[0], "cd"))
        {
            if (cmdArr[1] != NULL)
            {
                cmdArr[1][strcspn(cmdArr[1], "\n")] = 0;

                if (!strcmp(cmdArr[1], "~"))
                {
                    chdir(original_directory);
                }

                else if (!chdir(cmdArr[1]))
                {
                }

                else
                {
                    printf("-bash: cd: %s: No such file or directory\n", cmdArr[1]);
                }
            }

            else
            {
                chdir(original_directory);
            }
        }

        else if (!strcmp(cmdArr[0], "echo\n") || !strcmp(cmdArr[0], "echo"))
        {
            if (cmdArr[1] != NULL)
            {
                if (!strcmp(cmdArr[1], "*\n"))
                {
                    struct dirent **files;

                    int size = scandir(cwd, &files, NULL, alphasort);

                    for (int i = 0; i < size; i++)
                    {
                        char f[20];
                        strncpy(f, files[i]->d_name, 20);

                        if ((int)f[0] != 46)
                        {
                            printf("%s ", f);
                        }
                    }
                    printf("\n");
                }

                else if (!strcmp(cmdArr[1], "--help\n"))
                {
                    system("/bin/echo --help");
                }

                else
                {
                    for (int j = 1; j < i; j++)
                    {
                        printf("%s ", *(cmdArr + j));
                    }
                }
            }

            else
            {
                printf("\n");
            }
        }

        else if (!strcmp(cmdArr[0], "pwd\n") || !strcmp(cmdArr[0], "pwd"))
        {
            getcwd(cwd, 10000);

            if (cmdArr[1] != NULL)
            {
                if (!strcmp(cmdArr[1], "-L\n"))
                {
                    printf("%s\n", cwd);
                }

                else if (!strcmp(cmdArr[1], "-P\n"))
                {
                    printf("%s\n", cwd);
                }

                else
                {
                    cmdArr[1][strcspn(cmdArr[1], "\n")] = 0;
                    printf("-bash: pwd: %s: invalid option\n", cmdArr[1]);
                }
            }

            else
            {
                printf("%s\n", cwd);
            }
        }

        else if (!strcmp(cmdArr[0], "ls\n") || !strcmp(cmdArr[0], "ls"))
        {
            strcat(path, original_directory);
            strcat(path, "/./ls");

            if (!strcmp(cmdArr[i - 1], "&t\n"))
            {
                pthread_t thread;

                strcat(arrr, path);
                strcat(arrr, " ");
                strcat(arrr, cmdArr[0]);

                if (strcmp(cmdArr[1], "&t\n"))
                {
                    strcat(arrr, " ");
                    strcat(arrr, cmdArr[1]);
                }

                pthread_create(&thread, NULL, function, (void *)arrr);

                pthread_join(thread, NULL);
            }

            else
            {
                int f = fork();

                if (f == -1)
                {
                    printf("Fork Error (Child Process Not Created)");
                    exit(1);
                }

                else if (f == 0)
                {
                    char *test[] = {path, cmdArr[0], cmdArr[1], NULL};
                    execvp(test[0], test);
                }

                else
                {
                    wait(NULL);
                }
            }
        }

        else if (!strcmp(cmdArr[0], "cat\n") || !strcmp(cmdArr[0], "cat"))
        {
            strcat(path, original_directory);
            strcat(path, "/./cat");

            if (!strcmp(cmdArr[i - 1], "&t\n"))
            {
                pthread_t thread;

                strcat(arrr, path);
                strcat(arrr, " ");
                strcat(arrr, cmdArr[0]);

                if (strcmp(cmdArr[1], "&t\n"))
                {
                    strcat(arrr, " ");
                    strcat(arrr, cmdArr[1]);

                    if (strcmp(cmdArr[2], "&t\n"))
                    {
                        strcat(arrr, " ");
                        strcat(arrr, cmdArr[2]);
                    }
                }

                pthread_create(&thread, NULL, function, (void *)arrr);

                pthread_join(thread, NULL);
            }

            else
            {
                int f = fork();

                if (f == -1)
                {
                    printf("Fork Error (Child Process Not Created)");
                    exit(1);
                }

                else if (f == 0)
                {
                    char *test[] = {path, cmdArr[0], cmdArr[1], cmdArr[2], NULL};
                    execvp(test[0], test);
                }

                else
                {
                    wait(NULL);
                }
            }
        }

        else if (!strcmp(cmdArr[0], "date\n") || !strcmp(cmdArr[0], "date"))
        {
            strcat(path, original_directory);
            strcat(path, "/./date");

            if (!strcmp(cmdArr[i - 1], "&t\n"))
            {
                pthread_t thread;

                strcat(arrr, path);
                strcat(arrr, " ");
                strcat(arrr, cmdArr[0]);

                if (strcmp(cmdArr[1], "&t\n"))
                {
                    strcat(arrr, " ");
                    strcat(arrr, cmdArr[1]);
                }

                pthread_create(&thread, NULL, function, (void *)arrr);

                pthread_join(thread, NULL);
            }

            else
            {
                int f = fork();

                if (f == -1)
                {
                    printf("Fork Error (Child Process Not Created)");
                    exit(1);
                }

                else if (f == 0)
                {
                    char *test[] = {path, cmdArr[0], cmdArr[1], NULL};
                    execvp(test[0], test);
                }

                else
                {
                    wait(NULL);
                }
            }
        }

        else if (!strcmp(cmdArr[0], "rm\n") || !strcmp(cmdArr[0], "rm"))
        {
            strcat(path, original_directory);
            strcat(path, "/./rm");

            if (!strcmp(cmdArr[i - 1], "&t\n"))
            {
                pthread_t thread;

                strcat(arrr, path);
                strcat(arrr, " ");
                strcat(arrr, cmdArr[0]);

                if (strcmp(cmdArr[1], "&t\n"))
                {
                    strcat(arrr, " ");
                    strcat(arrr, cmdArr[1]);

                    if (strcmp(cmdArr[2], "&t\n"))
                    {
                        strcat(arrr, " ");
                        strcat(arrr, cmdArr[2]);
                    }
                }

                pthread_create(&thread, NULL, function, (void *)arrr);

                pthread_join(thread, NULL);
            }

            else
            {
                int f = fork();

                if (f == -1)
                {
                    printf("Fork Error (Child Process Not Created)");
                    exit(1);
                }

                else if (f == 0)
                {
                    char *test[] = {path, cmdArr[0], cmdArr[1], cmdArr[2], NULL};
                    execvp(test[0], test);
                }

                else
                {
                    wait(NULL);
                }
            }
        }

        else if (!strcmp(cmdArr[0], "mkdir\n") || !strcmp(cmdArr[0], "mkdir"))
        {
            strcat(path, original_directory);
            strcat(path, "/./mkdir");

            if (!strcmp(cmdArr[i - 1], "&t\n"))
            {
                pthread_t thread;

                strcat(arrr, path);
                strcat(arrr, " ");
                strcat(arrr, cmdArr[0]);

                if (strcmp(cmdArr[1], "&t\n"))
                {
                    strcat(arrr, " ");
                    strcat(arrr, cmdArr[1]);

                    if (strcmp(cmdArr[2], "&t\n"))
                    {
                        strcat(arrr, " ");
                        strcat(arrr, cmdArr[2]);
                    }
                }

                pthread_create(&thread, NULL, function, (void *)arrr);

                pthread_join(thread, NULL);
            }

            else
            {
                int f = fork();

                if (f == -1)
                {
                    printf("Fork Error (Child Process Not Created)");
                    exit(1);
                }

                else if (f == 0)
                {
                    char *test[] = {path, cmdArr[0], cmdArr[1], cmdArr[2], NULL};
                    execvp(test[0], test);
                }

                else
                {
                    wait(NULL);
                }
            }
        }

        else if (!strcmp(input, "exit\n"))
        {
            printf("\n\nThanks For Using My Shell!!!\n\n");
            exit(0);
        }

        else
        {
            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0)
            {
            }

            else
            {
                fputs(input, stdout);
                printf(": command not found\n");
            }
        }

        memset(input, 0, 10000);
        memset(cmdArr, 0, 10000);
        memset(arrr, 0, 20000);
        memset(path, 0, 20000);
    }
    return 0;
}
