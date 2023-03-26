#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int number = rand()%100;
	
	int count = 0;
	int a = 0;
	
	printf("请输入一个整数： \n");
	printf("> ");
	do{
	scanf("%d", &a);
	count ++;
	if (a>number){
		printf("太大了，小一点\n");
		printf("> ");
	}else if (a<number){
		printf("太小了，大一点\n");
		printf("> ");
	}else{
		printf("太棒了，猜对了\n");
		printf("猜了%d次", count);
	} }while(a != number);
	return 0;
}
