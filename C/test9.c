#include <stdio.h>

int main()
{
	int a;
	
	int number = 32;
	
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
		scanf("%d", &a);
	}
	return 0;
}

