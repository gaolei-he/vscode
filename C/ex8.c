#include <stdio.h>
int main()
{
	int day = 0;
	scanf("%d", &day);
	if (day%5>3)
		printf("Drying in day %d", day);
	else
		printf("Fishing in day %d", day);
	
	
	return 0;
}
