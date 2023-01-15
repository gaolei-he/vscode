#include <stdio.h>
int main()
{
	int x, y;
	int prime;
	int i, j, k, ret=0;
	while(scanf("%d %d", &x, &y)!=EOF){
		if(x==0&&y==0){
			continue;
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
