// 랜덤으로 두기
// 판 p에서 들 수 있는 곳 중 랜덤으로 좌표 반환
// return p*10+q : (p,q)에 둠 
int RANDOM_TURN(node1 p)
{
	int x, y;   // 랜덤으로 지정한 좌표 
	 
	// 랜덤으로 좌표 선택 
	x = rand()%size+1;
	y = rand()%size+1;
	while(!CHECK_PUT(p,x,y)){   // 랜덤으로 지정한 곳에 돌을 둘 수 없으면
		// 좌표 재지정 
		x = rand()%size+1;
		y = rand()%size+1;
	}
	 
	return x*10+y;   // 지정한 좌표 반환
}
