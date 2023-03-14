#include <stdio.h>
int main()
{
	int n;	
	while(scanf("%d", &n)!=EOF){
	int i;
	int a[n];
	int sum = 1;
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
		if(a[i]%2==0){
			a[i]=1;
		}
		sum *= a[i];
	}
	printf("%d\n", sum);
	}
	return 0;

}
