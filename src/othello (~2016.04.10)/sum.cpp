#include <stdio.h>

int main()
{
	int sum=0;
	freopen("othello_data.txt","r",stdin);
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			int x;
			scanf("%d", &x);
			sum += x;
		}
	}
	printf("%d ", sum);
	sum = 0;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			int x;
			scanf("%d", &x);
			sum += x;
		}
	}
	printf("%d\n", sum);
	while(1);
	return 0;
}
