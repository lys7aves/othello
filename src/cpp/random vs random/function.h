#define size 8

struct node1{
	int board[size+2][size+2];
};

int win, lose, draw;
node1 game, put, eat, put_, eat_;

void PRINT_GAME_SCREEN(int p);
void SETUP();
int UP(int p, int q);
int DOWN(int p, int q);
void PLAY_GAME();
void PRINT_BOARD(node1 p);
bool THE_END(node1 check);
bool CHECK_PUT(node1 p, int x, int y);
node1 FLIP(node1 p);
node1 PUT(node1 p, int x, int y);
bool CAN_DO(node1 p);
int WHOW_WIN(node1 p);
void REMEMBER(node1 p, int k, int z);
void ANALYSIS(int z);

int RANDOM_TURN(node1 ai);
