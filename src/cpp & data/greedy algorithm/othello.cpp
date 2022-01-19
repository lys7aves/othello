#include <stdio.h>
#include <conio.h>
#define POINT trash
#include <windows.h>
#undef POINT
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

#include "function.h"
#include "print.h"
#include "menu.h"
#include "move.h"
#include "user.h"
#include "greedy ai.h"
#include "game.h"
#include "option.h"
#include "analysis.h"
#include "random_ai.h"

int main()
{
	srand(time(NULL));
//	MAIN();
	int n;
	scanf("%d", &n);
	if(win+lose+draw>=n) return 0;
	while(1){
		PLAY_GAME(rand()%2+1);
		printf("%d\n", win+lose+draw);
		if(win+lose+draw>=n) break;
	}
	return 0;
}
