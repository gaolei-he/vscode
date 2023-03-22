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
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[6][6], b[6][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void f(int op, int& ans)
{
    int res = 0;
    memcpy(b, a, sizeof(a));
    rep(i, 0, 8)
    {
        if((op>>i) & 1)
        {
            res ++;
            int x = i % 3 + 1;
            int y = i / 3 + 1;
            if(op == 16) cerr << x << ' ' << y << endl;
            b[x][y] = ~b[x][y];
            rep(j, 0, 3)
                b[x+dx[j]][y+dy[j]] = ~b[x+dx[j]][y+dy[j]];
        }
    }
    rep(i, 1, 3)
        rep(j, 1, 3)
            if(b[i][j] != 0)
                return;
    ans = min(ans, res);
}
void solve()
{
    rep(i, 1, 3)
        rep(j, 1, 3)
            cin >> a[i][j];
    rep(i, 1, 3)
        rep(j, 1, 3)
            a[i][j] = -a[i][j];
    int ans = linf;
    rep(x, 0, (1<<9) - 1) f(x, ans);
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