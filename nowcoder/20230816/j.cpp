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
const int N = 51, mod = 1e9 + 7;
int a[N], b[N], martix[N][N];
int s[N][N];
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    rep(i, 1, n) rep(j, 1, m) martix[i][j] = a[i] * b[j];
    rep(i, 1, n)
        rep(j, 1, m)
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + martix[i][j];
    int ans = 0, x; cin >> x;
    rep(i, 1, n)
        rep(j, 1, m)
            rep(k, i, n)
                rep(l, j, m)
                    if(s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1] <= x)
                        ans = max(ans, (k - i + 1) * (l - j + 1));
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