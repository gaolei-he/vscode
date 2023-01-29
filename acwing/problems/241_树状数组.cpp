#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
const int N = 2e5+10;
int tr[N], a[N];
int gr[N], le[N];
int n;
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
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%lld", &a[i]);

    for(int i=1;i<=n;i++)
    {
        int v = a[i];
        gr[i] = sum(n) - sum(v);
        le[i] = sum(v-1);
        add(v, 1);
    }
    int res1 = 0, res2 = 0;
    memset(tr, 0, sizeof(tr));
    for(int i=n;i;i--)
    {
        int v = a[i];
        res1 += gr[i] * (sum(n) - sum(v));
        res2 += le[i] * (sum(v-1));
        add(v, 1);
    }
    cout << res1 << ' ' << res2 << endl;
    return 0;
}