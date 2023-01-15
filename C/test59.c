#include <stdio.h>
int main()
{
	int m, n;
	int j, k;
	while(scanf("%d %d", &n, &m)!=EOF){
		int sum = 0;
		int i = 2;
		for(j=0;j<n;j++){
			
			sum += i;
			i += 2;
			if((j+1)%m==0&&j!=0){
				printf("%d ", sum/m);
				sum = 0;
			}
		}
		if(n%m!=0){
			int sum = 0;
			for(i=n-n%m+1;i<=n;i++){
				sum += i*2;
			}
			printf("%d ", sum/(n-m));
		}
		printf("\n");
	}
	return 0;
}
