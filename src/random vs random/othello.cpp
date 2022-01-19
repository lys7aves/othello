#include <stdio.h>
#include <conio.h>
#define POINT trash
#include <windows.h>
#undef POINT
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "function.h"

int main()
{
	int n;
	scanf("%d", &n);   // 돌리고자 하는 횟수 입력
	SETUP();   // 이제까지 한 횟수(win + lose + draw) 입력을 위해 호출 
	while(win+lose+draw < n){   // 이제까지 한 횟수가 n번 이하이면
		PLAY_GAME();   // 게임 진행
	}
	return 0;
}
