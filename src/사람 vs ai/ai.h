#define min_point -100000000

// ���� ��Ȳ�� �־����� �� �� �α�
// �� �ڸ� ���� ��ǥ ��ȯ
// ���� �ڸ� : x��ǥ
// ���� �ڸ� : y��ǥ 
int AI_TURN(node1 ai)
{
	int x, y;   // x��ǥ�� y��ǥ 
	node2 k;
	
	k = LOOK(ai,0);   // �� �� Ž�� 
	x = k.xy/10;   // ��ȯ�� ���� x ��ǥ�� ��ȯ 
	y = k.xy%10;   // ��ȯ�� ���� y ��ǥ�� ��ȯ 
	return x*10+y;   // ��ǥ ��ȯ 
}

node2 LOOK(node1 p, int q)
{
	double point;
	node2 k;
	k.point = k.xy = 0;   // k�� �ʱ�ȭ 
	if(q==5) return k;   // 5�� �ձ��� ������ Ž�� ���� 
	k.point = min_point;   // ������ �ּڰ����� ����
	
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){   // ��� ��ǥ Ž�� 
			if(!CHECK_PUT(p,i,j)) continue;   // �� �� ������ �Ѿ 
			point = POINT(p,i,j)-LOOK(FLIP(PUT(p,i,j)),q+1).point;   // ���� = �ش� ���� - �����Ͽ� ��밡 ���� �� �ִ� ���� 
			if(point>k.point){   // ���������� �������� ���� ������ ������ 
				k.point = point;   // ���� ���� 
				k.xy = i*10+j;   // ��ǥ ���� 
			}
		}
	}
	if(k.xy==0){   // ��ǥ ������ ���� �ʾ����� (�� �� �ִ� ���� ������)
		k.point = -10000000;   // -10000000���� �ο�
	}
	return k;   // ������ ��ǥ�� ����� ����ü ��ȯ
}

// ���� ���
// �� p���� ��ǥ (x,y)�� ���� ���� ���� ���
// ���� ��ȯ 
double POINT(node1 p, int x, int y)
{
	double point=0;   // ���� 0���� �ʱ�ȭ
	
	point = (double) put.board[x][y];   // ���� ���� ���� �Է�
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){   // �ȹ� Ž��
			if(p.board[x+i][y+j]==-1){   // ����� ���� ������
				for(int l=2;true;l++){   // �� �� Ž��
					if(p.board[x+l*i][y+l*j]==0) break;   // ��ĭ�� ���� ������ Ž�� ����
					if(p.board[x+l*i][y+l*j]==1){   // ���� ���� ���� ������
						// ��� �� ������
						for(int k=1;k<l;k++){
							point += (double)eat.board[x+k*i][y+k*j]/10.0;
						}
						break;   // Ž�� ���� 
					}
				}
			}
		}
	}
	return point;   // ���� ��ȯ
}
