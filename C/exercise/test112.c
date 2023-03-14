#include <stdio.h>
void myprint_n(int n);
int main()
{
	int n;
	scanf("%d", &n);
	myprint_n(n);
	return 0;
}

void myprint_n(int n)
{
	while(n--){
		printf("$");
	}
	printf("\n");
	
}
