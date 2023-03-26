#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	
	if(n<0){
		printf("fu ");
		n = -n;
	}
	int i = 1, tem = n;
	while(tem!=0){
		tem /=10;
		i *= 10;
	}
	i /= 10;
	//printf("%d", i);
	int p = 0;
	while(i>=1){
		p = n / i;
		n = n % i;
		i /= 10;
		switch(p){
			case 0:printf("ling "); break;
			case 1:printf("yi "); break;
			case 2:printf("er ");  break;
			case 3:printf("san "); break;
			case 4:printf("si ");  break;
			case 5:printf("wu "); break;
			case 6:printf("liu "); break;
			case 7:printf("qi "); break;
			case 8:printf("ba "); break;
			case 9:printf("jiu "); break;	 
		}

	}
	return 0;
}
