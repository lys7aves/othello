// 1증가
// 증가값 반환 
int UP(int p, int q)
{
	return p%q+1;   // p 1증가 (p가 q보다 커지면 p=1) 
}

// 1감소
// 감소값 반환 
int DOWN(int p, int q)
{
	return (p-2+q)%q+1;   // p 1감소 (p가 1보다 작아지면 p=q) 
}
