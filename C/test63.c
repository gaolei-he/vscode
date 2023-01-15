#include <stdio.h>
int a[1002];
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		if(m==0&&n==0) break;
		int i, j;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		int ret = 0;
		for(i=0;i<n;i++){
		
			if(ret==0){
				printf("%d", a[i]);
				ret = 1;
			}else if(a[i]<=m&&a[i+1]>m){
				printf(" %d %d", a[i], m);
			}
			else{
				printf(" %d", a[i]);
			}
			
		}
		printf("\n");
		
	}
	return 0;
}
