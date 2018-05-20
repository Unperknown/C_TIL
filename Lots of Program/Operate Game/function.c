#include <stdio.h>
#include "data.h"

void bar();

void bar()
{
	for (int i = 0; i < 35; i++) printf("-");
	printf("\n");
}
void print_game()
{
	printf("\n");
	bar();
	printf("1. PLUS(+)\n");
	printf("2. MINUS(-)\n");
	printf("3. MULTIPLE(*)\n");
	printf("4. DIVIDE(/)\n");
	bar();
}
double operate(double a, double b)
{
	switch (choose)
	{
		case 1: return a + b;
		case 2: return a - b;
		case 3: return a * b;
		case 4: return b ? a / b : 0;
	}
}