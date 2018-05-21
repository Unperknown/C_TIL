#include <stdio.h>
#include <stdlib.h>

int status = 0;
static int cnt = 0;
static int rowCheck(char (* board)[3]);
static int colsCheck(char (* board)[3]);
static int diasCheck(char (* board)[3]);
static int drawCheck(char (* board)[3]);

void end()
{
	char ch[100];
	printf("Had fun enjoying game? Bye!\n");
	gets(ch);
	gets(ch);
	exit(EXIT_FAILURE);
}
void show_board(char (* board)[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != 2) printf("|");
		}
		if (i != 2) printf("\n------------\n");
	}
	printf("\n");
}
void place_p1(char (* board)[3])
{
	int i, j;
	if (scanf("%d %d", &i, &j) != 2 || (i < 0 && i > 2) || (j < 0 && j > 2))
	{
		printf("Invaild value.\n");
		end();
	}
	if (board[i][j] != '\0')
	{
		printf("Other team's already placed on there!\n");
		if (scanf("%d %d", &i, &j) != 2 || (i < 0 && i > 2) || (j < 0 && j > 2))
		{
		printf("Invaild value.\n");
		end();
		}
		
		board[i][j] = 'O';
	}
	else board[i][j] = 'O';
}
void place_p2(char (* board)[3])
{
	int i, j;
	if (scanf("%d %d", &i, &j) != 2 || (i < 0 && i > 2) || (j < 0 && j > 2))
	{
		printf("Invaild value.\n");
		end();
	}
	if (board[i][j] != '\0')
	{
		printf("Other team's already placed on there!\n");
		if (scanf("%d %d", &i, &j) != 2 || (i < 0 && i > 2) || (j < 0 && j > 2))
		{
		printf("Invaild value.\n");
		end();
		}
		board[i][j] = 'X';
	}
	else board[i][j] = 'X';
}
int check(char (* board)[3])
{
	cnt++;
	if (rowCheck(board)) status = rowCheck(board);
	if (colsCheck(board)) status = colsCheck(board);
	if (diasCheck(board)) status = diasCheck(board);
	if (cnt >= 8) status = drawCheck(board);
	return status;
}
void clean(char (* board)[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '\0';
		}
	}
	status = 0;
	cnt = 0;
}

static int drawCheck(char (* board)[3])
{
	int result = 0, flag = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != '\0') result = 3;
			else 
			{
				result = 0;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	return result;
}
static int rowCheck(char (* board)[3])
{
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == '\0') ;
			else if (board[i][0] == 'O') result = 1;
			else if (board[i][0] == 'X') result = 2;
		}
	}
	return result;
}
static int colsCheck(char (* board)[3])
{
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == '\0') ;
			else if (board[0][i] == 'O') result = 1;
			else if (board[0][i] == 'X') result = 2;
		}
	}
	return result;
}
static int diasCheck(char (* board)[3])
{
	int result = 0;
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == '\0') ;
		else if (board[0][0] == 'O') result = 1;
		else if (board[0][0] == 'X') result = 2;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][0] == '\0') ;
		else if (board[0][2] == 'O') result = 1;
		else if (board[0][2] == 'X') result = 2;
	}
	return result;
}