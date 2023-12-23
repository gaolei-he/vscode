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
    vector<pii> vec(n);
    for (auto &[x, y] : vec) cin >> x >> y;
    vector<pii> vec1, vec2;
    int val1 = 0, val2 = 0;
    for (auto [x, y] : vec)
    {
        if (x >= 0 and y >= 0) val1 += x, val2 += y;
        else if (x > 0 and y < 0) vec1.emplace_back(x, y);
        else if (x < 0 and y > 0) vec2.emplace_back(x, y);
    }
    int C = 400000;
    vector<vector<pii>> dp(2, vector<pii>(4e5+10));
    dp[0].assign(C + 1, make_pair(0, val1));
    dp[1].assign(C + 1, {0, val2});

    for (auto [x, y] : vec1)
        dec (i, C, abs(y))
            dp[0][i] = max(dp[0][i], {dp[0][i-abs(y)].first+x+y, dp[0][i-abs(y)].second+x});
    for (auto [x, y] : vec2)
        dec (i, C, abs(x))
            dp[1][i] = max(dp[1][i], {dp[1][i-abs(x)].first+y+x, dp[1][i-abs(x)].second+y});

    int ans = 0;
    rep(i, 0, C)
    {
        int val = dp[0][i].second;
        if (dp[1][val].second >= i) ans = max(ans, dp[0][i].first + dp[1][val].first);// + dp[1][val].second);
    }
    // rep(i, 1, 20) cerr << dp[0][i] << ' ' << dp[1][i] << endl;
    cout << ans + val1 + val2 << endl;

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