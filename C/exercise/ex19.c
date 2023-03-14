#include <stdio.h>
int main()
{
	int a = 2, b = 1;
	int n;
	scanf("%d", &n);
	
	double sum = 0;
	//和为浮点数 
	int i = 0;
	int tem = 0;
	while(i<n){
		//a*1.0变成浮点数 
		sum += a*1.0/b;
		tem = a;
		a = a + b;
		b = tem;
		i ++;
	}
	//输出浮点数要%f 
	printf("%f", sum);
	return 0;
}
