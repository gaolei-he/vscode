#include <stdio.h>
int main()
{
	int t, i, a[60];
	while(scanf("%d", &t)!=EOF){
	if(t==0) break;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=4;
	for(i=5;i<60;i++){
		a[i]=a[i-1]+a[i-3];
	}
	printf("%d\n", a[t]);
	}
	return 0;
}
