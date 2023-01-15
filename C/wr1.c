#include <stdio.h>

int main()
{
	int price = 0;
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a, b);
	
	
	const int amount = 100;
	
	printf("请输入金额（元）： ");
	
	scanf("%d", &price);
	
	int change = amount - price;
	
	printf("Here's the change: RMB%d \n", change);
	
	return 0;

}
