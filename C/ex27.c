#include <stdio.h>
int main()
{
	int num;
	scanf("%d", &num);
	int i, j, k;
	i = num / 100;
	j = (num%100)/10;
	k = num%10;
	while(i!=0){
		printf("B");
		i --;
	}
	while(j!=0){
		printf("S");
		j --; 
	}
	int n = 0;
	while(k!=0){
		n ++;
		printf("%d", n);
		k --;
	}
	printf("\n");
	return 0;
}
