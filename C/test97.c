#include <stdio.h>
int main()
{
	long double a[50];
	a[1]=3.0, a[2]=8.0;
	int i;
	for(i=3;i<40;i++){
		a[i]=2*(a[i-1]+a[i-2]);
	}
	int n;
	while(scanf("%d", &n)!=EOF){
		
			printf("%.0Lf\n", a[n]);			
		
			}
	
	return 0;
}
