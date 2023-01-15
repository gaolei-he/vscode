#include <stdio.h>
int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	
	int sum = 0, i = 1;
	int tem = a;
	while(n>1){
	
	while(i<n){
		tem = tem*10 + a;
		i ++;
	}
	sum += tem;
	tem = a;
	i = 1;
	n --;
	}
	sum += a;
	printf("%d", sum);
	return 0;
}
