#include <stdio.h>
int main()
{
	int time = 0,pass = 0;
	scanf("%d %d", &time, &pass);
	
	int hr = time / 100, mins = time % 100;
	int total_min = hr * 60 + mins;
	
	int total_min1 = total_min + pass;
	int output1 = total_min1 / 60, output2 = total_min1 % 60;
	printf("%d\n", output1 * 100 + output2);
	return 0;
}
