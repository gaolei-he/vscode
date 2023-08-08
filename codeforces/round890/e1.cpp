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
    vector<vector<int>> g(n);
    vector<int> sz(n, 0);
    rep(i, 1, n - 1)
    {
        int fa; cin >> fa;
        fa --;
        g[fa].push_back(i);
    }
    function<int(int)> dfs1 = [&](int ver) {
        if(g[ver].empty()) return sz[ver] = 1;
        for(auto x : g[ver]) sz[ver] += dfs1(x);
        return sz[ver] += 1;
    };
    dfs1(0);
    int ans = 0;
    function<void(int)> dfs2 = [&](int ver) {
        if(g[ver].empty()) return;
        for(auto x : g[ver]) dfs2(x);
        vector<int> vec;
        int sm = 0;
        for(auto x : g[ver]) vec.push_back(sz[x]), sm += sz[x];
        int val = sm / 2;
        vector<int> dp(val + 1, 0);
        rep(i, 1, SZ(vec))
        {
            dec(j, val, vec[i-1])
                dp[j] = max(dp[j], dp[j - vec[i-1]] + vec[i-1]);
        }
        ans += dp[val] * (sm - dp[val]);
    };
    dfs2(0);
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