/* hourGlass.c -- 역피라미드를 출력하는데 열의 중간 부분부터 피라미드를 출력하는 프로그램 */
#include <stdio.h>

int main()
{
	int i, j, k, size, temp;
	
	scanf("%d", &size);
	
	if (size % 2 != 0)
	{
		for (i = 0; i < size; i++)
		{
			if (i <= size / 2)
			{
				temp = i;
				for (j = 0; j < i; j++) printf(" ");
				for (k = 0; k < size - 2 * i; k++) printf("*");
			}
			else
			{
				temp--;
				for (j = 0; j < temp; j++) printf(" ");
				for (k = 0; k < size - 2 * temp; k++) printf("*");
			}
			printf("\n");
		}
	}
	else
		printf("Please input odd number instead.");

	return 0;
}