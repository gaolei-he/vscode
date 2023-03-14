#include <stdio.h>
long long x[1006];
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i;
		for(i=0;i<n;i++){
		
		scanf("%lld", &x[i]);
		}
		int ret = 0;
		for(i=0;i<n;i++){			
			if(x[i]%2==0) x[i] --;
			if(ret==0){
				printf("%lld", x[i]);
				ret = 1;
			}else printf(" %lld", x[i]);
			
		}
	}
	
	return 0;
}
