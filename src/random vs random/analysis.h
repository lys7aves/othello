// 데이터 저장
// 판p의 k좌표에 z가 뒀을 때를 의미
// k : 1의 자리 : x좌표 / 10의 자리 : y좌표
// z : 1 : 1p가 둔 경우 / -1 : 2p가 둔 경우
void REMEMBER(node1 p, int k, int z)
{
	int x, y;   // 좌표 
	// k의 좌표를 쓰기 편하게 바꿈 
	x = k/10;
	y = k%10;
	 
	put_.board[x][y] = z;   // (x,y)에 z가 뒀다고 표시
	// 먹는 돌 판별 
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){ 
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							eat_.board[x+k*i][y+k*j] += z;
							// z가 먹은 돌 표시 
						}
						break;
					}
				}
			}
		}
	}
}

// z가 이겼을 때 데이터 분석
// z : 1 : 1p가 둔 경우 / -1 : 2p가 둔 경우
void ANALYSIS(int z)
{
	// random vs random.txt파일 열기 
	FILE *out;
	out = fopen("random vs random.txt","w");
	 
	// put_board 갱신 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d    ", put.board[i][j] + z*put_.board[i][j]);   
		    // 기존 put_board + 새로운 put_boarad 
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	 
	// eat_board 갱신 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d    ", eat.board[i][j] + z*eat_.board[i][j]);   
		// 기존 eat_board + 새로운 eat_boarad 
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	 
	fprintf(out, "%d %d %d\n", win, lose, draw);   // 승패무 기록 
	fclose(out);   // 파일 입출력 종료 
}
