#include <stdio.h>
#include <string.h>
int main()
{
	char s1[79];
	gets(s1);
	int i;
	for(i=strlen(s1)-1;i!=-1;i--){
		printf("%c", s1[i]);
	}
	return 0;
}
