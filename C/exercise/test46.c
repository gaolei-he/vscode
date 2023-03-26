#include <stdio.h>
#include <string.h>
char s1[81], s2[81];
int main()
{
	gets(s1);
	gets(s2);
	char* p = strstr(s1,s2);
	int i;
	while(1){
		char* p = strstr(s1,s2);
		if(p){
			char* p = strstr(s1,s2);
			for(i=0;i<strlen(s1)-strlen(s2);i++){
				p[i]=p[strlen(s2)+i];
			}	
		}else{
			puts(s1);
			break;
		}
	}
	return 0;
}
