// 1����
// ������ ��ȯ 
int UP(int p, int q)
{
	return p%q+1;   // p 1���� (p�� q���� Ŀ���� p=1) 
}

// 1����
// ���Ұ� ��ȯ 
int DOWN(int p, int q)
{
	return (p-2+q)%q+1;   // p 1���� (p�� 1���� �۾����� p=q) 
}
