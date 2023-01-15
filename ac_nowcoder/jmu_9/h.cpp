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
#define double long double
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
char mp[250][250];
int ans1 = 0;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int ans = 0;
void f(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    ans1 += (y2-y1) * (x2-x1);
    rep(i, x1, x2)
        rep(j, y1, y2)
            mp[i][j] = '.';
}

void dfs(int x, int y, char op)
{
    mp[x][y] = op;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(mp[tx][ty] == '#') dfs(tx, ty, op);
    }

}



void solve()
{
    int x[6], y[6];
    rep(i, 1, 5) cin >> x[i] >> y[i];
    rep(i, 1, 5) x[i] += 120, y[i] += 120;
    rep(i, 1, 230)
        rep(j, 1, 230)
            mp[i][j] = '#';
    rep(i, 1, 4) f(x[i], y[i], x[i+1], y[i+1]);
    f(x[1], y[1], x[5], y[5]);

    dfs(1, 1, '&');
    rep(i, 1, 230)
        rep(j, 1, 230)
            if(mp[i][j] == '#') {dfs(i, j, '.'); break;}
    rep(i, 1, 230)
    {
        rep(j, 1, 230)
        {
            char op = mp[i][j];
            if(op == mp[i+1][j+1] && op == mp[i+1][j] && op == mp[i][j+1] && op == '.') ans ++;
        }
    }
    // cout << ans1 << endl;
    // rep(i, 110, 130)
    // {
    //     rep(j, 110, 130)
    //     {
    //         cout << mp[i][j] << ' ';

    //     }
    //     cout << endl;
    // }
    cout << (ans - ans1) * 2 + ans1;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

// double f(int x1, int y1, int x2, int y2, int x3, int y3)
// {
//     double a = sqrt((y1-y2)*(y1-y2) + (x1-x2)*(x1-x2));
//     double b = sqrt((y1-y3)*(y1-y3) + (x1-x3)*(x1-x3));
//     double c = sqrt((y3-y2)*(y3-y2) + (x3-x2)*(x3-x2));
//     double p = (a + b + c) / 2;
//     return sqrt(p * (p-a) * (p-b) * (p-c));
// }
// rep(i, 1, 204)
// {
//     rep(j, 1, 204)
//             cout
//         << mp[i][j] << ' ';
//     cout << endl;
// }

// void dfs(int x, int y)
// {
//     mp[x][y] = '*';
//     if(mp[x+1][y+1]) ans ++;
//     if(mp[x][y-1] == '.') {ans ++; mp[x][y-1] = '*';}
//     if(mp[x-1][y] == '.') {ans ++; mp[x-1][y] = '*'; }
//     if(mp[x-1][y-1] == '.') {ans ++; mp[x-1][y-1] = '*'; }
//     rep(i, 0, 3)
//     {
//         int tx = x + dx[i], ty = y + dy[i];
//         if (mp[tx][ty] == '#')
//             dfs(tx, ty);
//     }
// }