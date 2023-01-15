#include <stdio.h>
//Ë³ÐòÕûÊý¼ÆËãÆ÷ 
int main()
{
	int a;
	scanf("%d", &a);
	
	char c = '0';
	int i = 0;
	while(c!='='){
		scanf("%c", &c);
		if(c=='=')
		{
			printf("%d", a);
			break;
		}
		scanf("%d", &i);
		if(c=='+'){
			a += i;
		}else if(c=='-'){
			a -= i;
		}else if(c=='*'){
			a *= i;
		}else{
			if(i==0){
				printf("ERROR\n");
				break;
			}
			a /= i;
		}
	}
	
	
}
