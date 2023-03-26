#include <stdio.h>
int main()
{
	int m, n;
	int j, k;
	while(scanf("%d %d", &n, &m)!=EOF){
		int sum = 0, count = 0; 
		int i = 2;
		int ret = 0;
		for(j=0;j<n;j++){
			
			sum += i;
			i += 2;
			count ++;
			if((count==m||j==n-1)&&ret==0){
				printf("%d", sum/count);
				sum = 0;
				count = 0;
				ret = 1;
			}else if((count==m||j==n-1)&&ret==1){
				printf(" %d", sum/count);
				sum = 0;
				count = 0;
			}else{
			}
			}
			printf("\n");
		}
		
		
	
	return 0;
}
