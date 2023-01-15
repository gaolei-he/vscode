//HDU4000 count(x < y && x < z) - count(x < y < z)
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
const int N = 1e5+10;
int tr[N], n, a[N];
const int mod = 100000007;
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
signed main()
{
    int t, Case = 0;
    cin >> t;
    while (t--)
    {
        Case ++;
        scanf("%lld", &n);
        memset(tr, 0, sizeof(tr));
        for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
        int res = 0;
        int le[N], gr[N];
        for(int i=1;i<=n;i++)
        {
            int v = a[i];
            le[i] = sum(v-1);
            add(v, 1);
        }
        memset(tr, 0, sizeof(tr));
        for(int i=n;i;i--)
        {
            int v = a[i];
            gr[i] = sum(n) - sum(v-1);
            res += le[i] * gr[i];
            add(v, 1);
        }
        memset(tr, 0, sizeof(tr));
        int res1 = 0;
        for(int i=n;i;i--)
        {
            int v = a[i];
            int t = sum(n) - sum(v);
            res1 += t * (t - 1) / 2;
            add(v, 1);
        }
        printf("Case #%lld: %lld\n", Case, (res1 - res) % mod);
    }
    
}