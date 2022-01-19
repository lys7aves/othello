
void MAIN()
{
	int p, k=1;
	PRINT_MAIN_SCREEN(k);
	while(1){
		p = getch();
		if(p==72){
			k = DOWN(k,3);
		}
		else if(p==80){
			k = UP(k,3);
		}
		else if(p==13){
			break;
		}
		else continue;
		PRINT_MAIN_SCREEN(k);
	}
	if(k==1){
		ORDER();
	}
	else if(k==2){
		HOW_TO_PLAY(); 
	}
	else{
		system("cls");
		printf("감사합니다.");
		for(int i=1;i<=200000000;i++);
		exit(1);
	}
}

void PRINT_FRONT(int p, int q)
{
	if(p==q) printf("☞");
	else printf("  ");
}

void HOW_TO_PLAY()
{
	system("cls");
	printf("------------------------------------------------------------------------------\n");
	printf("|                                  THE RULE                                  |\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("⊙ 처음에 판 가운데에 사각형으로 엇갈리게 배치된 돌 4개를 놓고 시작한다.\n\n");
	printf("⊙ 돌은 반드시 상대방 돌을 양쪽에서 포위하여 뒤집을 수 있는 곳에 놓아야 한다.\n\n");
	printf("⊙ 돌을 뒤집을 곳이 없는 경우에는 차례가 자동적으로 상대방에게 넘어가게 된다.\n\n");
	printf("⊙ 아래와 같은 조건에 의해 양쪽 모두 더 이상 돌을 놓을 수 없게 되면 게임이 끝나게 된다.\n\n");
	printf("  ▷ 64개의 돌 모두가 판에 가득 찬 경우 (가장 일반적)\n\n");
	printf("  ▷ 어느 한 쪽이 돌을 모두 뒤집은 경우\n\n");
	printf("  ▷ 한 차례에 양 쪽 모두 서로 차례를 넘겨야 하는 경우\n\n");
	printf("⊙ 게임이 끝났을 때 돌이 많이 있는 플레이어가 승자가 된다.\n\n");
	printf("   만일 돌의 개수가 같을 경우는 무승부가 된다.\n\n");
	printf("\n");
	printf("조작키는 방향키와 엔터키입니다.");
	getch();
	MAIN();
}

void ORDER()
{
	int p, k=1;
	PRINT_GAME_SCREEN(k);
	while(1){
		p = getch();
		if(p==72){
			k = DOWN(k,3);
		}
		else if(p==80){
			k = UP(k,3);
		}
		else if(p==13){
			break;
		}
		else continue;
		PRINT_GAME_SCREEN(k);
	}
	if(k==3){
		k = rand()%2+1;
	}
	if(k==1){
		system("cls");
		printf("YOU FIRST\n");
	}
	else if(k==2){
		system("cls");
		printf("COM FIRST\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("FIRST\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("SECOND\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("pause");
	PLAY_GAME(k);
}
