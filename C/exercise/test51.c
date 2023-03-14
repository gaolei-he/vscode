#include <stdio.h>
int main()
{
	int n, i;
	float a[100];
	int num1 = 0, num2 = 0, num3 = 0;
	while(scanf("%d", &n)!=EOF){
		if(n==0){
			continue;
		}else{
			for(i=0;i<n;i++){
				scanf("%f", &a[i]);
				if(a[i]>0) num1 ++;
				else if(a[i]==0) num2 ++;
				else num3 ++;
			}
		}
		printf("%d %d %d", num3, num2, num1);
	}
	return 0;
}
