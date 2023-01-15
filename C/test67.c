#include <stdio.h>
int main()
{
	while(1){
	
	double m = 0.08121, r = 0.02, g = 9.8;
	int i;
	double sum1 = 0, sum2 = 0, a;
	for(i=0;i<3;i++){
		scanf("%lf", &a);
		sum2 += a;
	}
	sum2 /= 3;
	
	for(i=0;i<3;i++){
		scanf("%lf", &a);
		sum1 += a;
	}
	sum1 /= 3;
	double ans = m*g*r/(sum2-sum1)-sum2/(sum2-sum1)*m*r*r;
	printf("%f %f ", sum2, sum1);
	printf("%f\n", ans);
	}
	
	return 0;
 } 
