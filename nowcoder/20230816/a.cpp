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
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[N], s[N][31];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        rep(j, 0, 30)
        {
            s[i][j] = s[i - 1][j];
            if(a[i] >> j & 1) s[i][j] ++;
        }
    }
    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        int ans = 0;
        rep(i, 0, 30)
        {
            int c = s[r][i] - s[l - 1][i];
            if(c < (r - l + 1 - c)) ans += (1 << i);
        }
        cout << ans << endl;
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