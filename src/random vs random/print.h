// ���� ��Ȳ(���� ��) ��� 
void PRINT_BOARD(node1 p)
{
	int a=0, b=0;   // 1p�� 2p�� ���� ���� 
	
	system("cls");   // ȭ�� ����� 
	printf("#%d\n", win+lose+draw+1);   // ����ǰ��ִ� ���� Ƚ�� ���
	// ������ ��� 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==0){   // (i,j)�� 0�̸�(���� ������) 
				printf("��");   // ���� ���  
			}
			else{   // ���� ������
				if(p.board[i][j]==1){   // (i,j)�� 1p�� ���� ������ 
					a++;   // a++ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);   
					// ���� ���������� �ٲ�
				}
				else{   // (i,j)�� 2p�� ���� ������ 
					b++;   // b++ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);   
					// ���� ��������� �ٲ�
				}
				printf("��");   // �� ��� 
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // ���� ������� �ٲ�
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);   // ������
	printf("%2d", a);   // 1p�� ���� ���� ��� 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // ��� 
	printf(" vs ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);   // ����� 
	printf("%2d", b);   // 2p�� ���� ���� ��� 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   // ��� 
	printf("\n");
}
