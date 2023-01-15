#include <stdio.h>
//24小时转化 
int main()
{
	int hr = 0, min = 0;
	scanf("%d:%d", &hr, &min);
	if (hr > 12)
		printf("%d:%d", hr - 12, min);
	else
		printf("%d:%d", hr, min);
	return 0;
}
