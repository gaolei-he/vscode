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
bool st[N][N];
// string f(int x, int y)
// {
//     string s;
//     while(x) s.push_back(x%10+'0'), x /= 10;
//     s.push_back(' ');
//     while(y) s.push_back(y%10+'0'), y /= 10;
//     return s;
// }
// void g(int& x, int& y, string ans)
// {
//     x = 0;
//     y = 0;
//     while(ans.back() != ' ')
//     {
//         y *= 10;
//         y += ans.back() - '0';
//         ans.pop_back();
//     }
//     ans.pop_back();
//     while(ans.size())
//     {
//         x *= 10;
//         x += ans.back() - '0';
//         ans.pop_back();
//     }
// }
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
    while(q --)
    {
        int xt, yt;
        cin >> xt >> yt;
        xt ++, yt ++;
        bool flag = true;
        rep(i, 1, n*m)
        {
            switch (str[xt][yt])
            {
            case 'L':if(str[xt][yt-1] != '#') yt --; break;
            case 'R':if(str[xt][yt+1] != '#') yt ++; break;
            case 'U':if(str[xt-1][yt] != '#') xt --; break;
            case 'D':if(str[xt+1][yt] != '#') xt ++; break;
            default: break;
            }
            if(dis[xt][yt] && dis[xt][yt] <= i || xt == xs && yt == ys)//qcjj走到了商场入口
            {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << -1 << endl;
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