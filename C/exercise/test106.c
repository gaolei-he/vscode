#include <stdio.h>
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		int n1, m1;
		
		printf("+");
		n1=n;
		while(n1--)
			printf("-");
		
		printf("+\n");
		
		m1=m;
		while(m1--){
		
		printf("|");
		n1=n;
		while(n1--)
			printf(" ");
		printf("|\n");
		}
		
		printf("+");
		n1=n;
		while(n1--)
			printf("-");
		
		printf("+\n\n");
		
	}
	
	return 0;
}
