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
     
    int column = 1, row = 1;
     
    while (1)
    {
        if (hwA[column][row + 1] == 0)
        {
            hwA[column][row] = 9;
            row++;
        }
        else if (hwA[column][row + 1] == 1 && hwA[column + 1][row] == 0)
        {
            hwA[column][row] = 9;
            column++;
        }
        else if (hwA[column][row + 1] == 1 && hwA[column + 1][row] == 2)
        {
            hwA[column][row] = 9;
            column++;
            break;
        }
        else
            break;
    }
     
    hwA[column][row] = 9;
     
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