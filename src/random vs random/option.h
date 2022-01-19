// 1p�� �� �� �ִ��� �Ǵ�
// p, x, y : p �ǿ��� (x,y)�� 1p�� �� �� �ִ��� �Ǻ�
// return true : ��p���� (i,j)�� �δ°� ����
// return false : ��p���� (i,j)�� �δ� �� �Ұ���
bool CHECK_PUT(node1 p, int x, int y)
{
	if(p.board[x][y]!=0) return false;   // ���� ������ �� �� ���ٰ� ��ȯ
	for(int i=-1;i<=1;i++){   // ����
		for(int j=-1;j<=1;j++){   // �¿�
			if(p.board[x+i][y+j]==-1){   // (i,j)���⿡ 2p�� ���� ������
				for(int l=2;true;l++){   // (i,j)������ �� ���� ������
					if(p.board[x+l*i][y+l*j]==0) break;   
				    // ��ĭ�� ���� ��� ���� �� ���� ���̹Ƿ� (i,j)���� Ž�� ����
					if(p.board[x+l*i][y+l*j]==1) return true;  
				    // 1p�� ���� ���� ��� ��� ���� ���� �� �����Ƿ� true ��ȯ
				}
			}
		}
	}
	return false;   // �� �� �ִ� ���� ������ false ��ȯ 
}

// ������ ���� ���� �Ǵ�
// return true : ���� ����
// return false : ���� ���� 
bool THE_END(node1 check)
{
	bool a=false, b=false, x=false, y=false, z=false;
	// a, b : 1p�� 2p�� ���� ���� ���� (false�� �����ϸ� ���� ����)
	// x, y : 1p�� 2p�� �� �� �ִ����� ���� (�� �� false�̸� ���� ����)
	// z : ��ĭ�� ���� ���� (false�̸� ���� ����)
	 
	// ���� ���� �Ǵ�
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(check.board[i][j]==0) z = true;   // ��ĭ�� ������ z=true
			if(check.board[i][j]==1) a = true;   // 1p�� ���� ������ a=true
			if(check.board[i][j]==-1) b = true;   // 2p�� ���� ������ b=true
			// CHECK_PUT�Լ��� 1p�� �� �� �ִ��� �Ǵ��ϹǷ�
			// 2p �Ǻ� �� ���� ������ CHECK_PUT�Լ� ȣ��
			if(CHECK_PUT(check,i,j)) x = true;   // 1p�� �� �� ������ x=true
			if(CHECK_PUT(FLIP(check),i,j)) y = true;   // 2p�� �� �� ������ y=true
		}
	}
	if(!a || !b || (!x &&!y) || !z) return true;   // �� �� ������ �����ٰ�(true) ȣ��
	return false;   // �׷��� ������ ������ �ʾҴٰ�(false) ȣ��
}

// 1p�� �� ���� �ִ��� �Ǵ�
// return true : 1p�� �δ°� ����
// return false : 1p�� �δ°� �Ұ��� 
bool CAN_DO(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(CHECK_PUT(p,i,j)) return true;  // (i,j)�� �� �� ������true ��ȯ 
		}
	}
	return false;   // �� �� ������ false ��ȯ 
}

// ���� �̰���� �Ǵ�
// return 0 : ���º�
// return 1 : 1p ��
// return 2 : 2p �� 
int WHO_WIN(node1 p)
{
	int a=0, b=0;   // 1p�� 2p�� ���� ���� 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==1) a++;   // 1p�� ���� ������ a++ 
			if(p.board[i][j]==-1) b++;   // 2p�� ���� ������ b++ 
		}
	}
	if(a==b) return 0;   // 1p�� 2p�� ���� ������ ������ ���º� 
	else if(a>b) return 1;   // 1p�� 2p�� ���� �������� ������ 1p �� 
	else return 2;   // 1p�� 2p�� ���� �������� ������ 2p �� 
}

// �� ����
// p, x, y : �� p�� (x,y)�� �� ���� 
// ���� ���� �� ��ȯ 
node1 PUT(node1 p, int x, int y)
{
	p.board[x][y] = 1;   // (x,y)�� �� ����
	for(int i=-1;i<=1;i++){   // ���� 
		for(int j=-1;j<=1;j++){   // �¿쿡 
			if(p.board[x+i][y+j]==-1){   // (i,j)���⿡ 2p�� ���� ������ 
				for(int l=2;true;l++){   // (i,j)������ �� ���� ������ 
					if(p.board[x+l*i][y+l*j]==0) break;   
				   // ��ĭ�� ������ ���� �� ���� ���̹Ƿ� (i,j)���� Ž�� ����
					if(p.board[x+l*i][y+l*j]==1){   // 1p�� ���� ������
						// 1p�� ���� ������ ������
						for(int k=1;k<l;k++){
							p.board[x+k*i][y+k*j] = 1;
							// (i,j)������ ���� 1p�� ���� ������
						}
						break;   // (i,j)���� Ž�� ���� 
					}
				}
			}
		}
	}
	return p;   // ���� ���� �� ��ȯ 
}

// �� ������
// ������ �� ��ȯ 
node1 FLIP(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			p.board[i][j] *= -1; 
		}
	}
	return p;
}

void SETUP()   // ���� ���� �� ����
{
	srand(time(NULL));   // �����Լ�(rand())�� ����ϱ� ���� �Լ� 
	 
	// ������ �ʱ�ȭ 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			game.board[i][j] = 0;
			put_.board[i][j] = 0;
			eat_.board[i][j] = 0;
		}
	}
	game.board[4][4] = game.board[5][5] = -1;
	game.board[4][5] = game.board[5][4] = 1;
	 
	// put_board�� eat_board �Է� (random vs random.txt���Ͽ��� �Է�) 
	FILE *in;
	in = fopen("random vs random.txt","r"); 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fscanf(in, "%d", &put.board[i][j]);
		}
	}
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fscanf(in, "%d", &eat.board[i][j]);
		}
	}
	fscanf(in, "%d %d %d", &win, &lose, &draw); 
	fclose(in);
}
