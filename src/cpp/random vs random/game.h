void PLAY_GAME()
{
	int k=1, z;
	
	SETUP();
	
	PRINT_BOARD(game);
	while(!THE_END(game)){
        k = 3-k;
		if(k==1){
			if(CAN_DO(game)){
				z = RANDOM_TURN(game);
				REMEMBER(game,z,1);
				game = PUT(game,z/10,z%10);
			}
			else{
				printf("ONE MORE\n");
				continue;
			}
		}
		else{
			game = FLIP(game);
			if(CAN_DO(game)){
				z = RANDOM_TURN(game);
				REMEMBER(game,z,-1);
				game = PUT(game,z/10,z%10);
			}
			else{
				printf("ONE MORE\n");
				game = FLIP(game);
				continue;
			}
			game = FLIP(game);
		}
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
	return;
}
