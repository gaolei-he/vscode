#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j;
		int sum1 = 0, sum2 = 0;
		for(i=0;i<n;i++){
			scanf("%d", &j);
			sum1 += j;
		}
		for(i=0;i<n;i++){
			scanf("%d", &j);
			sum2 += j;
		}
		if(sum2<=sum1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
