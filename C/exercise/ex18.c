#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a;
	srand(time(0));
	int number = rand()%128;
	
	printf("����һ������");
	scanf("%d", &a);
	while(1){
	
		if(a>number){
			printf("̫���ˣ�Сһ��\n");
			printf("> ");
			scanf("%d", &a);
		} else if(a<number){
			printf("̫С�ˣ���һ��\n");
			printf("> ");
			scanf("%d", &a); 
		}else{
			printf("�¶��ˣ������");
			break; 
		}
	}
	return 0;
}

