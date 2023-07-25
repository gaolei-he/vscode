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
    vector<vector<pii>> g(n + 1);
    map<string, int> mp;
    bool res = true;
    rep(i, 1, m)
    {
        int x, y, z; cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, -z);
        if(x > y) swap(x, y), z = -z;
        string s = to_string(x) + " " + to_string(y);
        if(mp.count(s) and mp[s] != z) res = false;
        mp[s] = z;
    }

    vector<bool> vis(n+1, false);
    map<int, int> mpl, mpr;

    function<void(int)> dfs = [&](int ver) {
        vis[ver] = true;
        for(auto &[to, id] : g[ver])
        {
            string s = to_string(min(ver, to)) + " " + to_string(max(ver, to));
            if(mp[s] >= linf) continue;
            mp[s] = linf;
            if(mpr.count(to) and mpr[to] != mpr[ver] + id)
                res = false;
            if(!mpr.count(to)) mpr[to] = mpr[ver] + id;
            dfs(to);
        }
    };
    rep(i, 1, n)
    {
        if(vis[i]) continue;
        mpl[0] = i;
        mpr[i] = 0;
        mpl.clear();
        mpr.clear();
        dfs(i);
    }
    // cerr << mpr[2] << endl;
    if(res) cout << "YES\n";
    else cout << "NO\n";
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