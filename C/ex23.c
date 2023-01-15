#include <stdio.h>
int main()
{
	double a, b;
	int c;
	char d;
	scanf("%lf %d %c %lf", &a, &c, &d, &b);
	printf("%c %d %.2f %.2f", d, c, a, b);
	
	return 0;
}
