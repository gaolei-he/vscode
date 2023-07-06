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
const int N = 10 + 1500, mod = 1e9 + 7;
int dp[N][N];
bool a[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
        rep(j, 1, k)
    {
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
const int N = 1500 + 1, P = 1e9 + 7;
int a[N], f[N][N] = {{1}};
int tmp()
{
    int n, m = 0, k, ans = 0;
    std::cin >> n >> k;
    for (int i = 0, x; i < n; i++)
        if (std::cin >> x, x)
            a[++m] = i;
    for (int i = 0; i < n; i++)
        for (int j = m; j; j--)
            for (int t = abs(i - a[j]), x = t; x <= k; x++)
                (f[j][x] += f[j - 1][x - t]) %= P;
    while (k >= 0)
        (ans += f[m][k]) %= P, k -= 2;
    printf("%d", ans);
}