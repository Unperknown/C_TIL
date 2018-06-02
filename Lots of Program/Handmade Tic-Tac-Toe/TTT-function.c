#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "function.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

char board[ROW_MAX][COL_MAX];
char player1[INDEX_MAX], player2[INDEX_MAX];
static int cnt = 0;
static int turn = 0;
int status = 0; //현재 스테이지의 상태를 나타냄(Player1을 기준으로 승리이면 1, 패배이면 2, 무승부이면 3, 그 외의 경우는 0)

static int stageCheck();
static char * get_s(char *str, int max);
static void showBoard();
static void cersorMoveTo(int x, int y);
static int rowCheck();
static int colsCheck();
static int diasCheck();
static int drawCheck(); 

int cleanBoard()
{
	int row, col;
	
	for (row = 0; row < ROW_MAX; row++)
	{	
		for (col = 0; col < COL_MAX; col++)
		{
			board[row][col] = '\0';
		}
	}	
	cnt = 0;
	status = 0;
	turn  = 0;
	return 1;
}
void playerSet()
{
	int temp = 0;
	do
	{
		if (temp) printf("Enter different nickname.\n");
		printf("Enter Player1's name.\n< ");
		get_s(player1, INDEX_MAX);
		printf("Enter Player2's name.\n< ");
		get_s(player2, INDEX_MAX);
	} while (temp = !strcmp(player1, player2));
}	
int placeBoard()
{
	system("cls");
	int x_axis = 5, y_axis = 3;
	int placedOrNot = 1, check;
	printf("%s: %s VS %s: %s\n", turn ? "Player1" : "PLAYER1", player1, turn ? "PLAYER2" : "Player2", player2);
	showBoard();
	while (placedOrNot)
	{
		cersorMoveTo(x_axis, y_axis);
		char input;
		if ((input = getch()) == -32 || input == 0)
			input = getch();
		switch (input)
		{
			case LEFT: x_axis -= 4; break;
			case RIGHT: x_axis += 4; break;
			case UP: y_axis -= 2; break;
			case DOWN: y_axis += 2; break;
			case ENTER:
				if (board[y_axis / 2][x_axis / 4] == '\0')
				{
					board[y_axis / 2][x_axis / 4] = turn ? 'X' : 'O';
					placedOrNot = 0;
					turn = turn ? 0 : 1;
					if (check = stageCheck())
					{
						system("cls");
						printf("Player1: %s VS Player2: %s\n", player1, player2);
						showBoard();
					}
					return !check;
				}
		}
		if (x_axis < 1)
		{
			x_axis = 9;
		}
		else if (x_axis > 9)
		{
			x_axis = 1;
		}
		else if (y_axis < 1)
		{
			y_axis = 5;
		}
		else if (y_axis > 5)
		{
			y_axis = 1;
		}
	}
}
int restartOrNot()
{
	char ch[100];
	gets(ch);
	return ch[0] == 'Q' ? 0 : 1;
}
void quit()
{
	printf("Had fun enjoying game? Bye!\n");
	char ch[100];
	gets(ch);
	exit(EXIT_FAILURE);
}

static int stageCheck()
{
	cnt++;
	
	int result;
	if (result = rowCheck()) status = result;
	else if (result = colsCheck()) status = result;
	else if (result = diasCheck()) status = result;
	else if (cnt == 9) status = 3;

	if (status) cersorMoveTo(0, 6);
	return status;
}
static char * get_s(char *str, int max)
{
	char * ret_str;
	
	ret_str = fgets(str, max, stdin);
	
	int temp_index = 0;
	if (ret_str)
	{
		if (ret_str[0] == '\n') ret_str = fgets(str, max, stdin);
		while (ret_str[temp_index] != '\0' && ret_str[temp_index] != '\n') temp_index++;
		if (ret_str[temp_index] == '\n') ret_str[temp_index] = '\0';
	}
	
	return ret_str;
}
static void showBoard()
{
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
static void cersorMoveTo(int x, int y)
{
	COORD position = { x, y };
	static HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);	
}
static int rowCheck()
{
	int result = 0;
	for (int i = 0; i < ROW_MAX; i++)
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
static int colsCheck()
{
	int result = 0;
	for (int i = 0; i < COL_MAX; i++)
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
static int diasCheck()
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