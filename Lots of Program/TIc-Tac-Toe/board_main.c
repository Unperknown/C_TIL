#include <stdio.h>
#include "board.h"

extern int status;

static char * s_get(char * name, int max);
int main()
{
	char player1[50], player2[50], quit;
	do
	{
		if (quit != '\0' || quit == '\n')
		{
			getchar();
			clean(board);
		}
		printf("Enter Player1's name.\n< ");
		s_get(player1, 50);
		printf("Enter Player2's name.\n< ");
		s_get(player2, 50);
	
		printf("Player1(O): %s VS Player2(X): %s\n", player1, player2);
		show_board(board);
		do 
		{
			printf("%s's turn(O): ", player1);
			place_p1(board);
			if (check(board) > 0) break;
			show_board(board);
			printf("%s's turn(X): ", player2);
			place_p2(board);
			show_board(board);
		} while (check(board) == 0);
		
		getchar();
		printf("Game over!\n");
		show_board(board);
		if (status == 3) printf("Drawn.\n");
		else if (status == -1) printf("Error.\n");
		else printf("Winner is %s!\n", (status == 1 ? player1 : player2));
		printf("Want to play again? Press any key to continue.(Press Q if you want to stop.)\n");
	} while (quit = getchar() != 'Q');
	
	end();
	
	return 0;
}

static char * s_get(char * name, int max)
{
	int i = 0;
	char * temp;
	
	temp = fgets(name, max, stdin);
	if (temp)
	{
		while (name[i] != '\n' && name[i] != '\0')
			i++;
		if (name[i] == '\n') name[i] = '\0';
	}
	
	return temp;
}