#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[101], b[101];
int c[101];
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		if(n==0&&m==0) break;
		int i = 0, j;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d", &b[i]);
		}
		int cnt = 0;
		for(i=0;i<n;i++){
			int ret = 0;
			for(j=0;j<m;j++){
				if(a[i]==b[j]) ret = 1;
			}
			if(ret==0){
				c[cnt]=a[i];
				cnt ++;
			}
		}
		cnt --;
		int max = c[0];
		for(i=0;i<=cnt;i++){
			if(max<c[i]) max = c[i];
		}
		int k = 0;
		int ret = 1;
		for(i=0;i<=cnt;i++){
			int min = max + 1;			
			for(j=0;j<=cnt;j++){
				if(min>=c[j]){
					min = c[j];
					k = j;
				}
			}
			printf("%d ", min);
			ret = 0;
			c[k] = max + 1;
		}
		
		if(ret==1) printf("NULL");
		printf("\n");
	}
	
	return 0;
}
