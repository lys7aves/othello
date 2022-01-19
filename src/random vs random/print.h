// 현재 상황(보드 판) 출력 
void PRINT_BOARD(node1 p)
{
	int a=0, b=0;   // 1p와 2p의 돌의 개수 
	
	system("cls");   // 화면 지우기 
	printf("#%d\n", win+lose+draw+1);   // 진행되고있는 게임 횟수 출력
	// 보드판 출력 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==0){   // (i,j)가 0이면(돌이 없으면) 
				printf("■");   // 공백 출력  
			}
			else{   // 돌이 있으면
				if(p.board[i][j]==1){   // (i,j)에 1p의 돌이 있으면 
					a++;   // a++ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);   
					// 색을 빨강색으로 바꿈
				}
				else{   // (i,j)에 2p의 돌이 있으면 
					b++;   // b++ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);   
					// 색을 노란색으로 바꿈
				}
				printf("●");   // 돌 출력 
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // 색을 흰색으로 바꿈
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);   // 빨강색
	printf("%2d", a);   // 1p의 돌의 개수 출력 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // 흰색 
	printf(" vs ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);   // 노란색 
	printf("%2d", b);   // 2p의 돌의 개수 출력 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // 흰색 
	printf("\n");
}
