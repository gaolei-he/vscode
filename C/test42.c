#include <stdio.h>
int main()
{
	int m, n;
	int sum1 = 0, sum2 = 0;
	int i;
	while(scanf("%d %d", &m, &n)!=EOF){
		int a[n-m+1];
		int t = m;
		for(i=0;i<n-m+1;i++){
			a[i]=t;
			t ++;
		}
		if(m%2==0){
			for(i=0;i<n-m+1;i++){
				sum1 += a[i++]*a[i++];
				printf("#%d#", a[--i]);
			}
			for(i=1;i<n-m+1;i++){
				sum2 += a[i++]*a[i++]*a[i++];
				printf("#%d#", a[--i]);
			}
		}
		if(m%2!=0){
			for(i=0;i<n-m+1;i++){
				sum2 += a[i++]*a[i++]*a[i++];
			}
			for(i=1;i<n-m+1;i++){
				sum1 += a[i++]*a[i++];
			}
		}
		printf("%d %d\n", sum1, sum2);
	}
}
