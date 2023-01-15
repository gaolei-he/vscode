#include <stdio.h>
int main()
{
	char c;
	
	while(1){
	scanf("%c", &c);
	if(c>=65&&c<=90)
		c += 32;
	else if(c>=97&&c<=122)
		c -= 32;
	else if(c=='#')
		break;
	
	printf("%c", c);
	}
	
	return 0;
}
