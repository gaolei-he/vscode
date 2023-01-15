#include <stdio.h>
int main()
{
	int n, a, b;
	double num[6000];
	num[0]=1.0, num[1]=2.0;
	int i;
	for(i=2;i<5999;i++){
		num[i]=num[i-1]+num[i-2];
	}
	while(scanf("%d", &n)!=EOF){
		int i, j;
		for(i=0;i<n;i++){
			scanf("%d %d", &a, &b);
			int c = b - a - 1;
			printf("%.0f\n", num[c]);
		}
	}
	
	return 0;
}
