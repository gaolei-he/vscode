#include <stdio.h>

int main()
{
	double a[103];
	
	int n;
	int b[100];
	int p;
	
	while(scanf("%d", &n)!=EOF){
		for(p=0;p<100;p++){
		b[p]=1;
	}
		int i, j, k;
		for(i=0;i<n;i++){
			scanf("%lf", &a[i]);
		}
		for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if(a[j]>a[k]){
					int t;
					t = a[j];
					a[j] = a[k];
					a[k] = t;
				}
			}
		}
		int cnt = 0;
		int ret = 0;
		for(i=0;i<n-1;i++){
			if(a[i]==a[i+1]){
				b[cnt] ++;
				ret = 1;
			}
			else if(a[i]!=a[i+1]&&ret==1){
				cnt ++;
				ret = 0;
			}else;
		}
		int max = 0;
		for(i=0;i<=cnt;i++){
			if(max<b[i]) max = b[i];
		}
		printf("%d\n", max);
	}
	
	return 0;
 } 
