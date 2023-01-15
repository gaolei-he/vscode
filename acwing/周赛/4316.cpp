#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200010;

int main()
{
    LL ans[N], cnt = 0, t, n;
    cin >> n >> t;
    for(int i=1;i<=n;i++) scanf("%lld", &ans[i]);
    for(int i=1;i<=n;i++)
    {
        LL sum = 0;
        for(int j=i;j<=n;j++)
        {
            sum += ans[j];
            if(sum<t) cnt ++;
        }
    }
    cout << cnt;
    return 0;
}