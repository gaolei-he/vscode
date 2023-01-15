#include <stdio.h>
//找出不同的球 
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b)
		printf("C\n");
	else if (c == a)
		printf("B\n");
	else
		printf("C\n");
	return 0;
}
