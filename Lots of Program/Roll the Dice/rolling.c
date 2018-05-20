#include <stdio.h>
#include <stdlib.h>
#include "randroll.h"

int rolldice()
{
	int roll;
	
	roll = rand() % sides + 1;
	
	return roll;
}
void print_roll()
{
	int temp = 0;
	
	printf("Result of rolling %d dice(s) with %d sides.\n", dice, sides);
	while (++temp <= cnt) 
	{
		printf("%d ", rolldice());
		if (temp % 7 == 0) printf("\n");
		if (temp == cnt && temp % 7 != 0) printf("\n");
	}
}
void end()
{
	char ch[100];
	printf("Press any key to continue. . .\n");
	gets(ch);
	gets(ch);
	exit(EXIT_FAILURE);
}