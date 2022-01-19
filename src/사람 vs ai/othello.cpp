#include <stdio.h>
#include <conio.h>
#define POINT trash
#include <windows.h>
#undef POINT
#include <stdlib.h>
#include <time.h>
#include <direct.h>

using namespace std;

#include "function.h"
#include "print.h"
#include "menu.h"
#include "move.h"
#include "user.h"
#include "ai.h"
#include "game.h"
#include "option.h"
#include "analysis.h"
#include "random_ai.h"

int main()
{
	SETUP();
	while(1) MAIN();
	return 0;
}
