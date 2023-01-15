#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int mi = 1e7;
    for(int i=0;i<n;i++) mi = min(mi, a[i]);
    int ans = 0;
    a[n] = mi;
    int tmp = 0;
    for(int i=0;i<=n;i++)
    {
        if(a[i]==mi)
        {
            if(k==1) continue;
            else ans += (i - tmp - 1) / (k - 1);
            if((i-tmp-1)%(k-1)&&i-tmp-1>0) ans ++;
            int j = i;
            while(a[j+1]==mi) j ++;
            tmp = j;
            i = j;
        }
    }
    if(ans==0)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[i+1])
            {
                cout << -1;
                return 0;
            }
        }
        cout << 0;
        return 0;
    }
    cout << ans;
    return 0;
}