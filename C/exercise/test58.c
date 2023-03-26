#include <stdio.h>
int main()
{
	int x, y;
	int prime;
	int i, j, k;
	while(scanf("%d %d", &x, &y)!=EOF){
		int ret = 0;
		if(x==0&&y==0){
			break;
		}else{
			for(i=x;i<=y;i++){
				prime = i*i+i+41;
				for(j=2;j<prime;j++){
					k = prime%j;
					if(k==0){
						ret = 1;
					}
				}
			}
		}
		if(ret==1){
			printf("Sorry\n");
		}else{
			printf("OK\n");
		}
	}
	return 0;
}
