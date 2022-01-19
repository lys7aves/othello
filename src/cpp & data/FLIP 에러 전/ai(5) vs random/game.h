
void PLAY_GAME(int k)
{
	int kk, z;
	
	SETUP();
	
	kk = 3-k;
	PRINT_BOARD(game);
	while(!THE_END(game)){
        kk = 3-kk;
		if(kk==1){
			if(k!=1) game = FLIP(game);
			if(CAN_DO(game)){
//				z = USER_TURN(game,k==1?true:false);
//				z = AI_TURN(game);
				z = RANDOM_TURN(game);
				REMEMBER(game,z,1);
				game = PUT(game,z/10,z%10);
			}
			else{
//				printf("ONE MORE\n");
				if(k!=1) game = FLIP(game);
				continue;
			}
			if(k!=1) game = FLIP(game);
		}
		else{
			if(k!=2) game = FLIP(game);
			if(CAN_DO(game)){
				z = AI_TURN(game);
//				z = RANDOM_TURN(game);
				REMEMBER(game,z,-1);
				game = PUT(game,z/10,z%10);
			}
			else{
//				printf("ONE MORE\n");
				if(k!=2) game = FLIP(game);
				continue;
			}
			if(k!=2) game = FLIP(game);
		}
		px = z/10;
		py = z%10;
		PRINT_BOARD(game);
	}
	z = WHOW_WIN(game);
	if(z==0){
//		printf("DRAW\n");
		draw++;
		ANALYSIS(0);
	}
	else if(z==k){
//		printf("YOU WIN\n");
		lose++;
		ANALYSIS(1);
	}
	else{
//		printf("COMPUTER WIN\n");
		win++;
		ANALYSIS(-1);
	}
//	system("pause");
	return;
}
