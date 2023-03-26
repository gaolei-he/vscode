#include <stdio.h>
int main()
{
	int m, n;
	while(scanf("%d %d", &n, &m)!=EOF){
		getchar();
		int i, j;
		char k;
		int sum1=0, sum2=0;
		
		for(i=0;i<n;i++){
			if(m==0) break;
			
			for(j=0;j<m;j++){
				scanf("%c", &k);
				if(k=='#'){
					sum1++;
				}else if(k=='.'){
					sum2++;
				}
			}
			getchar();
		}
		int ans = sum1*1400+sum2*1800;
		printf("%d\n", ans);
	}
	return 0;
}
