/* hourGlass(Ver.2).c -- 행의 최대 갯수를 입력받아 역피라미드를 출력하고 열의 중간 부분부터 피라미드를 출력하는 프로그램 */
#include <stdio.h>

int main()
{
	int cnt, column = 0, std = 0;
	
	scanf("%d", &cnt);
	
	column = cnt / 2; //역피라미드를 출력할 때 열의 갯수는 행의 최대 갯수를 반으로 나눈 값과 같음
	if (cnt % 2 != 0) //행의 최대 갯수가 홀수이면 행의 갯수가 1개일 때까지 역피라미드를 출력하므로
		column++; //열 갯수를 하나 더 늘림
	
	for (int i = 0; i < column; i++)
	{
		std = i;
		for (int j = 0; j < cnt; j++)
		{
			if (j >= std) printf("*"); //역피라미드에서 공백과 별의 기준이 되는 변수 std는 i의 값과 같고 std가 증가할수록 공백이 생기고 별의 갯수가 줄어듬
			else printf(" ");
		}
		printf("\n"); //한 열을 출력하고 줄바꿈
		cnt--; //역피라미드의 별의 갯수를 줄어들게 하는 문장
	}
	for (int i = 0; i < column - 1; i++)
	{
		if (i == 0)
		{
			cnt += 2;
			std--; //피라미드를 출력하기 위해 역피라미드의 문장의 반대로 함
		}
		else
		{
			cnt++;
			std--;
		}
		for (int j = 0; j < cnt; j++)
		{
			if (j >= std) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}