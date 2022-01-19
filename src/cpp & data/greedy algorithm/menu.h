
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
		printf("�����մϴ�.");
		for(int i=1;i<=200000000;i++);
		exit(1);
	}
}

void PRINT_FRONT(int p, int q)
{
	if(p==q) printf("��");
	else printf("  ");
}

void HOW_TO_PLAY()
{
	system("cls");
	printf("------------------------------------------------------------------------------\n");
	printf("|                                  THE RULE                                  |\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("�� ó���� �� ����� �簢������ �������� ��ġ�� �� 4���� ���� �����Ѵ�.\n\n");
	printf("�� ���� �ݵ�� ���� ���� ���ʿ��� �����Ͽ� ������ �� �ִ� ���� ���ƾ� �Ѵ�.\n\n");
	printf("�� ���� ������ ���� ���� ��쿡�� ���ʰ� �ڵ������� ���濡�� �Ѿ�� �ȴ�.\n\n");
	printf("�� �Ʒ��� ���� ���ǿ� ���� ���� ��� �� �̻� ���� ���� �� ���� �Ǹ� ������ ������ �ȴ�.\n\n");
	printf("  �� 64���� �� ��ΰ� �ǿ� ���� �� ��� (���� �Ϲ���)\n\n");
	printf("  �� ��� �� ���� ���� ��� ������ ���\n\n");
	printf("  �� �� ���ʿ� �� �� ��� ���� ���ʸ� �Ѱܾ� �ϴ� ���\n\n");
	printf("�� ������ ������ �� ���� ���� �ִ� �÷��̾ ���ڰ� �ȴ�.\n\n");
	printf("   ���� ���� ������ ���� ���� ���ºΰ� �ȴ�.\n\n");
	printf("\n");
	printf("����Ű�� ����Ű�� ����Ű�Դϴ�.");
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
