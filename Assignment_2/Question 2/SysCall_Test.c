#include <stdio.h>
#include <unistd.h>

#define KERNEL_2D_MEMCPY 451

void Print(int n , float arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%g " , arr[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    float sourceArray[5][5] = {{1.1   , 2.2   , 3.3   , 4.4   , 5.5},
                               {6.6   , 7.7   , 8.8   , 9.9   , 10.10},
                               {11.11 , 12.12 , 13.13 , 14.14 , 15.15},
                               {16.16 , 17.17 , 18.18 , 19.19 , 20.20},
                               {21.21 , 22.22 , 23.23 , 24.24 , 25.25}};
    
    float destinationArray[5][5];

    printf("\nSource Array:- \n\n");
    Print(5 , sourceArray); 


    int status = syscall(KERNEL_2D_MEMCPY , sourceArray , destinationArray);

    if (status == 0)
    {
        printf("\n\n");
        printf("Destination After (After Copy):- \n\n");
        Print(5 , destinationArray);
    }

    return 0;
}