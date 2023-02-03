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
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int ans[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gz(n+1), gf(n+1);
    rep(i, 1, m)
    {
        int x, y; cin >> x >> y;
        gz[x].push_back(y);
        gf[y].push_back(x);
    }
    bool vis[n+1];
    function<void(vector<vector<int>>&, int)> dfs = [&](vector<vector<int>>& g, int st) {
        vis[st] = true;
        for(auto i:g[st]) if(!vis[i]) dfs(g, i);
    };
    memset(ans, -1, sizeof(ans));
    rep(i, 1, n)
    {
        memset(vis, 0, sizeof(vis));
        dfs(gz, i);
        int v1 = 0, v2 = 0;
        rep(i, 1, n) if(vis[i]) v1 ++;
        memset(vis, 0, sizeof(vis));
        dfs(gf, i);
        rep(i, 1, n) if(vis[i]) v2 ++;
        if(v1 + v2 == n + 1) ans[v2] = i;
    }
    rep(i, 1, n) cout << ans[i] << (i == n ? "\n" : " ");
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