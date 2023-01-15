#include <stdio.h>
int a[50][5];
double b[5];
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		int i, j, k;
		int sum = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d", &a[i][j]);
			}
		}
		int cnt = 0, cnt1 = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				sum += a[i][j];
			}
			if(i==0){
				printf("%.2f", sum*1.0/m);	
			}else{			
				printf(" %.2f", sum*1.0/m);
			}
			sum = 0;
		}
		printf("\n");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				sum += a[j][i];
				}
				if(i==0){
					printf("%.2f", sum*1.0/n);
				}else{
				printf(" %.2f", sum*1.0/n);
				}
				b[i]=sum*1.0/n;
				sum = 0;
		}
		printf("\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]>=b[j]) cnt++;
			}
			if(cnt==m){
				cnt1++;
				
			}
			cnt = 0;
			}
			printf("%d\n\n", cnt1);
		
	}
	return 0;
}
