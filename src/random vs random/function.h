#define size 8

struct node1{
	int board[size+2][size+2];
};

int win, lose, draw;
node1 game, put, eat, put_, eat_;

void SETUP();   // ���� ���� �� ����
void PLAY_GAME();   // ������ �����Ű�� �Լ� 
void PRINT_BOARD(node1 p);   // ���� ��Ȳ(���� ��) ���
bool THE_END(node1 check);   // ������ ���� ���� �Ǻ�
bool CHECK_PUT(node1 p, int x, int y);   // 1p�� �� �� �ִ��� �Ǻ�
node1 FLIP(node1 p);   // �� ������
node1 PUT(node1 p, int x, int y);   // �� ����
bool CAN_DO(node1 p);   // 1p�� �� ���� �ִ��� �Ǻ�
int WHO_WIN(node1 p);   // ���� �̰���� �Ǻ� 
void REMEMBER(node1 p, int k, int z);   // ������ ����
void ANALYSIS(int z);   // z�� �̰��� �� ������ �м�

int RANDOM_TURN(node1 ai);   // �������� �α�

#include "print.h"
#include "game.h"
#include "option.h"
#include "analysis.h"
#include "random_ai.h"
