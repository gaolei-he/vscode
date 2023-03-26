//µ¥´Ê³¤¶È
#include <stdio.h>
int main()
{
	char c;
	int count = 0;
	scanf("%c", &c);
	while(1){
		if(c!=' '&&c!='.'){
			count ++;			
		}
		else if(c==' '){
		printf("%d ", count);
		count = 0;
		}
		else{
			printf("%d", count);
			break;
		}
		scanf("%c", &c);
		
	}
	return 0;
} 
