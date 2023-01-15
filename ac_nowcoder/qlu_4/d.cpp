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
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar3 = array<int, 3>;
using ar6 = array<int, 6>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int liq[N];
void solve()
{
    int n, m, p, c, a, b;
    cin >> n >> m >> p >> c >> a >> b;
    ar3 mp[n+10][m+10];
    rep(i, 0, n+1)
        rep(j, 0, m+1)
            mp[i][j][0] = mp[i][j][1] = mp[i][j][2] = 0;
    rep(i, 1, c)
    {
        cin >> liq[i];
        liq[i] = liq[i] * a + b;
    }
    ar6 op[p+10];
    rep(i, 1, p)
        rep(j, 0, 4)
        {
            cin >> op[i][j];
            op[i][5] = i;
        }
    sort(op + 1, op + p + 1, [&](ar6 a, ar6 b) {
        if(liq[a[4]] == liq[b[4]]) return a[5] < b[5];
        return liq[a[4]] > liq[b[4]];
    });
    // rep(i, 1, 5) cout << op[i][4] << ' ';
    // cout << "#\n";
    // reverse(op + 1, op + p + 1);
    rep(t, 1, p)
    {
        int x1 = op[t][0], y1 = op[t][1], x2 = op[t][2], y2 = op[t][3];
        if(liq[op[t][4]] < 0) break;
        rep(i, x1, x2)
        {
            if(mp[i][y1][1] >= y2) i = mp[i][y1][0];
            rep(j, y1, y2)
            {
                if(mp[i][j][0])j = mp[i][j][1];
                else mp[i][j][0] = x2, mp[i][j][1] = y2, mp[i][j][2] = op[t][4];
            }
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, m) cout << mp[i][j][2] << ' ';
        cout << endl;
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}