#include <stdio.h>
int main()
{
	int x = 0;
	scanf("%d", &x);
	
	int b = x / 16 * 10;
	int c = x % 16;
	printf("%d\n", b + c);
	
	return 0;
}
