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
    int deadline; cin >> deadline;
    int idx = 0;
    vector<vector<pii>> g;
    vector<vector<int>> dp(0, vector<int>(deadline + 1, 0));
    function<void(int)> dfs1 = [&](int fa)
    {
        while(g.size() <= fa) g.push_back({});
        int val1, val2; cin >> val1 >> val2;
        if(val2 == 0)
        {
            g[fa].push_back({++idx, val1});
            int tmp = idx;
            dfs1(tmp);
            dfs1(tmp);
        }
        else
        {
            g[fa].push_back({++idx, val1});
            while(dp.size() <= idx) dp.push_back(vector<int>(deadline + 1, 0));
            rep(i, 1, deadline) dp[idx][i] = min(i / 5, val2);
        }
    };
    dfs1(idx);


    function<void(int)> dfs2 = [&](int fa)
    {
        while(dp.size() <= fa) dp.push_back(vector<int>(deadline + 1, 0));
        if(g[fa].empty()) return;
        int son1 = g[fa].front().first, son2 = g[fa].back().first;
        dfs2(son1);
        dfs2(son2);
        while(dp.size() <= son1 or dp.size() <= son2) dp.push_back(vector<int>(deadline + 1, 0));
        int val1 = g[fa].front().second, val2 = g[fa].back().second;
        rep(i, 1, deadline)
        {
            rep(j, 0, i)
            {
                int tmp = 0;
                if(j >= val1 * 2) tmp = dp[son1][j - val1 * 2];
                if(i - j >= val2 * 2) tmp += dp[son2][i - j - val2 * 2];
                dp[fa][i] = max(dp[fa][i], tmp);
            }
        }
        // cerr << fa << " " << dp[fa][deadline] << endl;
    };
    dfs2(1);
    cout << dp[1][deadline - g[0][0].second * 2 - 1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}