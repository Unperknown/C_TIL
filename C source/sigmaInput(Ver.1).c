/* *****
   ****
   ***
   **
   *
   **
   ***
   ****
   ***** 출력하기 */

#include <stdio.h>

int main()
{
	int row, column;
	
	scanf("%d", &row);
	
	column = row;
	
	for (int i = 0; i < column - 1; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("*");
		}
		printf("\n");
		row--;
	}
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("*");
		}
		printf("\n");
		row++;
	}
	
	return 0;
}