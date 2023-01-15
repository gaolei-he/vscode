#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，"
	"如输入 5 7：");
	double foot = 5;
	int inch = 7;
	
	
	printf("身高是%f米。\n",
	((foot+inch/12.0)*0.3048));
	return 0;
}
