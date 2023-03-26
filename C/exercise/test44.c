#include <stdio.h>
#include <string.h>
int main()
{
	char str[81];
	gets(str);
	int k = strlen(str);
	char* p = k + str;
	while(1){
		if(p==str)
		{
			printf("%s", p);
			break;
		}
		if(*p==' ')
		{
			*p = '\0';
			printf("%s ", p+1);
		}
		p --;
	}
	return 0;
}
