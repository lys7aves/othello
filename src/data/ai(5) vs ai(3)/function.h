#define size 8
#define delay_time 000

struct node1{
	int board[size+2][size+2];
};
struct node2{
	double point;
	int xy;
};

int asdf;
int px, py, win, lose, draw;
int remember[100];
double put_gap, eat_gap;
node1 game, put, eat, put_, eat_;

void MAIN();
void PRINT_MAIN_SCREEN(int p);
void PRINT_FRONT(int p, int q);
void HOW_TO_PLAY();
void ORDER();
void PRINT_GAME_SCREEN(int p);
void SETUP();
int UP(int p, int q);
int DOWN(int p, int q);
void PLAY_GAME(int k);
void PRINT_BOARD(node1 p);
bool THE_END(node1 check);
bool CHECK_PUT(node1 p, int x, int y);
node1 FLIP(node1 p);
node1 PUT(node1 p, int x, int y);
bool CAN_DO(node1 p);
int WHOW_WIN(node1 p);
double POINT(node1 p, int x, int y);
node2 LOOK(node1 p, int q);
void REMEMBER(node1 p, int k, int z);
void ANALYSIS(int z);

int USER_TURN(node1 user, bool z);
int AI_TURN(node1 ai);
int RANDOM_TURN(node1 p);
