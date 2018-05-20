#include <stdio.h>
#include "move.h"

int n, m, i, j, choose;

int main()
{
    extern int n;
	extern int m;
	char ch;
	int cnt = 0;
	int temp;
	
	do 
	{
		cnt = 0;
		printf("Set size of board.\n< ");
		if (scanf("%d %d", &n, &m) != 2 || n <= 1 || m <= 1)
		{
			puts("Incorrect value.");
			end();
		}
		printf("Where is the start?\n");
		bar();
		printf("1\t2\n\n\n");
		printf("3\t4\n");
		bar();
		if (scanf("%d", &choose) != 1 || choose < 1 || choose > 4)
		{
			puts("Incorrect value.");
			end();
		}
		start_point(&i, &j);
		printf("Set way to move.\n");
		bar();
		printf("1. UP\n");
		printf("2. DOWN\n");
		printf("3. LEFT\n");
		printf("4. RIGHT\n");
		bar();
		while (++cnt <= 4)
		{
			if (scanf("%d", &temp) != 1)
			{
				puts("Incorrect value.");
				end();
			}
			set_way(temp);
		}
		follow_snail(n, m);
		arr_print(n, m);
		getchar();
		clear();
		printf("Press any key to continue.(Press Q if you want to quit.)\n");
	} while ((ch = getchar()) != 'Q');
     
	end();
    return 0;
}