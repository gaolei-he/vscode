#include <stdio.h>
#include <math.h>
int main()
{
	int x[101], y[101];
	int n;
	while(scanf("%d", &n)!=EOF){
		int i;
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
		}
		double sum = 0;
		for(i=0;i<n;i++){
			if(i==n-1) sum += x[i]*y[0]-x[0]*y[i];
			sum += x[i]*y[i+1]-x[i+1]*y[i];

		}
		printf("%.1f\n", sum/2);
	}
	
	return 0;
 } 
