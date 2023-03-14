#include <stdio.h>
int a[1000][1000];
int b[1000][1000];
int main()
{
	int m, n;
	while(scanf("%d %d", &m, &n)!=EOF){
		
		int i, j;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d", &a[i][j]);
				if(a[i][j]>=0){
					b[i][j]=a[i][j];
				}else{
					b[i][j]=-a[i][j];
				}
			}
		}
		int c=0, d=0;
		int max;
		max=b[0][0];
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(max<b[i][j]){
					max=b[i][j];
					c=i;
					d=j;
				}
			}
		}
		printf("%d %d %d\n", a[c][d],c+1,d+1);
	}
	return 0;
}
