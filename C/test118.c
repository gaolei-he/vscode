#include <stdio.h>
int a[1003];
int b[1000];
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i;
		int cnt = 0;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		a[i]=1;
		int num = 0;
		for(i=0;i<n;i++){
			if(a[i]==1) cnt ++;
			if(a[i+1]==1) b[num++]=a[i];
		}
		printf("%d\n", cnt);
		int ret = 0;
		for(i=0;i<num;i++){
			if(ret==0){
			ret = 1;
			printf("%d", b[i]);
			}else printf(" %d", b[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}
