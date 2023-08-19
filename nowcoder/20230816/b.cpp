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
#define ull unsigned long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 310, mod = 1e9 + 7;
int a[N][N * 2], dp[N][N * 2];
void solve()
{
    int n, k; cin >> n >> k;
    rep(i, 1, n)
        rep(j, (n - i + 1), i - 1 + n)
            {
                cin >> a[i][j];
                dp[i][j] = -linf;
            }
    dp[1][n] = a[1][n];
    rep(i, 1, n-1)
        rep(j, (n - i + 1), i - 1 + n)
        {
            // if(dp[i][j] == 9) cerr << i << ' ' << j << endl;
        //     dp[i-1][j] = max(dp[i-1][j], dp[i][j] + a[i-1][j]);
        //     dp[i-1][j-1] = max(dp[i-1][j-1], dp[i][j] + a[i-1][j-1]);
        //     dp[i-1][j+1] = max(dp[i-1][j+1], dp[i][j] + a[i-1][j+1]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
            dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a[i + 1][j - 1]);
        }
    // cerr << dp[2][n + 1] << endl;
    // exit(0);
    int ans = -linf;
    rep(i, n - k, n + k) ans = max(ans, dp[n][i]);
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