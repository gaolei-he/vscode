#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, d;
	double l;
	while(scanf("%lf %lf %lf %lf", &a, &b, &c, &d)!=EOF){
		l = sqrt((c-a)*(c-a)+(d-b)*(d-b));
		printf("%.2f\n", l);
	}
	return 0;
}
