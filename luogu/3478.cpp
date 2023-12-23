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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n + 1);
    vector<int> son(n + 1);
    function<int(int)> dfs = [&](int ver)
    {
        son[ver] = 1;
        for(auto x : g[ver])
            if(!son[x]) son[ver] += dfs(x);
        return son[ver];
    };
    dfs(1);
    vector<bool> vis(n + 1, false);
    function<int(int)> count_ans = [&](int ver)
    {
        vis[ver] = true;
        int res = 0;
        for(auto x : g[ver])
            if(!vis[x])
                res += count_ans(x);
        return res + son[ver] - 1;
    };
    dp[1] = count_ans(1);
    vis.assign(n + 1, false);
    // for(auto x : vis) cerr << x << ' ';
    int ans = dp[1], res = 1;
    function<void(int)> calc = [&](int ver)
    {
        vis[ver] = true;
        for(auto x : g[ver])
        {
            if(!vis[x])
            {
                dp[x] = dp[ver] - son[x] + (n - son[x]);
                if(dp[x] > ans)
                {
                    ans = dp[x];
                    res = x;
                }
                // cerr << dp[x] << ' ';
                calc(x);
            }
        }
    };
    calc(1);
    // rep(i, 1, n) cerr << dp[i] << ' ';
    cout << res << endl;
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