

void PRINT_MAIN_SCREEN(int p)
{
	system("cls");
	printf("------------------------------------------\n");
	printf("|                 OTHELLO                |\n");
	printf("------------------------------------------\n");
	printf("\n");
	PRINT_FRONT(1,p);
	printf("GAME START\n");
	PRINT_FRONT(2,p);
	printf("HOW TO PLAY\n");
	PRINT_FRONT(3,p);
	printf("THE END\n"); 
}

void PRINT_GAME_SCREEN(int p)
{
	system("cls");
	printf("------------------------------------------\n");
	printf("|                  ORDER                 |\n");
	printf("------------------------------------------\n");
	printf("\n");
	PRINT_FRONT(1,p);
	printf("선공\n");
	PRINT_FRONT(2,p);
	printf("후공\n");
	PRINT_FRONT(3,p);
	printf("RANDOM\n"); 
}


void PRINT_BOARD(node1 p)
{
	int a=0, b=0;
	
	system("cls");
//	printf("#%d\n", win+lose+draw);
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==0){
				if(i==px && j==py) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				printf("■");
			}
			else{
				if(p.board[i][j]==1){
					a++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					if(i==px && j==py) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				}
				else{
					b++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					if(i==px && j==py) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
				}
				printf("●");
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		}
		printf("\n"); 
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("%2d", a);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf(" vs ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("%2d", b);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("\n");
}
