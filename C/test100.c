#include <stdio.h>
long long fact(int n);
int main()
{
	long long a[22];
	a[1]=0, a[2]=1, a[3]=2;
	int i;
	for(i=4;i<=20;i++){
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	} 
	long long sum;
	int n, j;
	scanf("%d", &n);
	while(n){
		for(i=0;i<n;i++){
		scanf("%d", &j);
	sum = fact(j);
	double ans = 100.0*a[j]/sum;
	printf("%.2f", ans);
	puts("%");
	printf("%");
	n--;
	}
	}
	return 0;
}
long long fact(int n){
	int i;
	long long sum = 1;
	for(i=1;i<=n;i++){
		sum *= i;
	}
	return sum;
}
