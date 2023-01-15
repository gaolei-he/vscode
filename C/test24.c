#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, p;
	scanf("%d %d %d", &a, &b, &p);
  	a = pow(a,b);
  	b = a % p;
  	printf("%d\n", b);
	return 0;
}
