#include <stdio.h>
int main()
{
	printf("%d\n", 5==3);
	int a = 5==3;
	if (a==0) {
		printf("yes\n");
	}
	printf("%d\n", 7 >= 3 + 4);
	
	int b = 0;
	b = 5 > 3 == 6 > 4;
	int c = 0, d = 0, e = 0;
	c = 6 > 5 > 4;
	d = a == b == 6;
	e = a == b > 0;
	
	printf("%d %d %d %d\n", b, c, d, e);
	
	if (3==3)
		printf("yes");
	
	return 0;
	
}
