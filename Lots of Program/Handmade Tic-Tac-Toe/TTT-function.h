#define ROW_MAX 3
#define COL_MAX 3
#define INDEX_MAX 255

void cleanBoard(char (*board)[COL_MAX]);
void playerSet();
int placeBoard(char (*board)[COL_MAX]);
int restartOrNot();
void quit();