#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[n],count = 0;
	int i;
	int k;
	scanf("%d", &k);
	a[count++] = k;
	for(i=0;i<n-1;i++){
		scanf(" %d", &k);
		a[count++] = k;
	}
	int sum1 = 0, sum2 = 0;
	int num1 = 0, num2 = n-1;
	while(num2-num1!=-1){
	
		if(a[num1]>a[num2]){
			sum1 += a[num1];
			num1 ++;
		}else{
			sum1 += a[num2];
			num2 --;
		}
		if(a[num1]>a[num2]){
			sum2 += a[num1];
			num1 ++;
		}else{
			sum2 += a[num2];
			num2 --;
	}
	}
	if(sum1>sum2){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	//printf("%d", a[1]);
}
