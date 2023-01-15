#include <stdio.h>
int main()
{
	int a[100];
	int n, m;
	int i;
	a[0]=1, a[1]=2;
	for(i=2;i<50;i++){
		a[i]=a[i-1]+a[i-2];
	}
	while(scanf("%d", &n)!=EOF){
		int i;
		for(i=0;i<n;i++){
			scanf("%d", &m);
			printf("%d\n", a[m-2]);
		}
	}
	
	return 0;
}
