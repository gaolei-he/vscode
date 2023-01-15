#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	int ans = 0;
	scanf("%d", &ans);
	
	a = ans / 100;
	c = ans % 10;
	b = (ans / 10)%10;
	
	printf("%d", (c * 100) + (b * 10) + a);
	
	return 0;
}
