#include <stdio.h>
int main()
{
	int n, i, cnt;
	int out[11];
	
	while(scanf("%d", &n)!=EOF){
		for(i=0,cnt=0;n!=0;i++,cnt++){
			out[i]=n%2;
			n /= 2;
		}
		for(i=cnt-1;i!=-1;i--){
			printf("%d", out[i]);
		}
		printf("\n");
	}
	
	return 0;
}
