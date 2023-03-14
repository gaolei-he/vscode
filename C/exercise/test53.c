#include <stdio.h>
int main()
{
	int m, n, i;
	int a1, a2, a3;

	while(scanf("%d %d", &m, &n)!=EOF){
		int ret = 0;
		for(i=m;i<n;i++){
			a1 = i%10;
			a2 = i/10%10;
			a3 = i/100;
			if(i == a1*a1*a1+a2*a2*a2+a3*a3*a3){
				printf("%d ", i);
				ret = 1;
			}
		}
		if(ret == 0){
			printf("no");
		}
		printf("\n");
	}
	return 0;
}
