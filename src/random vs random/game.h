// 게임을 진행시키는 함수 
void PLAY_GAME()
{ 
	int k=1, xy, z;
	// k : 차례 표시(1 : 1p / 2 : 2p)
	// xy : 좌표 (10의 자리 : x좌표 / 1의 자리 : y좌표) 
	// z : 게임의 승패 여부 (0 : 무승부 / 1 : 1p승 / 2 : 2p승) 
	  
	SETUP();   // 게임 설정 
	 
	PRINT_BOARD(game);   // 보드판 출력
	// 게임 진행 
	while(!THE_END(game)){   // 게임이 끝나지 않을 때까지 
		k = 3-k;   // 차례 바꾸기
		if(k==1){   // 1p 차례일 때 
			if(CAN_DO(game)){   // 둘 곳이 있으면 
				xy = RANDOM_TURN(game);   // 랜덤 좌표 선택 
				REMEMBER(game,xy,1);   // 1p가 둔 좌표 저장 
				game = PUT(game,xy/10,xy%10);   // 돌 놓기 
			}
			else{   // 둘 곳이 없으면
				// 아무것도 하지 않고(두지 않고) 
				printf("ONE MORE\n");   // "ONE MORE"출력 후 
				continue;   // 차례 넘김 
			}
		}
		else{   // 2p차례일 때
			// option.h헤더파일의 모든 함수는 1p가 기준. 1p의 입장으로 판 바꾸기
			game = FLIP(game);   // 판을 뒤집기(판을 1p의 입장으로 변환)
			if(CAN_DO(game)){   // 둘 곳이 있으면 
				xy = RANDOM_TURN(game);   // 랜덤 좌표 선택 
				REMEMBER(game,xy,-1);   // 2p가 둔 좌표 저장 
				game = PUT(game,xy/10,xy%10);   // 돌 놓기 
			}
			else{   // 둘 곳이 없으면
				// 아무것도 하지 않고(두지 않고) 
				printf("ONE MORE\n");   // "ONE MORE"출력 후 
				game = FLIP(game);   // 판을 뒤집고(원상복귀시키고) 
				continue;   // 턴 넘김 
			}
			game = FLIP(game);   // 판을 뒤집음(원상복귀시킴) 
		}
		PRINT_BOARD(game);   // 보드판 출력 
	}
	z = WHO_WIN(game);   // 누가 이겼는지 판단 
	if(z==0){   // 무승부이면
		draw++;   // 무승부 횟수+1 
		ANALYSIS(0);   // 결과 분석 
	}
	else if(z==1){   // 1p 승리 시
		win++;   // 승리 횟수+1 
		ANALYSIS(1);   // 결과 분석 
	}
	else{   // 2p가 승리 시
		lose++;   // 패배 횟수+1 
		ANALYSIS(-1);   // 결과 분석
	}
}
