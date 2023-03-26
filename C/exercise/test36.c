#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int a[m][n];
	int i, j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
			
		}
		
	}
	int ret = 0;
	for(i=1;i<m-1;i++){
		for(j=1;j<n-1;j++){
			if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]){
				if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]){
					printf("%d", a[i][j]);
					printf(" %d %d\n", i+1,j+1);
					ret = 1;
				}
			}
			
		}
		
	}
	if(ret==0){
		printf("None %d %d", m, n);
	}
	return 0;
}
