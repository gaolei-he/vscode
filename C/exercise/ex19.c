#include <stdio.h>
int main()
{
	int a = 2, b = 1;
	int n;
	scanf("%d", &n);
	
	double sum = 0;
	//��Ϊ������ 
	int i = 0;
	int tem = 0;
	while(i<n){
		//a*1.0��ɸ����� 
		sum += a*1.0/b;
		tem = a;
		a = a + b;
		b = tem;
		i ++;
	}
	//���������Ҫ%f 
	printf("%f", sum);
	return 0;
}
