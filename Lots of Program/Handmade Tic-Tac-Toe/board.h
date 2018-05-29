#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 3
#define COLS 3

char board[ROWS][COLS];
extern int status;

void playerSet();
void show_board(char (* board)[COLS]);
void place_p(char (* board)[COLS]);
int check(char (* board)[COLS]);
void clean(char (* board)[COLS]);
void end();
int quit();
