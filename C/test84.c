#include <stdio.h>
#include <math.h>
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		if(n==0&&m==0) break;
		int n1 = n%1000;
		while(m!=1){
			n1 = n1*n%1000;
			m--;
		}
		printf("%d\n", n1);
	}
	return 0;
}
