#include <stdio.h>
int main()
{
	int n, max;
	while(scanf("%d %d", &n, &max)!=EOF){
		int a[max+1];
		int i, j, k;
		int num1, num2;
		for(i=1;i<=max;i++){
			a[i]=1;
		}
		for(i=0;i<n;i++){
			scanf("%d %d", &num1, &num2);
			for(j=num1;j<=num2;j++)	a[j] = 0;
			
		}
		int cnt = 0;
		for(i=1;i<=max;i++){
			if(a[i]==1) cnt ++;
		}
		printf("%d\n", cnt);
		int ret = 0;
		for(i=1;i<=max;i++){
			if(ret==0&&a[i]==1){
				printf("%d", i);
				ret = 1;
			}else if(a[i]==1) printf(" %d", i);
			else;
		}
		printf("\n");
	}
	
	return 0;
}
