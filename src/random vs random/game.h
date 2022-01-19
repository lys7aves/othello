// ������ �����Ű�� �Լ� 
void PLAY_GAME()
{ 
	int k=1, xy, z;
	// k : ���� ǥ��(1 : 1p / 2 : 2p)
	// xy : ��ǥ (10�� �ڸ� : x��ǥ / 1�� �ڸ� : y��ǥ) 
	// z : ������ ���� ���� (0 : ���º� / 1 : 1p�� / 2 : 2p��) 
	  
	SETUP();   // ���� ���� 
	 
	PRINT_BOARD(game);   // ������ ���
	// ���� ���� 
	while(!THE_END(game)){   // ������ ������ ���� ������ 
		k = 3-k;   // ���� �ٲٱ�
		if(k==1){   // 1p ������ �� 
			if(CAN_DO(game)){   // �� ���� ������ 
				xy = RANDOM_TURN(game);   // ���� ��ǥ ���� 
				REMEMBER(game,xy,1);   // 1p�� �� ��ǥ ���� 
				game = PUT(game,xy/10,xy%10);   // �� ���� 
			}
			else{   // �� ���� ������
				// �ƹ��͵� ���� �ʰ�(���� �ʰ�) 
				printf("ONE MORE\n");   // "ONE MORE"��� �� 
				continue;   // ���� �ѱ� 
			}
		}
		else{   // 2p������ ��
			// option.h��������� ��� �Լ��� 1p�� ����. 1p�� �������� �� �ٲٱ�
			game = FLIP(game);   // ���� ������(���� 1p�� �������� ��ȯ)
			if(CAN_DO(game)){   // �� ���� ������ 
				xy = RANDOM_TURN(game);   // ���� ��ǥ ���� 
				REMEMBER(game,xy,-1);   // 2p�� �� ��ǥ ���� 
				game = PUT(game,xy/10,xy%10);   // �� ���� 
			}
			else{   // �� ���� ������
				// �ƹ��͵� ���� �ʰ�(���� �ʰ�) 
				printf("ONE MORE\n");   // "ONE MORE"��� �� 
				game = FLIP(game);   // ���� ������(���󺹱ͽ�Ű��) 
				continue;   // �� �ѱ� 
			}
			game = FLIP(game);   // ���� ������(���󺹱ͽ�Ŵ) 
		}
		PRINT_BOARD(game);   // ������ ��� 
	}
	z = WHO_WIN(game);   // ���� �̰���� �Ǵ� 
	if(z==0){   // ���º��̸�
		draw++;   // ���º� Ƚ��+1 
		ANALYSIS(0);   // ��� �м� 
	}
	else if(z==1){   // 1p �¸� ��
		win++;   // �¸� Ƚ��+1 
		ANALYSIS(1);   // ��� �м� 
	}
	else{   // 2p�� �¸� ��
		lose++;   // �й� Ƚ��+1 
		ANALYSIS(-1);   // ��� �м�
	}
}
