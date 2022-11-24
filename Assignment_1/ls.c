#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void ls(char *arr[])
{
    char cwd[10000];
    getcwd(cwd, 10000);

    struct dirent **files;

    int size = scandir(cwd, &files, NULL, alphasort);

    if (arr[1] != NULL)
    {
        if (!strcmp(arr[1], "-a\n") || !strcmp(arr[1], "-a"))
        {
            for (int i = 0; i < size; i++)
            {
                char f[20];
                strncpy(f, files[i]->d_name, 20);

                printf("%s  ", f);
            }
            printf("\n");
        }

        else if (!strcmp(arr[1], "-m\n") || !strcmp(arr[1], "-m"))
        {
            for (int i = 0; i < size; i++)
            {
                char f[20];
                strncpy(f, files[i]->d_name, 20);

                if ((int)f[0] != 46)
                {
                    printf("%s, ", f);
                }
            }
            printf("\n");
        }

        else
        {
            printf("ls: invalid option  %s\n", arr[1]);
        }
    }

    else
    {
        for (int i = 0; i < size; i++)
        {
            char f[20];
            strncpy(f, files[i]->d_name, 20);

            if ((int)f[0] != 46)
            {
                printf("%s  ", f);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    char *arr[] = {argv[1], argv[2]};
    ls(arr);

    return 0;
}
