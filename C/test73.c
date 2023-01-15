#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		if(n==0) break;
		int i;
		int a[101];
		int cnt, sum=0;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
			cnt=a[i]/100;
			sum+=cnt;
			cnt=(a[i]%100)/50;
			sum+=cnt;
			cnt=a[i]%50/10;
			sum+=cnt;
			cnt=a[i]%10/5;
			sum+=cnt;
			cnt=a[i]%5/2;
			sum+=cnt;
			cnt=a[i]%2/1;
			sum+=cnt;
		}
		printf("%d\n", sum);
	}
	return 0;
}
