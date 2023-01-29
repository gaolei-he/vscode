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
const int N = 10 + 1e2, mod = 1e9 + 7;
int a[N];
int f[N][4];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    memset(f, 0x3f, sizeof(f));
    rep(i, 0, 2) f[0][i] = 0;
    rep(i, 1, n)
    {
        if(a[i] == 0) rep(j, 0, 2) f[i][0] = min(f[i][0], f[i-1][j] + 1);
        else if(a[i] == 1)
        {
            f[i][1] = min(f[i-1][2], f[i-1][0]);
            f[i][0] = min({f[i-1][0], f[i-1][1], f[i-1][2]}) + 1;
        }
        else if(a[i] == 2)
        {
            f[i][2] = min(f[i-1][1], f[i-1][0]);
            f[i][0] = min({f[i-1][0], f[i-1][1], f[i-1][2]}) + 1;
        }
        else
        {
            f[i][0] = min({f[i-1][0], f[i-1][1], f[i-1][2]}) + 1;
            f[i][2] = min(f[i-1][1], f[i-1][0]);
            f[i][1] = min(f[i-1][2], f[i-1][0]);
        }
    }
    int ans = mod;
    rep(i, 0, 2) ans = min(ans, f[n][i]);
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