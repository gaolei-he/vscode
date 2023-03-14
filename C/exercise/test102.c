#include <stdio.h>
int main()
{
	int i,c,s;
	long long a[21], sum[21];
	sum[1]=1;
	sum[0]=1;
	a[1]=0;
	a[2]=1;
	for(i=2;i<21;i++){
		sum[i] = sum[i-1]*i;
		if(i>2) a[i]=(i-1)*(a[i-1]+a[i-2]);
		}
	
	scanf("%d", &c);
	while(c--){
	
		int m, n;
		scanf("%d %d", &n, &m);
	 
		printf("%lld\n",sum[n]/sum[m]/sum[n-m]*a[m]);
		
	}
	
	return 0;
}

