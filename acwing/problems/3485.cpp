#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N], s[N];
int son[N<<2][2], idx, cnt[N<<2];
void insert(int x)
{
    int p = 0;
    for (int i = 0; i < 32; i++)
    {
        int u = (x >> (31 - i)) & 1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++;
    }
}
void del(int x)
{
    int p = 0;
    for (int i = 0; i < 32; i++)
    {
        int u = (x >> (31 - i)) & 1;
        p = son[p][u];
        cnt[p] --;
    }
}
int query(int x)
{
    int p = 0;
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int u = (x >> (31 - i)) & 1;
        if(son[p][u?0:1] && cnt[son[p][u?0:1]]) res += (1 << (31-i)), p = son[p][u?0:1];
        else p = son[p][u];
    }
    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) s[i] = s[i-1] ^ a[i];
    int ans = 0;
    
    for(int i=0, j=0; i<=n;i++)
    {
        while(j <= n && j - i <= m)
            insert(s[j ++]);
        ans = max(ans, query(s[i]));
        del(s[i]);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}