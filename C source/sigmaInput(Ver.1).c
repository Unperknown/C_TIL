/* sigmainput(Ver.1).c - 
   ***
   **
   *
   **
   *** 출력 프로그램(단, 입력 값은 행의 별 갯수) */

#include <stdio.h>

int main()
{
	int row, column;
	
	scanf("%d", &row);
	
	column = row; //행의 별 갯수는 역삼각형 및 삼각형의 열 갯수와 같음
	
	for (int i = 0; i < column - 1; i++) //열 갯수는 역삼각형을 출력하거나 삼각형을 출력할 때 하나를 줄임
	{
		for (int j = 0; j < row; j++)
		{
			printf("*");
		}
		printf("\n");
		row--; //역삼각형은 row를 기준으로 별의 갯수를 줄임
	}
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("*");
		}
		printf("\n");
		row++; //삼각형은 row를 기준으로 별의 갯수를 늘림
	}
	
	return 0;
}