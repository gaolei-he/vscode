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
const int N = 10 + 5e2, mod = 1e9 + 7;
int a[N];
bool dp[N][N][N];
int n, k;
void f()
{
    dp[0][0][0] = true;
    // rep(i, 0, n) dp[i][0][0] = dp[i][a[i]][a[i]] = dp[i][a[i]][0] = true;
    rep(i, 1, n)
        rep(j, 0, k)
            rep(l, 0, j)
            {
                if(dp[i-1][j][l]) dp[i][j][l] = true;
                else if(j >= a[i] && dp[i-1][j-a[i]][l]) dp[i][j][l] = true;
                else if(j >= a[i] && l >= a[i] && dp[i-1][j-a[i]][l-a[i]]) dp[i][j][l] = true;
            }
}
void solve()
{
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    f();
    vector<int> ans;
    rep(i, 0, k)
        if(dp[n][k][i]) ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x:ans) cout << x << ' ';
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