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
using psi = pair<string, int>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e2, mod = 1e9 + 7;
int dist[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    rep(i, 1, n) dist[i][i] = 0;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    if(dist[1][n] == linf)
    {
        cout << "inf\n";
        return;
    }
    string ans(n, '0');
    ans.front() = '1';
    vector<psi> vec;
    cout << dist[1][n];
    for(int lst=0,mi;dist[1][n]!=linf;lst=mi)
    {
        mi = dist[1][n];
        rep(i, 2, n) mi = min(dist[1][i], mi);
        vec.push_back({ans, mi-lst});
        rep(i, 2, n) if(mi == dist[1][i]) ans[i-1] = '1',dist[1][i] = linf;
    }
    cout << ' ' << vec.size() << endl;
    for(auto[x,y]:vec) cout << x << ' ' << y << endl;
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