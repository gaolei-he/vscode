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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 11, mod = 1e9 + 7;
int a[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool st[N][N];
int f[N][N];
void solve()
{
    int h, w;
    cin >> h >> w;
    rep(i, 1, h)
        rep(j, 1, w)
            cin >> a[i][j];
    unordered_set<int> st1;
    int ans = 0;
    int res = 0;
    function<int(int, int)> dfs = [&](int x, int y) {
        res ++;
        if(f[x][y]) return f[x][y];
        if(x == w && y == h)
        {
            ans ++;
            return 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = dx[i] + x, ty = dy[i] + y;
            if(tx > 0 && tx <= h && ty > 0 && ty <= w && !st[tx][ty])
            {
                st[tx][ty] = true;
                f[x][y] += dfs(tx, ty);
                st[tx][ty] = false;
            }
        }
        return f[x][y];
    };
    
    st[1][1] = true;
    f[1][1] = dfs(1, 1);
    cout <<f[1][1] <<endl;
    // rep(i, 1, h)
    // {
    //     rep(j, 1, w) cout <<f[i][j] << ' ';
    //     cout <<endl;
    // }
    cout << ans << ' ' << res << endl;
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