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
    int r; cin >> r;
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(m+1, vector<bool>(n+r+m+1, 1)));
    rep(i, 1, r)
    {
        int x, y, z; cin >> x >> y >> z;
        if(x > n+r+m) continue;
        if(y == 1)
            rep(j, 0, m)
                dp[z][j][x] = 0;
        else if(y == 2)
            rep(j, 0, n)
                dp[j][z][x] = 0;
    }
    rep(i, 0, n) rep(j, 0, m) rep(k, 0, n+r+m)
    {
        if(i == 0 and j == 0 and k == 0) continue;
        if(!dp[i][j][k]) continue;
        dp[i][j][k] = 0;
        if(i and k) dp[i][j][k] = dp[i][j][k] | dp[i-1][j][k-1];
        if(j and k) dp[i][j][k] = dp[i][j][k] | dp[i][j-1][k-1];
        if(k) dp[i][j][k] = dp[i][j][k] | dp[i][j][k-1];
    }
    rep(i, n + m, n+m+r)
    {
        if(dp[n][m][i])
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;

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