/*************************************************************************
    > File Name: tmp1.c
    > Author: maverick
    > Mail: ahegaolei@163.com 
    > Created Time: Sat 09 Jul 2022 08:14:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
	char *str1 = "good";
	write(2, str1, strlen(str1));
	return 0;
}
