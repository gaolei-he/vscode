#include <stdio.h>
#include <string.h>
int main()
{
	char a[3];
	a[0]='a';
	a[2]='\0';
	printf("%d", strlen(a));
	return 0;
}
