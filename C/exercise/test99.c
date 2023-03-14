#include<stdio.h>
int main()
{
    int i,n;
    long long a[100]={0,3,8};
    for(i=3;i<=40;i++)
    {
        a[i]=2*(a[i-1]+a[i-2]);
    }
    while(scanf("%d",&n)!=EOF)
    printf("%lld\n",a[n]);
    return 0;
}
