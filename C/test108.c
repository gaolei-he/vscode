#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int cnt = 0;
		int i;
		for(i=1;i<=n;i++){
			if(n%i==0) cnt ++;
		}
		if(cnt%2==0) printf("0\n");
		else printf("1\n");
	}
	
	
	return 0;
 } 
