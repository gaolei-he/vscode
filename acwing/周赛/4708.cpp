#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define int long long
#define inf 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a);i<=(n);++i)
#define dec(i, n, a) for (int i=(n);i>=(a);--i)
using namespace std;
int k, n, m;
int x, y;
char mp[12][12][12];
int ans = 0;
int dz[] = {1, 0, -1, 0, 0, 0}, dx[] = {0, 0, 0, 0, 1, -1}, dy[] = {0, 1, 0, -1, 0, 0};
void dfs(int x, int y, int z)
{
    mp[z][x][y] = '#';
    ans ++;
    for (int i = 0; i < 6; i++)
    {
        int tx = dx[i] + x, ty = dy[i] + y, tz = dz[i] + z;
        char op = mp[tz][tx][ty];
        if(op == '.') dfs(tx, ty, tz);
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> k >> n >> m;
    rep(i, 1, k)
        rep(j, 1, n)
            rep(k, 1, m)
                cin >> mp[i][j][k];

    cin >> x >> y;
    dfs(x, y, 1);
    cout << ans << endl;

    return 0;
}