
int USER_TURN(node1 user, bool z)
{
	int p, x, y, zz=1;
	while(1){
		p = getch();
		if(p==72){
			px = DOWN(px,size);
		}
		else if(p==75){
			py = DOWN(py,size);
		}
		else if(p==77){
			py = UP(py,size);
		}
		else if(p==80){
			px = UP(px,size);
		}
		else if(p==13 || p==32){
			if(CHECK_PUT(user,px,py)){
                return px*10+py;
            }
            else{
                printf("YOU CAN'T PUT\n");
                continue;
            }
		}
		else continue;
		PRINT_BOARD(z?user:FLIP(user));
	}
	return 0;
}
