#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int number = rand()%100;
	
	int count = 0;
	int a = 0;
	
	printf("������һ�������� \n");
	printf("> ");
	do{
	scanf("%d", &a);
	count ++;
	if (a>number){
		printf("̫���ˣ�Сһ��\n");
		printf("> ");
	}else if (a<number){
		printf("̫С�ˣ���һ��\n");
		printf("> ");
	}else{
		printf("̫���ˣ��¶���\n");
		printf("����%d��", count);
	} }while(a != number);
	return 0;
}
