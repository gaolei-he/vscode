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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int mx[N], mn[N];
int sxf[N], sxs[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) mx[i] = mn[i] = sxf[i] = sxs[i] = 0;
    mx[1] = sxf[1] = 1;
    int now = 1;
    while(n--)
    {
        char op; cin >> op;
        if(op == '+')
        {
            now ++;
            int v, x; cin >> v >> x;
            sxf[now] = max(0ll, x+sxf[v]);
            sxs[now] = min(0ll, sxs[v]+x);
            mx[now] = max(mx[v], sxf[now]);
            mn[now] = min(mn[v], sxs[now]);
        }
        else if(op == '?')
        {
            int u, v, k; cin >> u >> v >> k;
            // cerr << mx[v] << ' ' << mn[v] << endl;
            if(k >= mn[v] and k <= mx[v]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}