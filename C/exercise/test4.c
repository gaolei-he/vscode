#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);
	d = a;
	while (b>1){
		d = d*a;
		b -= 1;
	}
	printf("%d\n", d%c);
	return 0;
}
