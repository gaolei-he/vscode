#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d", &a);
	while (a != 0){
		b = a%10;
		printf("%d", b);
		a /= 10;
		c ++;
	}
	printf(" %d\n", c);
	return 0;
}
