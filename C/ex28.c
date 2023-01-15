#include <stdio.h>
int main()
{
	int n, count;
	int i, j, k;
	scanf("%d", &n);
	if(n>=1&&n<=10){
		for(count=1;i<=n;count++){
			scanf("%d %d %d", &i, &j, &k);
			if(i+j>k){
				printf("Case #%d: true\n", count);
			}else{
				printf("Case #%d: false\n", count);
			}
		}
	}
}
