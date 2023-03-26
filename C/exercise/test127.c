#include <stdio.h>
long long a[300000];
int main()
{
	long long n, m;
	
	while(scanf("%lld %lld", &n, &m)!=EOF){
		int i;
		for(i=1;i<=n;i++) scanf("%lld", &a[i]);
		if(a[1]<m) printf("0");
		else printf("%d", a[1]/m);
		int tem = a[1]%m;
		for(i=2;i<=n;i++){
			tem += a[i];
			printf(" %d", tem/m);
			tem = tem%m;
		}
		printf("\n");
	}
	
	return 0;
}
