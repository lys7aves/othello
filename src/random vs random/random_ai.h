// �������� �α�
// �� p���� �� �� �ִ� �� �� �������� ��ǥ ��ȯ
// return p*10+q : (p,q)�� �� 
int RANDOM_TURN(node1 p)
{
	int x, y;   // �������� ������ ��ǥ 
	 
	// �������� ��ǥ ���� 
	x = rand()%size+1;
	y = rand()%size+1;
	while(!CHECK_PUT(p,x,y)){   // �������� ������ ���� ���� �� �� ������
		// ��ǥ ������ 
		x = rand()%size+1;
		y = rand()%size+1;
	}
	 
	return x*10+y;   // ������ ��ǥ ��ȯ
}
