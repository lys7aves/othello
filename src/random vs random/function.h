#define size 8

struct node1{
	int board[size+2][size+2];
};

int win, lose, draw;
node1 game, put, eat, put_, eat_;

void SETUP();   // 게임 시작 전 셋팅
void PLAY_GAME();   // 게임을 진행시키는 함수 
void PRINT_BOARD(node1 p);   // 현재 상황(보드 판) 출력
bool THE_END(node1 check);   // 게임의 종료 여부 판별
bool CHECK_PUT(node1 p, int x, int y);   // 1p가 둘 수 있는지 판별
node1 FLIP(node1 p);   // 판 뒤집기
node1 PUT(node1 p, int x, int y);   // 돌 놓기
bool CAN_DO(node1 p);   // 1p가 둘 곳이 있는지 판별
int WHO_WIN(node1 p);   // 누가 이겼는지 판별 
void REMEMBER(node1 p, int k, int z);   // 데이터 저장
void ANALYSIS(int z);   // z가 이겼을 때 데이터 분석

int RANDOM_TURN(node1 ai);   // 랜담으로 두기

#include "print.h"
#include "game.h"
#include "option.h"
#include "analysis.h"
#include "random_ai.h"
