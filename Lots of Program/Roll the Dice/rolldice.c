#include <stdio.h>
#include "randroll.h"

int sides, dice, cnt;

int main()
{
	char ch;
	do
	{
		printf("How much you want to roll?\n< ");
		if (scanf("%d", &cnt) != 1)
		{
			printf("Incorrect value.\n");
			end();
		}
		printf("Input dice's sides and dice.\n< ");
		if (scanf("%d %d", &sides, &dice) != 2 || sides < 3 || dice < 1)
		{
			printf("Incorrect value.\n");
			end();
		}
		print_roll();
		getchar();
		printf("Want to play again?\nInput 'a' to continue.(Press any key if you want to quit.)\n< ");
	} while ((ch = getchar()) == 'a');
	
	end();
	
	return 0;
}