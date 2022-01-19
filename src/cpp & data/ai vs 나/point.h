

double POINT(node1 p, int x, int y)
{
	double point=0;
	point += put.board[x][y]/put_gap*C_put;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							point += p.board[x+k*i][y+k*j]/eat_gap*C_eat;
						}
						break;
					}
				}
			}
		}
	}
	return point;
}

node2 LOOK(node1 p, int q)
{
	double point;
	node2 k;
	k.point = k.xy = 0;
	if(q==4) return k;
	k.point = min_point;
	k.xy = 0;
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(!CHECK_PUT(p,i,j)) continue;
			point = POINT(p,i,j)-LOOK(PUT(p,i,j),q+1).point;
			if(point>k.point){
				k.point = point;
				k.xy = i*10+j;
			}
		}
	}
	if(k.xy==0){
		k.point = _point;
		k.xy = 0;
	}
	return k;
}
