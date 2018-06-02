#define ROW_MAX 3
#define COL_MAX 3
#define INDEX_MAX 255

extern int status;
extern char board[ROW_MAX][COL_MAX];
extern char player1[INDEX_MAX], player2[INDEX_MAX];

void quit();
int restartOrNot();
void playerSet();
int cleanBoard();
int placeBoard();