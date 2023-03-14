#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a;
	srand(time(0));
	int number = rand()%128;
	
	printf("输入一个数：");
	scanf("%d", &a);
	while(1){
	
		if(a>number){
			printf("太大了，小一点\n");
			printf("> ");
			scanf("%d", &a);
		} else if(a<number){
			printf("太小了，大一点\n");
			printf("> ");
			scanf("%d", &a); 
		}else{
			printf("猜对了，真棒！");
			break; 
		}
	}
	return 0;
}

