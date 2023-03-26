#include <stdio.h>
int main()
{
	int speed = 0;
	const int STANDARD = 60;
	scanf("%d", &speed);
	if (speed <= STANDARD)
		printf("Speed: %d - OK", speed);
	else
		printf("Speed: %d - Speeding", speed);
	return 0;
}
