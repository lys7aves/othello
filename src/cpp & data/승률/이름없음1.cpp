#include <stdio.h>

int main()
{
	char x;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	while(scanf("%c", &x)!=EOF){
		int a, win, lose, draw;
		scanf("%d", &a);
		for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) scanf("%d", &a);
		for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) scanf("%d", &a);
		scanf("%d %d %d", &win, &lose, &draw);
		printf("%d  %d  %d\n", win, lose, draw);
	}
	return 0;
}
