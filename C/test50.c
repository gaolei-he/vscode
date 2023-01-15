#include <stdio.h>
int main()
{
	int m, n;

	while(scanf("%d %d", &m, &n)!=EOF){
		int sum1 = 0, sum2 = 0, i;
		for(i=m;i<=n;i++){
			if(i%2==0){
				sum1 += i*i;
			}else{
				sum2 += i*i*i;
			}
	}
	printf("%d %d\n", sum1, sum2);
	}
	return 0;
}
