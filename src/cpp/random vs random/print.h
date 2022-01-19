void PRINT_BOARD(node1 p)
{
	int a=0, b=0;
	
	system("cls");
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==0){
				printf("бс");
			}
			else{
				if(p.board[i][j]==1){
					a++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				}
				else{
					b++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				}
				printf("б▄");
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
