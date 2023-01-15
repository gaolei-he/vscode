#include <stdio.h>
int main()
{
	int a = 5, b = 6;
	int t = 0;
	t = a;
	a = b;
	b = t;
	printf("%d %d\n",a, b);
	return 0;
}
