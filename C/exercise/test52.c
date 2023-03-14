#include <stdio.h>
#include <math.h>
int main()
{
	int n, m, i;
	while(scanf("%d %d", &n, &m)!=EOF){
		double sum = 0;
		double t = n*1.0;
		for(i=0;i<m;i++){
			sum += t; 
			t = sqrt(t);
		}
		printf("%.2f", sum);
	}
	return 0;
}
