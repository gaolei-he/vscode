#include <stdio.h>
#include <string.h>
int main()
{
	char str[180];
	char* p = str;
	gets(str);
	char c;
	scanf("%c", &c);
	int ret = 0;
	while(p<=str+strlen(str)){
		if(*p==c){
			*(p-1)='\0';
			printf("%s\n",p);
			ret = 1;
			break;
		}
		p ++;
		
	}
	if(ret==0){
		printf("Not found\n");
	}
	return 0;
}
