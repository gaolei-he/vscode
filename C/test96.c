#include <stdio.h>
int main()
{
	double a[60];
	a[1]=1.0, a[2]=2.0;
	int i;
	for(i=3;i<55;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	while(scanf("%d", &n)!=EOF){
		printf("%.0f\n", a[n]);
	}
	
	return 0;
 } 
