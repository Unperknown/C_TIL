#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "TTT-function.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

char board[ROW_MAX][COL_MAX]; //각 스테이지 당 놓은 수를 저장할 공간
char player1[INDEX_MAX], player2[INDEX_MAX]; //플레이어 닉네임을 설정할 공간
int status = 0; //현재 스테이지의 상태를 나타냄(Player1을 기준으로 승리이면 1, 패배이면 2, 무승부이면 3, 그 외의 경우는 0)
static int x_axis = 5, y_axis = 3; //커서 좌표를 나타내는 변수(초기 값은 게임판의 가운데 좌표 값)
static int cnt = 0; //놓은 횟수 측정
static _Bool turn = 0; //두 플레이어의 구분을 위한 임시 변수

static void showBoard(char (*board)[COL_MAX]); //현재 스테이지 상태 출력 함수
static void detectBoundary(int *x, int *y); //수를 놓을 때 경계 유무 확인
static int stageCheck(); //빙고 유무 확인
static int rowCheck(); //빙고 유무 확인 하위 함수들(가로, 세로, 대각선)
static int colsCheck();
static int diasCheck();
static char buffer(); //입력할 때 개행 문자의 입력으로 인한 오류를 막기 위한 임시 버퍼 함수
static char * get_s(char *str, int max); //플레이어 이름을 공백도 허용하기 위해 만든 임시 문자열 입력 함수
static int getch_(char ch);
static void cersorMoveTo(int x, int y); //커서 이동 함수

void cleanBoard(char (*board)[COL_MAX])
{
	int row, col;
	
	for (row = 0; row < ROW_MAX; row++)
	{	
		for (col = 0; col < COL_MAX; col++)
		{
			board[row][col] = '\0';
		}
	}
	x_axis = 5;
	y_axis = 3;
	cnt = 0;
	status = 0;
	turn = 0;
}
void playerSet()
{
	_Bool sameNickname = 0;
	do
	{
		if (sameNickname) printf("Enter different nickname.\n");
		printf("Enter Player1's name.\n< ");
		get_s(player1, INDEX_MAX);
		printf("Enter Player2's name.\n< ");
		get_s(player2, INDEX_MAX);
	} while (sameNickname = !strcmp(player1, player2));
}	
int placeBoard(char (*board)[COL_MAX])
{
	int check, placedOrNot = 1;
	showBoard(board);
	while (placedOrNot)
	{
		char input;
		cersorMoveTo(x_axis, y_axis);
		switch (getch_(input))
		{
			case LEFT: x_axis -= 4; break;
			case RIGHT: x_axis += 4; break;
			case UP: y_axis -= 2; break;
			case DOWN: y_axis += 2; break;
			case ENTER:
				if (board[y_axis / 2][x_axis / 4] == '\0')
				{
					board[y_axis / 2][x_axis / 4] = turn ? 'X' : 'O';
					turn = turn ? 0 : 1;
					if (check = stageCheck()) showBoard(board);
					return !check;
				}
		}
		detectBoundary(&x_axis, &y_axis);
	}
}
int restartOrNot()
{
	return buffer() == 'Q' ? 0 : 1;
}
void quit()
{
	printf("Had fun enjoying game? Bye!\n");
	buffer();
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
static char buffer()
{
	char ch[100];
	gets(ch);
	return ch[0];
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
static int getch_(char ch)
{
	if ((ch = getch()) == -32 || ch == 0)
		ch = getch();
	
	return ch;
}
static void showBoard(char (* board)[COL_MAX])
{
	system("cls");
	printf("Player1: %s VS Player2: %s\n", player1, player2);
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
static void detectBoundary(int *x, int *y)
{
	if (*x < 1) *x = 9;
	else if (*x > 9) *x = 1;
	else if (*y < 1) *y = 5;
	else if (*y > 5) *y = 1;
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