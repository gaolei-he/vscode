#include <stdio.h>
int main()
{
	long long a[10001];
	a[1]=2;
	int i;
	for(i=2;i<10001;i++){
		a[i]=a[i-1]+4*(i-1)+1;
	}
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &i);
		printf("%lld\n", a[i]);
	}
	
	
	return 0;
}
