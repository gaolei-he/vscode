#include <stdio.h>
#include <math.h>
int main()
{
	int n, d;
	int x[101];
	while(scanf("%d %d", &n, &d)!=EOF){
		int i, j, k;
		for(i=0;i<n;i++){
			scanf("%d", &x[i]);
		}
		for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if(x[j]>x[k]){
					int t;
					t = x[j];
					x[j] = x[k];
					x[k] = t;
				}
			}
		}
		for(i=0;i<n;i++){
			printf("%d ", x[i]);
		}
		printf("\n");
		int cnt = 2;
		for(i=1;i<n;i++){
			
			if(x[i]-x[i-1]>d*2) cnt += 2;
			else if(x[i]-x[i-1]>=d*2) cnt ++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
