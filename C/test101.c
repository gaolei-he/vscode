#include<stdio.h>
#include<math.h>
int main()
{
	__int64 f[21],sum[21]={0};
	f[1]=0,f[2]=1,sum[1]=1,sum[2]=2;
	int n;
	for(n=3;n<21;n++)
	{
		f[n]=(n-1)*(f[n-1]+f[n-2]);
		sum[n]=n*sum[n-1];
	}
	int x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%.2lf",f[x]*100.0/sum[x]);
		puts("%");
	}
	return 1;
}
