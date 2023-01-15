#include <stdio.h>
int main()
{
	/*char = 1
	short = 2
	int = 4
	long = 4
	long long = 8*/
	unsigned char c = 255;
	char a = 255;
	short b = 255;
	short d = 65535;
	char e =127;
	e = e+1;
	char f = -128;
	f -= 1;
	//Ò»¸öÔ² 
	printf("%d\n", f);
	printf("%d\n", e);
	printf("%d %d %d %d", a, b, c, d);
	return 0;
	// 1111 1111
	// 0000 0000 1111 1111
	
}

