/*本题要求统计给定整数M和N区间内素数的个数
并对它们求和。
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
		/*a赋值给d若break，加d=0，循环a的值不能变，要递增 
		若没有break，sum要加上d=a*/
		 d = a;
		while(chu<a){
			int yu = a % chu;
			if(yu==0){
				//如果break就加0 
				d = 0;
				i = 0;
				break;
			}
			chu ++;
		}
		//算一个质数后初始化除数为2 
		chu = 2;
		count += i;
		/*break后加0，没有break的话while结束后要让i初始化 
		因为之前i变为0*/ 
		i = 1;
		sum += d;
		a ++;
	}
	printf("%d %d", count, sum);
	return 0;
}
