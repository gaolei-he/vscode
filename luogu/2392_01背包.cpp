#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int num[5];
    for(int i=1;i<=4;i++) scanf("%d", &num[i]);
    int sum1 = 0, sum = 0, n = 0;
    while((n++)!=4)
    {
        sum = 0;
        int a[num[n]+1];
        int Max = 0;
        for(int i=1;i<=num[n];i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int ans[sum+1];
        memset(ans, 0, sizeof(ans));
        for(int i=1;i<=num[n];i++)
            for(int j=sum/2;j>0;j--)
            ans[j] = max(ans[j], ans[(j-a[i])>0?(j-a[i]):0]+(j-a[i]>=0?a[i]:0));
        sum1 += sum - ans[sum/2];
    }
    cout << sum1;

    return 0;
}