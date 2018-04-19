#include <stdio.h>

int main()
{
	int cnt, column = 0, std = 0;
	
	scanf("%d", &cnt);
	
	column = cnt / 2;
	if (cnt % 2 != 0)
		column++;
	
	for (int i = 0; i < column; i++)
	{
		std = i;
		for (int j = 0; j < cnt; j++)
		{
			if (j >= std) printf("*");
			else printf(" ");
		}
		printf("\n");
		cnt--;
	}
	for (int i = 0; i < column - 1; i++)
	{
		if (i == 0)
		{
			cnt += 2;
			std--;
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