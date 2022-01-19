#define min_point -100000000

// 판의 상황이 주어졌을 때 돌 두기
// 두 자리 수로 좌표 반환
// 십의 자리 : x좌표
// 일의 자리 : y좌표 
int AI_TURN(node1 ai)
{
	int x, y;   // x좌표와 y좌표 
	node2 k;
	
	k = LOOK(ai,0);   // 둘 곳 탐색 
	x = k.xy/10;   // 반환된 값을 x 좌표로 전환 
	y = k.xy%10;   // 반환된 값을 y 좌표로 전환 
	return x*10+y;   // 좌표 반환 
}

node2 LOOK(node1 p, int q)
{
	double point;
	node2 k;
	k.point = k.xy = 0;   // k값 초기화 
	if(q==5) return k;   // 5수 앞까지 봤으면 탐색 종료 
	k.point = min_point;   // 점수를 최솟값으로 셋팅
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){   // 모든 좌표 탐색 
			if(!CHECK_PUT(p,i,j)) continue;   // 둘 수 없으면 넘어감 
			point = POINT(p,i,j)-LOOK(FLIP(PUT(p,i,j)),q+1).point;   // 점수 = 해당 점수 - 다음턴에 상대가 얻을 수 있는 점수 
			if(point>k.point){   // 이전까지의 점수보다 현재 점수가 높으면 
				k.point = point;   // 점수 갱신 
				k.xy = i*10+j;   // 좌표 갱신 
			}
		}
	}
	if(k.xy==0){   // 좌표 갱신이 되지 않았으면 (둘 수 있는 곳이 없으면)
		k.point = -10000000;   // -10000000점수 부여
	}
	return k;   // 점수와 좌표가 저장된 구조체 반환
}

// 점수 계산
// 판 p에서 좌표 (x,y)에 뒀을 때의 점수 계산
// 점수 반환 
double POINT(node1 p, int x, int y)
{
	double point=0;   // 점수 0으로 초기화
	
	point = (double) put.board[x][y];   // 뒀을 때의 점수 입력
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){   // 팔방 탐색
			if(p.board[x+i][y+j]==-1){   // 상대의 돌이 있으면
				for(int l=2;true;l++){   // 그 줄 탐색
					if(p.board[x+l*i][y+l*j]==0) break;   // 빈칸이 먼저 나오면 탐색 종료
					if(p.board[x+l*i][y+l*j]==1){   // 나의 돌이 먼저 나오면
						// 상대 돌 뒤집기
						for(int k=1;k<l;k++){
							point += (double)eat.board[x+k*i][y+k*j]/10.0;
						}
						break;   // 탐색 종료 
					}
				}
			}
		}
	}
	return point;   // 점수 반환
}
