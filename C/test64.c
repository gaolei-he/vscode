#include <stdio.h>
int main()
{
	int a[10001];
	int b[10001];
	int n, t, i;
	while(scanf("%d", &n)!=EOF){
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
			b[i]=a[i];
			if(a[i]<0){
				b[i]=-b[i];
			}
		}
		int max = b[0];
		int min = b[0];
		int j;
		for(j=0;j<n;j++){
		
			for(i=0;i<n;i++){
				if(max<b[i]){
					max = b[i];
					t = i;
				}if(min>b[i]){
					min = b[i];
				}
			}
			
			printf(" %d", a[t]);
			max = min;
			a[t]=min-1;
	}
	}
	return 0;
}
