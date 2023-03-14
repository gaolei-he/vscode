#include <stdio.h>
 
int main()
{
	char ch = '0';
	int result, i, flag = 0;
	scanf("%d", &result);
	while( ch != '=' )
	{
		scanf("%c", &ch);
		if(ch == '=')
			break;
		scanf("%d", &i);
		if( ch == '+' )
			result += i;
		else if( ch == '-' )
			result -= i;
		else if( ch == '*' )
			result *= i;
		else if( ch == '/' )
		{
			if( i != 0 )
				result /= i;
			else
				flag = 1;
		}
		else
			flag = 1;
	}
	if(flag)
		printf("ERROR\n");
	else
		printf("%d", result);
		
	return 0;
}
