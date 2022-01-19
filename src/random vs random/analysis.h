// ������ ����
// ��p�� k��ǥ�� z�� ���� ���� �ǹ�
// k : 1�� �ڸ� : x��ǥ / 10�� �ڸ� : y��ǥ
// z : 1 : 1p�� �� ��� / -1 : 2p�� �� ���
void REMEMBER(node1 p, int k, int z)
{
	int x, y;   // ��ǥ 
	// k�� ��ǥ�� ���� ���ϰ� �ٲ� 
	x = k/10;
	y = k%10;
	 
	put_.board[x][y] = z;   // (x,y)�� z�� �״ٰ� ǥ��
	// �Դ� �� �Ǻ� 
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){ 
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							eat_.board[x+k*i][y+k*j] += z;
							// z�� ���� �� ǥ�� 
						}
						break;
					}
				}
			}
		}
	}
}

// z�� �̰��� �� ������ �м�
// z : 1 : 1p�� �� ��� / -1 : 2p�� �� ���
void ANALYSIS(int z)
{
	// random vs random.txt���� ���� 
	FILE *out;
	out = fopen("random vs random.txt","w");
	 
	// put_board ���� 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d    ", put.board[i][j] + z*put_.board[i][j]);   
		    // ���� put_board + ���ο� put_boarad 
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	 
	// eat_board ���� 
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d    ", eat.board[i][j] + z*eat_.board[i][j]);   
		// ���� eat_board + ���ο� eat_boarad 
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	 
	fprintf(out, "%d %d %d\n", win, lose, draw);   // ���й� ��� 
	fclose(out);   // ���� ����� ���� 
}
