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
    vector<vector<int>> dp(n + 1, vector<int>(2, linf));
    vector<pii> vec(n + 1);
    rep(i, 1, n) cin >> vec[i].first >> vec[i].second;
    dp[1][1] = vec[1].second - 1;
    dp[1][0] = vec[1].first + vec[1].second - 1;
    rep(i, 2, n)
    {
        int val = linf;
        val = vec[i].second - vec[i].first + abs(vec[i-1].first - vec[i].first) + dp[i-1][0];
        val = min(val, vec[i].second - vec[i].first + abs(vec[i-1].second - vec[i].first) + dp[i-1][1]);
        dp[i][1] = val;
        val = vec[i].second - vec[i].first + abs(vec[i-1].first - vec[i].second) + dp[i-1][0];
        val = min(val, vec[i].second - vec[i].first + abs(vec[i-1].second - vec[i].second) + dp[i-1][1]);
        dp[i][0] = val;
        // cerr << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << min(dp[n][0] + (n - vec[n].first), dp[n][1] + (n - vec[n].second)) + n - 1 << endl;
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