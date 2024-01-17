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
const int N = 10 + 1e5, mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int val = ceil(sqrt(n) + 5);
    vector<vector<int>> suf(n + 1, vector<int>(val));
    auto sm = suf;
    rep(i, 1, val - 2) suf[n][i] = a[n];
    dec(i, n-1, 1)
    {
        rep(j, 1, val - 2)
        {
            suf[i][j] = a[i];
            if(i + j <= n) suf[i][j] += suf[i + j][j];
        }
    }
    rep(i, 1, val - 2) sm[n][i] = a[n];
    dec(i, n - 1, 1)
    {
        rep(j, 1, val - 2)
        {
            sm[i][j] = a[i];
            if(i + j <= n) sm[i][j] += sm[i + j][j] + suf[i + j][j];
        }
        // cout << sm[i][1] << endl;
    }

    while(q --)
    {
        int s, d, k;
        cin >> s >> d >> k;
        if(k < ceil(sqrt(n) + 2))
        {
            int ans = 0;
            rep(i, 1, k)
            {
                ans += a[s + (i - 1) * d] * i;
            }
            cout << ans << ' ';
        }
        else
        {
            int ans = sm[s][d];
            if(s + d * k <= n) ans -= sm[s + d * k][d] + suf[s + d * k][d] * k;
            cout << ans << ' ';
        }
    }
    cout << endl;
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