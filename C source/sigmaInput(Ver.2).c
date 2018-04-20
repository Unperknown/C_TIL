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
	if (column % 2 != 0) row++; //세로 줄의 갯수는 행의 별 갯수를 반으로 나눈 값에서 하나를 더한 값과 같음
	else
	{
		printf("Please input odd number instead."); //이 도형은 절대로 열의 갯수가 짝수일 수 없으므로 짝수를 입력하면 종료시킴
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