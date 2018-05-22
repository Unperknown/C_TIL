#include "board.h"

int status = 0;
static int cnt = 0, turn = 0;
static int rowCheck(char (* board)[COLS]);
static int colsCheck(char (* board)[COLS]);
static int diasCheck(char (* board)[COLS]);
static int drawCheck(char (* board)[COLS]);

void end()
{
	char ch[100];
	gets(ch);
	exit(EXIT_FAILURE);
}
int quit()
{
	char ch[100];
	gets(ch);
	return ch[0] == 'Q' ? 0 : 1;
}
void show_board(char (* board)[COLS])
{
	printf("    1   2   3\n");
	for (int i = 0; i < ROWS; i++)
	{
		printf("%d  ", i + 1);
		for (int j = 0; j < COLS; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != 2) printf("|");
		}
		if (i != 2) printf("\n  -------------\n");
	}
	printf("\n");
}
void place_p(char (* board)[COLS])
{
	int i, j, temp, done = 1;
	do
	{
		if ((temp = scanf("%d %d", &i, &j)) != 2 || (i < 1 || i > 3) || (j < 1 || j > 3))
		{
			printf("Invaild axis(x, y)!\n");
			printf("Input vaild axis(x, y).\n< "); continue;
		}
		else if (temp == 2 && board[i - 1][j - 1] != '\0')
		{
			printf("Someone already placed on there!\n");
			printf("Place on another axis(x, y).\n< "); continue;
		}
		else if (temp == 2) done = 0;
	} while (done);
	board[i - 1][j - 1] = turn ? 'X': 'O';
	if (turn) turn = 0;
	else turn = 1;
}
int check(char (* board)[COLS])
{
	cnt++;
	if (rowCheck(board)) status = rowCheck(board);
	else if (colsCheck(board)) status = colsCheck(board);
	else if (diasCheck(board)) status = diasCheck(board);
	else if (cnt == 9) status = drawCheck(board);

	return status;
}
void clean(char (* board)[COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = '\0';
		}
	}
	status = 0;
	cnt = 0;
	turn = 0;
}

static int drawCheck(char (* board)[COLS])
{
	int result = 0, flag = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
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
static int rowCheck(char (* board)[COLS])
{
	int result = 0;
	for (int i = 0; i < ROWS; i++)
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
static int colsCheck(char (* board)[COLS])
{
	int result = 0;
	for (int i = 0; i < COLS; i++)
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
static int diasCheck(char (* board)[COLS])
{
	int result = 0;
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == '\0') ;
		else if (board[0][0] == 'O') result = 1;
		else if (board[0][0] == 'X') result = 2;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == '\0') ;
		else if (board[0][2] == 'O') result = 1;
		else if (board[0][2] == 'X') result = 2;
	}
	return result;
}
