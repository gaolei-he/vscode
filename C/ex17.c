/*����Ҫ��ͳ�Ƹ�������M��N�����������ĸ���
����������͡�
*/ 
#include <stdio.h>
int main()
{
	int a, b;
	scanf ("%d %d", &a, &b);
	
	if(a==1){
		a = 2;
	}
	int chu = 2, count = 0, sum = 0;
	int i = 1, d = 0;
	while(a<=b){
		/*a��ֵ��d��break����d=0��ѭ��a��ֵ���ܱ䣬Ҫ���� 
		��û��break��sumҪ����d=a*/
		 d = a;
		while(chu<a){
			int yu = a % chu;
			if(yu==0){
				//���break�ͼ�0 
				d = 0;
				i = 0;
				break;
			}
			chu ++;
		}
		//��һ���������ʼ������Ϊ2 
		chu = 2;
		count += i;
		/*break���0��û��break�Ļ�while������Ҫ��i��ʼ�� 
		��Ϊ֮ǰi��Ϊ0*/ 
		i = 1;
		sum += d;
		a ++;
	}
	printf("%d %d", count, sum);
	return 0;
}
