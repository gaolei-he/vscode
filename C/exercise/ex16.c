//´òÓ¡³Ë·¨¿Ú¾÷ 
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a = 1, b = 1;
	while(b<=n){
		while(a<=b){
			printf("%d*%d=%d", a, b, a*b);
			
			if(a==b){
				printf("\n");
			}else if(a*b/10==0){
				printf("   ");
			}else{
				printf("  ");
			}
			a ++;
		}
		a = 1;
		b ++;
	}
	return 0;
}
