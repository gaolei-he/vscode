#include <stdio.h>
int fact(int i);
int main()
{
	int i = 1, sum = 0;
	while(i!=10){
		int x;
		x = fact(i);
		sum += x;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}
int fact(int i)
{
	int sum = 1, j;
	for(j=1;j<=i;j++){
		sum *= j;
	}
	return sum;
}
