#include <stdio.h>
#include "TTT-function.h"

extern char player1[INDEX_MAX], player2[INDEX_MAX];
extern char board[ROW_MAX][COL_MAX];
extern int status;

void gameStart();
void gameResult();

int main()
{
	do
	{
		gameStart(); //게임 시작
		gameResult(); //한 스테이지의 결과 알림(승리, 패배, 무승부)
	} while (restartOrNot());
	
	quit(); //프로그램 종료
	return 0;
}

void gameStart()
{
	playerSet(); //플레이어 이름 설정
	cleanBoard(board); //스테이지 시작 시 게임판 초기화(스테이지가 한 개 이상 있으므로)
	while (placeBoard(board));
}
void gameResult()
{
	printf("Game over!\n");
	switch (status) //스테이지 상태를 저장하는 status 변수에 따라 결과 출력
	{
		case 1: printf("Winner is %s!\n", player1); break;
		case 2: printf("Winner is %s!\n", player2); break;
		case 3: printf("Draw.\n"); break;
	}
	printf("Want to play again? Press any sentence to continue.(Press Q if you want to quit)\n");
}