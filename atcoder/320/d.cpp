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
using ar3 = array<int, 3>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<ar3>> g(n + 1);
    rep(i, 1, m)
    {
        int v1, v2, x, y;
        cin >> v1 >> v2 >> x >> y;
        g[v1].push_back({v2, x, y});
        g[v2].push_back({v1, -x, -y});
    }
    vector<bool> vis(n + 1);
    vector<pii> ans(n + 1);
    function<void(int, int, int)> dfs = [&](int u, int xx, int yy)
    {
        vis[u] = true;
        ans[u] = {xx, yy};
        for(auto [v, x, y] : g[u])
        {
            if(vis[v]) continue;
            dfs(v, xx + x, yy + y);
        }
    };
    dfs(1, 0, 0);
    rep(i, 1, n)
    {
        if(vis[i]) cout << ans[i].first << " " << ans[i].second << endl;
        else cout << "undecidable\n";
    }
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