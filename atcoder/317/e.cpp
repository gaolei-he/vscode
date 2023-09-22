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
const int N = 10 + 2e3, mod = 1e9 + 7;
char str[N][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
void solve()
{
    int h, w; cin >> h >> w;
    rep(i, 1, h) cin >> str[i] + 1;
    rep(i, 1, h)
        rep(j, 1, w)
            if(str[i][j] == '>')
                while(str[i][j + 1] == '.' or str[i][j + 1] == '!') str[i][++j] = '!';
    rep(i, 1, h)
        dec(j, w, 1)
            if(str[i][j] == '<')
                while(str[i][j - 1] == '.' or str[i][j - 1] == '!') str[i][--j] = '!';
    rep(j, 1, w)
        rep(i, 1, h)
            if(str[i][j] == 'v')
                while(str[i + 1][j] == '.' or str[i + 1][j] == '!') str[++i][j] = '!';
    rep(j, 1, w)
        dec(i, h, 1)
            if(str[i][j] == '^')
                while(str[i - 1][j] == '.' or str[i - 1][j] == '!') str[--i][j] = '!';
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, -1));
    int sx, sy, ex, ey;
    // rep(i, 1, h) cerr << str[i] + 1 << endl;
    rep(i, 1, h)
        rep(j, 1, w)
            if(str[i][j] == 'S') sx = i, sy = j;
            else if(str[i][j] == 'G') ex = i, ey = j;
    dp[sx][sy] = 0;
    queue<pii> q;
    q.push({sx, sy});
    while(q.size())
    {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        // cerr << x << ' ' << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if((str[tx][ty] == '.' or str[tx][ty] == 'G') and dp[tx][ty] == -1) {
                dp[tx][ty] = dp[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    cout << dp[ex][ey] << endl;
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