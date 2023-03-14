#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d/%d", &a, &b);
	int i=1;
	while(i<=a&&i<=b){
		if(a%i==0&&b%i==0){
			a /= i;
			b /= i;
			i = 1;
		}
		i ++;
	}
	printf("%d/%d", a, b);
	return 0;
	
}
