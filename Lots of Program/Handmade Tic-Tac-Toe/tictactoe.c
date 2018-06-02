#include <stdio.h>
#include "function.h"

extern char player1[INDEX_MAX], player2[INDEX_MAX];
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
	cleanBoard(); //스테이지 시작 시 게임판 초기화(스테이지가 여러 개 있으므로)
	while (placeBoard());
}
void gameResult()
{
	printf("Game over!\n");
	switch (status) //스테이지 상태를 저장하는 status 변수에 따라 결과 출력
	{
		case 1: printf("Winner is %s!\n", player1); break;
		case 2: printf("Winner is %s!\n", player2); break;
		case 3: printf("Both didn't win, it's draw.\n"); break;
	}
	printf("Want to play again? Press any key to continue.(Press Q if you want to quit.)\n");
}