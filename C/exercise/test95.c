#include <stdio.h>
int main()
{
	int n;
	double a[60];
	int i;
	a[0]=3.0, a[1]=6.0, a[2]=6.0;
	for(i=3;i<55;i++){
		a[i]=a[i-2]*2+a[i-1];
	}
	while(scanf("%d", &n)!=EOF){
		printf("%.0f\n", a[n-1]);
	}
	
	return 0;
}
