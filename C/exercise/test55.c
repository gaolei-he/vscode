#include <stdio.h>
int main()
{
	int m, n;
	int i, j;
	double k;
	while(scanf("%d", &m)!=EOF){
	
		for(i=0;i<m;i++){
			double sum = 0;
			scanf("%d", &n);
			for(j=1;j<=n;j++){
				k = 1.0/j;
				if(j%2==0){
					k = -k;
				}
				sum += k;
			}
			printf("%.2f\n", sum);
		}
	}
	return 0;
}
