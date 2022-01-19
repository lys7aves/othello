// 1p가 둘 수 있는지 판단
// p, x, y : p 판에서 (x,y)에 1p가 둘 수 있는지 판별
// return true : 판p에서 (i,j)에 두는게 가능
// return false : 판p에서 (i,j)에 두는 게 불가능
bool CHECK_PUT(node1 p, int x, int y)
{
	if(p.board[x][y]!=0) return false;   // 돌이 있으면 둘 수 없다고 반환
	for(int i=-1;i<=1;i++){   // 상하
		for(int j=-1;j<=1;j++){   // 좌우
			if(p.board[x+i][y+j]==-1){   // (i,j)방향에 2p의 돌이 있으면
				for(int l=2;true;l++){   // (i,j)방향의 그 다음 돌부터
					if(p.board[x+l*i][y+l*j]==0) break;   
				    // 빈칸이 나올 경우 먹을 수 없는 돌이므로 (i,j)방향 탐색 종료
					if(p.board[x+l*i][y+l*j]==1) return true;  
				    // 1p의 돌이 나올 경우 상대 돌을 먹을 수 있으므로 true 반환
				}
			}
		}
	}
	return false;   // 둘 수 있는 곳이 없으면 false 반환 
}

// 게임의 종료 여부 판단
// return true : 게임 종료
// return false : 게임 진행 
bool THE_END(node1 check)
{
	bool a=false, b=false, x=false, y=false, z=false;
	// a, b : 1p와 2p의 돌의 존재 유무 (false가 존재하면 게임 종료)
	// x, y : 1p와 2p가 둘 수 있는지의 여부 (둘 다 false이면 게임 종료)
	// z : 빈칸의 존재 유무 (false이면 게임 종료)
	 
	// 게임 종료 판단
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(check.board[i][j]==0) z = true;   // 빈칸이 있으면 z=true
			if(check.board[i][j]==1) a = true;   // 1p의 돌이 있으면 a=true
			if(check.board[i][j]==-1) b = true;   // 2p의 돌이 있으면 b=true
			// CHECK_PUT함수는 1p가 둘 수 있는지 판단하므로
			// 2p 판별 시 판을 뒤집고 CHECK_PUT함수 호출
			if(CHECK_PUT(check,i,j)) x = true;   // 1p가 둘 수 있으면 x=true
			if(CHECK_PUT(FLIP(check),i,j)) y = true;   // 2p가 둘 수 있으면 y=true
		}
	}
	if(!a || !b || (!x &&!y) || !z) return true;   // 둘 수 없으면 끝났다고(true) 호출
	return false;   // 그렇지 않으면 끝나지 않았다고(false) 호출
}

// 1p가 둘 곳이 있는지 판단
// return true : 1p가 두는게 가능
// return false : 1p가 두는게 불가능 
bool CAN_DO(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(CHECK_PUT(p,i,j)) return true;  // (i,j)에 둘 수 있으면true 반환 
		}
	}
	return false;   // 둘 수 있으면 false 반환 
}

// 누가 이겼는지 판단
// return 0 : 무승부
// return 1 : 1p 승
// return 2 : 2p 승 
int WHO_WIN(node1 p)
{
	int a=0, b=0;   // 1p와 2p의 돌의 개수 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==1) a++;   // 1p의 돌이 있으면 a++ 
			if(p.board[i][j]==-1) b++;   // 2p의 돌이 있으면 b++ 
		}
	}
	if(a==b) return 0;   // 1p와 2p의 돌의 개수가 같으면 무승부 
	else if(a>b) return 1;   // 1p가 2p의 돌의 개수보다 많으면 1p 승 
	else return 2;   // 1p가 2p의 돌의 개수보다 적으면 2p 승 
}

// 돌 놓기
// p, x, y : 판 p의 (x,y)에 돌 놓기 
// 돌을 놓은 판 반환 
node1 PUT(node1 p, int x, int y)
{
	p.board[x][y] = 1;   // (x,y)에 돌 놓음
	for(int i=-1;i<=1;i++){   // 상하 
		for(int j=-1;j<=1;j++){   // 좌우에 
			if(p.board[x+i][y+j]==-1){   // (i,j)방향에 2p의 돌이 있으면 
				for(int l=2;true;l++){   // (i,j)방향의 그 다음 돌부터 
					if(p.board[x+l*i][y+l*j]==0) break;   
				   // 빈칸이 나오면 먹을 수 없는 돌이므로 (i,j)방향 탐색 종료
					if(p.board[x+l*i][y+l*j]==1){   // 1p의 돌이 나오면
						// 1p의 돌이 나오기 전까지
						for(int k=1;k<l;k++){
							p.board[x+k*i][y+k*j] = 1;
							// (i,j)방향의 돌을 1p의 돌로 뒤집음
						}
						break;   // (i,j)방향 탐색 종료 
					}
				}
			}
		}
	}
	return p;   // 돌을 놓은 판 반환 
}

// 판 뒤집기
// 뒤집은 판 반환 
node1 FLIP(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			p.board[i][j] *= -1; 
		}
	}
	return p;
}

void SETUP()   // 게임 시작 전 설정
{
	srand(time(NULL));   // 랜덤함수(rand())를 사용하기 위한 함수 
	 
	// 보드판 초기화 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			game.board[i][j] = 0;
			put_.board[i][j] = 0;
			eat_.board[i][j] = 0;
		}
	}
	game.board[4][4] = game.board[5][5] = -1;
	game.board[4][5] = game.board[5][4] = 1;
	 
	// put_board와 eat_board 입력 (random vs random.txt파일에서 입력) 
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
