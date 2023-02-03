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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 5e5, mod = 1e9 + 7;
bool a[N][5], vis1[N][5], vis2[N][5];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n)
        rep(j, 1, 3)
            a[i][j] = vis1[i][j] = vis2[i][j] = 0;
    rep(i, 1, k)
    {
        int x, y; cin >> x >> y;
        if(a[x][y]) a[x][y] = false;
        else a[x][y] = true;
    }
    queue<PII> q;
    q.push({1, 1});
    while(q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x > n || y > 3 || a[x][y] || vis1[x][y]) continue;
        vis1[x][y] = true;
        q.push({x+1, y});
        q.push({x, y+1});
    }
    q.push({n, 3});

    while(q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x < 1 || y < 1 || a[x][y] || vis2[x][y]) continue;
        vis2[x][y] = true;
        q.push({x, y-1});
        q.push({x-1, y});
    }
    // cerr << "#\n";

    int ans = 0;
    rep(i, 1, n)
        rep(j, 1, 3)
            if(vis1[i][j] && vis2[i][j] && i + j != 2) ans ++;
    cout << ans << endl;
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