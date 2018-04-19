/* *****
   ****
   ***
   **
   *
   **
   ***
   ****
   ***** 출력하기 (ver.2 - 세로 줄의 갯수를 입력하여 출력함)*/
#include <stdio.h>

int main()
{
	int row, column, temp;
	
	scanf("%d", &column);
	
	row = column / 2;
	if (column % 2 != 0) row++;
	else
	{
		printf("Please input odd number instead.");
		return 0;
	}
	temp = row;
	
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < temp; j++)
		{
			printf("*");
		}
		printf("\n");
		temp--;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < temp; j++)
		{
			printf("*");
		}
		printf("\n");
		temp++;
	}
	
	return 0;
}