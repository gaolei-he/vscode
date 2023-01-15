#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j, k;
		
		
		for(i=0;i<n;i++){
			int num1, num2, sum1 = 0, sum2 = 0;
			scanf("%d %d", &num1, &num2);
			for(j=1;j<num1;j++){
				if(num1%j==0){
					sum1 += j;
				}
				
			}
			for(j=1;j<num2;j++){
				if(num2%j==0){
					sum2 += j;
				}
				
			}
			if((sum2==num1)&&(sum1==num2)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
