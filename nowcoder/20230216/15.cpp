#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
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
#define lowbit(x) ((x)&(-(x)))
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 3e5, mod = 1e9 + 7;
int tr[N], child[N];
int n, r;
bool st[N];
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
void solve()
{
    cin >> n >> r;
    vector<vector<int>> g(n+1);
    rep(i, 2, n)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    int sm = 1;
    auto fact = [](int x) {
        int res = 1;
        rep(i, 1, x) res = res * i % mod;
        return res;
    };
    rep(i, 1, n)
    {
        if(i == r) sm = sm * fact(SZ(g[r])) % mod;
        else if(g[i].size() == 1) continue;
        else sm = sm * fact(SZ(g[i])-1) % mod;
    }
    function<int(int)> dfs = [&](int p) {
        st[p] = true;
        ans = (ans + sum(n) - sum(p)) % mod;
        add(p, 1);
        int t = 0;
        for(auto v:g[p]) if(!st[v]) t += dfs(v);
        add(p, -1);
        child[p] = t;
        st[p] = false;
        return t + 1;
    };
    function<void(int)> dfs1 = [&](int p) {
        st[p] = true;
        add(p, 1);
        // cerr << sum(n) << endl;
        ans = (ans + (n - sum(n) - child[p]) % mod * 250000002 % mod) % mod;
        // cerr << ans << endl;
        for(auto v:g[p]) if(!st[v]) dfs1(v);
        add(p, -1);
    };
    dfs(r);
    dfs1(r);
    cout << ans * sm % mod << endl;

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