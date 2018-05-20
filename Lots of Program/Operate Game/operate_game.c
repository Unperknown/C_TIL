#include <stdio.h>
#include <stdlib.h>
#include "data.h"

double a, b;
int choose;

int main()
{
	int status;
	char ch[100], ch2;
	
	do
	{
		print_game();
		printf("Input two number.\n< ");
		status = scanf("%lf %lf", &a, &b);
		if (status != 2)
		{
			printf("Incorrect number.\n");
			gets(ch);
			gets(ch);
			exit(EXIT_FAILURE);
		}
		printf("Choose operate.\n< ");
		status = scanf("%d", &choose);
		if (status != 1 || choose < 1 || choose > 4)
		{
			printf("Incorrect value.\n");
			gets(ch);
			gets(ch);
			exit(EXIT_FAILURE);
		}
		getchar();
		printf("Result is %.10g!\n", operate(a, b));
		printf("Want to do it again?\nInput A to continue.\n< ");
	} while ((ch2 = getchar()) == 'A');
	
	printf("Press any key to continue. . .");
	getchar();
	getchar();
	
	return 0;
}