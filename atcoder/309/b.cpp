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
const int N = 10 + 1e2, mod = 1e9 + 7;
char str[N][N];
char ans[N][N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> str[i] + 1;
    memcpy(ans, str, sizeof str);
    ans[1][1] = ans[2][1];
    rep(i, 2, n) ans[1][i] = str[1][i-1];
    ans[2][n] = str[1][n];
    rep(i, 2, n) ans[i][n] = str[i-1][n];
    ans[n][n-1] = str[n][n];
    rep(i, 1, n-1) ans[n][i] = str[n][i+1];
    ans[n-1][1] = str[n][1];
    rep(i, 2, n-1) ans[i][1] = str[i+1][1];
    rep(i, 1, n) cout << ans[i] + 1 << endl;
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