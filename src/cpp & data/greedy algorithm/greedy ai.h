#define min_point -2100000000.0
#define _point -32.0   // �� �� ���� ���� ���� 
#define C_put 18
#define C_eat 1

node2 LOOK(node1 p, int q, int r);
double POINT(node1 p, int x, int y);

int GREEDY_AI_TURN(node1 ai)
{
	int x, y;
	double timer=clock();
	node2 k;
	
	k = LOOK(ai,0,1);
	x = k.xy/10;
	y = k.xy%10;
	while(clock()-timer<=(double)delay_time);
	return x*10+y;
}

node2 LOOK(node1 p, int q, int r)
{
	int c=0;
	double point;
	node2 k;
	k.point = k.xy = 0;
	if(THE_END(p)) return k;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(CHECK_PUT(p,i,j)) c++;
		}
	}
	if(c*r>10000) return k;
	k.point = min_point;
	k.xy = 0;
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(!CHECK_PUT(p,i,j)) continue;
			point = POINT(p,i,j)-LOOK(FLIP(PUT(p,i,j)),q+1,r*c).point;
			if(point>k.point){
				k.point = point;
				k.xy = i*10+j;
			}
		}
	}
	if(k.xy==0){
		k.point = 0-LOOK(FLIP(p),q+1,r).point;
		k.xy = 0;
	}
	return k;
}

double POINT(node1 p, int x, int y)
{
	double point=1;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							point++;
						}
						break;
					}
				}
			}
		}
	}
	return point;
}
