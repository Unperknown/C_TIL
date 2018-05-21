char board[3][3];
extern int status;

void show_board(char (* board)[3]);
void place_p1(char (* board)[3]);
void place_p2(char (* board)[3]);
int check(char (* board)[3]);
void clean(char (* board)[3]);
void end();