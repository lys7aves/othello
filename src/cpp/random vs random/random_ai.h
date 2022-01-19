int RANDOM_TURN(node1 p)
{
	int x, y;
	
	x = rand()%size+1;
	y = rand()%size+1;
	while(!CHECK_PUT(p,x,y)){
		x = rand()%size+1;
		y = rand()%size+1;
	}
	
	return x*10+y;
}
