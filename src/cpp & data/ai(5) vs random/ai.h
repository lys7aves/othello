#define min_point -2100000000.0
#define _point -32.0   // 둘 수 없을 때의 점수 
#define C_put 18
#define C_eat 1

int AI_TURN(node1 ai)
{
	int x, y;
	double timer=clock();
	node2 k;
	
	k = LOOK(ai,0);
	x = k.xy/10;
	y = k.xy%10;
//	printf("%d %d %f\n", x, y, k.point);
//	system("pause");
//	printf("%d, (%d,%d)\n", k, x, y);
//	system("pause");
/*	x = rand()%size+1;
	y = rand()%size+1;
	while(!CHECK_PUT(ai,x,y)){
		x = rand()%size+1;
		y = rand()%size+1;
	}*/
	while(clock()-timer<=(double)delay_time);
	return x*10+y;
}

node2 LOOK(node1 p, int q)
{
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
//			printf("%f %f\n", k.point, point);
		}
	}
	if(k.xy==0){
		k.point = -10000000;//_point;
		k.xy = 0;
	}
//	printf("point(%d) : %f\n", q, point);
	return k;
}

double POINT(node1 p, int x, int y)
{
	double point=0;
	point = (double) put.board[x][y];///put_gap*C_put;
//	printf("%f ", point);
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							point += (double)eat.board[x+k*i][y+k*j]/10.0;///eat_gap*C_eat;
						}
						break;
					}
				}
			}
		}
	}
//	printf("POINT %d %d %d %f\n", x, y, put.board[x][y], point);
	return point;
}
