#include <stdio.h>
#include <conio.h>
#define POINT trash
#include <windows.h>
#undef POINT
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "function.h"
#include "print.h"
#include "move.h"
#include "game.h"
#include "option.h"
#include "analysis.h"
#include "random_ai.h"

int main()
{
	int n;
	scanf("%d", &n);   // �������� �ϴ� Ƚ�� �Է�
	SETUP();   // �������� �� Ƚ��(win + lose + draw) �Է��� ���� ȣ
	while(win+lose+draw < n){   // �������� �� Ƚ���� n�� �����̸�
		PLAY_GAME();   // ���� ����
	}
	return 0;
}