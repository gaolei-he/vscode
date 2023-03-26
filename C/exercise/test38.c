#include <stdio.h>
int main()
{
	int i=2,j=2,k;
	int sum1=1,sum2=1;
	int c ;
	
	for(c=0;c<100;c++){
		sum1*=j;
		sum2=sum2*i;
		i ++;
		printf("%d\n%d\n", sum1, sum2);
	}
	return 0;
 } 
