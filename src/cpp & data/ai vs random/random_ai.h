int RANDOM_TURN(node1 p)
{
	int x, y;
	double timer=clock();
	
	x = rand()%size+1;
	y = rand()%size+1;
	while(!CHECK_PUT(p,x,y)){
		x = rand()%size+1;
		y = rand()%size+1;
	}
	
	while(clock()-timer<=delay_time);
	return x*10+y;
}
