#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	int b = 0;
	b = a/30.48*12;
	int inch = 0;
	int foot = 0;
	inch = b%12;
	foot = b/12;
	printf("%d %d",foot,inch);
	return 0;
}
