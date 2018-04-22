#include <stdio.h>
#include <stdlib.h>
     
int main()
{
    int **hwA = malloc(sizeof(int *) * 10);
     
    for (int i = 0; i < 10; i++)
        hwA[i] = malloc(sizeof(int) * 10);
     
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &hwA[i][j]);
        }
    }
     
    int row = 1, column = 1;
     
    while (1)
    {
        if (hwA[row][column + 1] == 0)
        {
            hwA[row][column] = 9;
            column++;
        }
        else if (hwA[row][column + 1] == 1 && hwA[row + 1][column] == 0)
        {
            hwA[row][column] = 9;
            row++;
        }
        else if (hwA[row][column + 1] == 1 && hwA[row + 1][column] == 2)
        {
            hwA[row][column] = 9;
            row++;
            break;
        }
        else
            break;
    }
     
    hwA[row][column] = 9;
     
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", hwA[i][j]);
        }
         
        printf("\n");
    }
     
    for (int i = 0; i < 10; i++)
        free(hwA[i]);
     
    free(hwA);
     
    return 0;
}