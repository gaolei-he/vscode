#include <stdio.h>

 
int a[1002];
 
int main()
{
	int t, i, max = 0;
	int count[10];
	scanf("%d", &t);
	for ( i=0; i<10; i++ )
	{
		count[i] = 0;
	}
	for ( i=0; i<t; i++ )
	{
		scanf("%d", &a[i]);
	}
	for ( i=0; i<t; i++ )
	{
		while (a[i])
		{
			count[a[i]%10]++;
			a[i] /= 10;
		}
	}
	for ( i=0; i<10; i++ )
	{
 		if ( max < count[i] )
		{
			max = count[i];
		}
	}
	printf("%d:", max);
	for ( i=0; i<10; i++ )
	{
		if ( count[i] == max )
		{
			printf(" %d", i);
		}
	}
	printf("\n");
	
	return 0;
}
