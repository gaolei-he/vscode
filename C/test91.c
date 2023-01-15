#include <stdio.h>
int main()
{
	int m, n;
	while(scanf("%d", &n)!=EOF){
		int i, j, k;
		for(i=0;i<n;i++){
			int sum = 3;
			scanf("%d", &m);
			for(j=0;j<m;j++){
				sum = (sum-1)*2;
			}
			printf("%d\n", sum);
		}
	}
	
	return 0;
}
