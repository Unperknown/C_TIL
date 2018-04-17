#include <stdio.h>

int main()
{
	int i, j, k, size, temp;
	
	scanf("%d", &size);
	
	if (size % 2 != 0)
	{
		for (i = 0; i <= size / 2; i++)
		{
			for (j = 0; j < i; j++) printf(" ");
			for (k = 0; k < size - 2 * i; k++) printf("*");
		}
		for (i = size / 2 + 1; i < size; i++)
		{
			temp -= i;
			for (j = 0; j < temp; j++) printf(" ");
			for (k = 0; k < size - 2 * temp; k++) printf("*");
			printf("\n");
		}
	}
	else
		printf("Please input odd number instead.");

	return 0;
}