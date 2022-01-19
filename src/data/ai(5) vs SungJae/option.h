void SETUP()
{
	int mini=0, maxi=0;
	px = py = 4;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			game.board[i][j] = 0;
			put_.board[i][j] = 0;
			eat_.board[i][j] = 0;
		}
	}
	game.board[4][4] = game.board[5][5] = -1;
	game.board[4][5] = game.board[5][4] = 1;
	remember[0] = 0;
	sprintf(file_position, "othello");
	sprintf(name, "ai(5) vs SungJae");
	sprintf(file_name, "%s\\%s brain.txt", file_position, name);
	FILE *in;
	in = fopen(file_name,"r");
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fscanf(in, "%d", &put.board[i][j]);
			mini = min(mini,put.board[i][j]);
			maxi = max(maxi,put.board[i][j]);
		}
	}
	put_gap = maxi-mini;
	if(put_gap==0) put_gap = 1;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fscanf(in, "%d", &eat.board[i][j]);
			eat_gap = max(eat_gap, (double)put.board[i][j]);
		}
	}
	if(eat_gap==0) eat_gap = 1;
	fscanf(in, "%d %d %d", &win, &lose, &draw);
	fclose(in);
}

bool THE_END(node1 check)
{
	bool a=false, b=false, x=true, y=true, z=true;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(check.board[i][j]==0) z = false;
			if(check.board[i][j]==1) a = true;
			if(check.board[i][j]==-1) b = true;
			if(CHECK_PUT(check,i,j)) x = false;
			if(CHECK_PUT(FLIP(check),i,j)) y = false;
		}
	}
	if(!a || !b || (x && y) || z) return true;
	return false;
}

bool CHECK_PUT(node1 p, int x, int y)
{
	if(p.board[x][y]!=0) return false;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=size;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1) return true;
				}
			}
		}
	}
	return false;
}

node1 FLIP(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			p.board[i][j] *= -1;
		}
	}
	return p;
}

node1 PUT(node1 p, int x, int y)
{
	p.board[x][y] = 1;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							p.board[x+k*i][y+k*j] = 1;
						}
						break;
					}
				}
			}
		}
	}
	return p;
}

bool CAN_DO(node1 p)
{
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(CHECK_PUT(p,i,j)) return true;
		}
	}
	return false;
}

int WHOW_WIN(node1 p)
{
	int a=0, b=0;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(p.board[i][j]==1) a++;
			if(p.board[i][j]==-1) b++;
		}
	}
	if(a==b) return 0;
	else if(a>b) return 1;
	else return 2;
}
