#include <stdio.h>
int main()
{
	char a, b, c;
	char i, j, k;
	while(scanf("\n%c%c%c", &a, &b, &c)!=EOF){
		if(a>b){
		
			if(a>c){
			
				i = a;
			
				if(b>c){
				
					j = b;
					k = c;
				}
				else{
					j = c;
					k = b;
				}
				}
			}
		if(b>a){
			
			if(b>c){
			
				i = b;
				if(a>c){
				
					j = a;
					k = c;
				}
				else{
					j = c;
					k = a;
				}
				}
			}
		if(c>b){
		
			if(c>a){
			
				i = c;
				if(b>a){
				
					j = b;
					k = a;
				}
				else{
					j = a;
					k = b;
				}
				}
			
			}
					
		printf("%c %c %c\n", k, j, i);
	}
	return 0;
}
