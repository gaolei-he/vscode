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
const int N = 10 + 1e2, mod = 1e9 + 7;
char a[N], b[N];
int dp[N][2];
void solve()
{
    cin >> a + 1 >> b + 1;
    int n = strlen(a+1);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;
    rep(i, 1, n)
    {
        if(a[i] != b[i])
        {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }
        else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + 1;
        }
    }
    if(a[n] == b[n]) cout << dp[n][0];
    else cout << dp[n-1][1] << endl;
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