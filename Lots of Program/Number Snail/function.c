#include <stdio.h>
#include <stdlib.h>
#include "move.h"

static int up_v = 0, down_v = 0, left_v = 0, right_v = 0;
static int flag = 0;
static int down(int * i, int * j);
static int up(int * i, int * j);
static int left(int * i, int * j);
static int right(int * i, int * j);

void start_point(int * i, int * j)
{
	switch (choose)
	{
		case 1: *i = 0; *j = 0; break;
		case 2: *i = 0; *j = m - 1; break;
		case 3: *i = n - 1; *j = 0; break;
		case 4: *i = n - 1; *j = m - 1; break;
	}
}
void set_way(int a)
{
	switch (a)
	{
		case 1: up_v = flag++; break;
		case 2: down_v = flag++; break;
		case 3: left_v = flag++; break;
		case 4: right_v = flag++; break;
	}
}
void follow_snail(int n, int m)
{
	int way = 0;
	int num = 1;
	while (num <= (n * m))
    {
        a[i][j] = num++;
        if ((way % 4) == up_v) way += up(&i, &j);
        else if ((way % 4) == down_v) way += down(&i, &j);
        else if ((way % 4) == left_v) way += left(&i, &j);
        else if ((way % 4) == right_v) way += right(&i, &j);
    }
}
void arr_print(int n, int m)
{
	printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void clear()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            a[i][j] = 0;
        }
    }
	up_v = 0; down_v = 0; left_v = 0; right_v = 0; flag = 0;
}
void end()
{
	char ch[100];
	printf("End.\n");
	gets(ch);
	gets(ch);
	exit(EXIT_FAILURE);
}

void bar()
{
	for (int i = 0; i < 10; i++) printf("-");
	puts("");
}
int down(int * i, int * j)
{
    (*i)++;
    if (*i == (n - 1) || a[*i + 1][*j] != 0) return 1;
    else return 0;
}
int up(int * i, int * j)
{
    (*i)--;
    if (*i == 0 || a[*i - 1][*j] != 0) return 1;
    else return 0;
}
int left(int * i, int * j)
{
    (*j)--;
    if (*j == 0 || a[*i][*j - 1] != 0) return 1;
    else return 0;
}
int right(int * i, int * j)
{
    (*j)++;
    if (*j == (m - 1) || a[*i][*j + 1] != 0) return 1;
    else return 0;
}