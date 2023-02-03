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
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 8e2, mod = 1e9 + 7;
char str[N][N];
int dis[N][N];
pii nxt[N][N][22];
void solve()
{
    int n, m, xs, ys, q;
    cin >> n >> m >> xs >> ys >> q;
    xs ++, ys ++;
    rep(i, 1, n) cin >> str[i] + 1;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    queue<pii> que;
    que.push({xs, ys});
    dis[xs][ys] = 0;
    while(que.size())
    {
        pii t = que.front();
        int x = t.first, y = t.second;
        que.pop();
        rep(i, 0, 3)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx < 1 || ty < 1 || tx > n || ty > m || str[tx][ty] == '#') continue;
            if(dis[tx][ty]) continue;
            dis[tx][ty] = dis[x][y] + 1;
            que.push({tx, ty});
        }
    }

    rep(i, 1, n)
        rep(j, 1, m)
        {
            int x = i, y = j;
            switch (str[x][y])
            {
            case 'L':if(str[x][y-1] != '#') y--; break;
            case 'R':if(str[x][y+1] != '#') y++; break;
            case 'U':if(str[x-1][y] != '#') x--; break;
            case 'D':if(str[x+1][y] != '#') x++; break;
            default: break;
            }
            nxt[i][j][0] = {x, y};
        }
    rep(k, 1, 20)
        rep(i, 1, n)
            rep(j, 1, m)
            {
                int x = nxt[i][j][0].first, y = nxt[i][j][0].second;
                rep(l, 0, k-1)
                {
                    auto t = nxt[x][y][l];
                    x = t.first, y = t.second;
                }
                nxt[i][j][k] = {x, y};
            }
    int xt, yt;
    function<bool(int, int, int)> check = [&](int k, int xt, int yt) {
        int tk = k;
        rep(i, 0, mod)
        {
            auto t = nxt[xt][yt][i];
            if(k&1) xt = t.first, yt = t.second;
            k >>= 1;
            if(!k) break;
        }
        if(dis[xt][yt] && dis[xt][yt] <= tk) return true;
        else if(xt == xs && yt == ys) return true;
        return false;
    };
    while(q --)
    {
        
        cin >> xt >> yt;
        xt ++, yt ++;
        int l = 0, r = n * m + 10;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid, xt, yt)) r = mid;
            else l = mid + 1;
        }
        if(l > m * n) l = -1;
        cout << l << endl;
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