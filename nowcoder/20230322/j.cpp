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
const int N = 10 + 5e3, mod = 1e9 + 7;
int dp[10][N][3];
int n, m;
void solve()
{
    cin >> m >> n;
    // dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 1;
    // rep(i, 1, m)
    //     rep(j, 0, 2)
    //         dp[i][0][j] = 1;
    rep(j, 0, 2)
        dp[1][1][j] = 1;
    rep(i, 1, m)
    {
        rep(j, 1, n)
        {
            if(i == 1 && j == 1) continue;
            dp[i][j][0] = dp[i][j-1][1] + dp[i-1][j][1] + dp[i][j-1][2] + dp[i-1][j][2] - dp[i-1][j-1][1] - dp[i-1][j-1][2];
            dp[i][j][1] = dp[i][j-1][0] + dp[i-1][j][0] + dp[i][j-1][2] + dp[i-1][j][2] - dp[i-1][j-1][0] - dp[i-1][j-1][2];
            dp[i][j][2] = dp[i][j-1][1] + dp[i-1][j][1] + dp[i][j-1][0] + dp[i-1][j][0] - dp[i-1][j-1][1] - dp[i-1][j-1][0];
            rep(k, 0, 2) dp[i][j][k] %= mod;
            rep(k, 0, 2) cerr << dp[i][j][k] << ' ';
            cerr << "##";
        }
        cerr << endl;
    }
    cout << dp[m][n][0] + dp[m][n][1] + dp[m][n][2] << endl;
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