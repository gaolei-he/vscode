#include <stdio.h>
int main()
{
	int mark = 0;
	
	scanf("%d", &mark);
	
	switch(mark){
		case 9: printf("A\n"); break;
		case 8: printf("B\n"); break;
		case 7: printf("C\n"); break;
		case 6: printf("D\n"); break;
		case 5:
		default: printf("E\n"); break;
	}
	while (1){
		printf("%d\n", mark *= 2);
	}
	return 0;
	
}
