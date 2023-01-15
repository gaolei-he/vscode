#include <stdio.h>
int main()
{
	int n, a;
	while(scanf("%d %d", &n, &a)!=EOF){
		int cost[n], wallet[a];
		int i, j, k;
		for(i=0;i<n;i++) scanf("%d", &cost[i]);
		for(i=0;i<a;i++) scanf("%d", &wallet[i]);
		j = 0;
		int cnt = 0;
		for(i=0;i<n;i++){
			for(;j<a;){
				if(wallet[j]>=cost[i]){
					cnt ++;
					j ++;
					break;
				}else break;
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
