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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 5e2, mod = 1e9 + 7;
int n, m;
int b[N], x[N];
int dp[100010];
void solve()
{
    cin >> n >> m;
    rep(i, 1, m) cin >> b[i] >> x[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[n] = 0;
    dec(i, n, 1)
        rep(j, 1, m)
            if(x[j] < i) dp[i-i%x[j]] = min(dp[i-i%x[j]], dp[i]+b[j]);
    rep(i, 1, n)
        if(dp[0] != dp[i])
        {
            cout << dp[i] << endl;
            return;
        }
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