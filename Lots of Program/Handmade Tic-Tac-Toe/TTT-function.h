#define ROW_MAX 3
#define COL_MAX 3
#define INDEX_MAX 255

extern int status;
extern char board[ROW_MAX][COL_MAX];
extern char player1[INDEX_MAX], player2[INDEX_MAX];

void cleanBoard(char (*board)[COL_MAX]);
void playerSet();
int placeBoard(char (*board)[COL_MAX]);
int restartOrNot();
void quit();