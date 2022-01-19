#define min_point -100000000
#define think_time 1000

int timer_;

int AI_TURN(node1 ai)
{
	int x, y;
	double timer=clock();
	node2 k;
	
	printf("\nI'm thinking. Please wait.\n"); 
	timer_ = clock();
	
	k = LOOK(ai,0);
	x = k.xy/10;
	y = k.xy%10;
	while(clock()-timer<=(double)delay_time);
	return x*10+y;
}

node2 LOOK(node1 p, int q)
{
	if(clock()-timer_>=think_time){
		timer_ = clock();
		printf("��"); 
	}
	double point;
	node2 k;
	k.point = k.xy = 0;
	if(q==5) return k;
	k.point = min_point;
	k.xy = 0;
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			if(!CHECK_PUT(p,i,j)) continue;
			point = POINT(p,i,j)-LOOK(FLIP(PUT(p,i,j)),q+1).point;
			if(point>k.point){
				k.point = point;
				k.xy = i*10+j;
			}
		}
	}
	if(k.xy==0){
		k.point = -10000000;
		k.xy = 0;
	}
	return k;
}

double POINT(node1 p, int x, int y)
{
	double point=0;
	point = (double) put.board[x][y];
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							point += (double)eat.board[x+k*i][y+k*j]/10.0;
						}
						break;
					}
				}
			}
		}
	}
	return point;
}
