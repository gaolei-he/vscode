#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		if(n==0) break;
		int a[101];
		int i, j;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		int min = a[0];
		for(i=0;i<n;i++){
			if(min>=a[i]){
				min = a[i];
				j = i;
			}
		}
		int t = a[0];
		a[0]=min;
		a[j]=t;
		for(i=0;i<n;i++){
			if(i!=n-1){
			printf("%d ", a[i]);
			}else{
			printf("%d", a[i]);
			}
		}
		printf("\n");
		
	}
	return 0;
}
