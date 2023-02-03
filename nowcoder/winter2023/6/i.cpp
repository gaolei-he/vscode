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
const int N = 10 + 2e5, mod = 1e9 + 7;
int dist[N];
bool st[N];
int n, m;
vector<vector<int>> g;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while(q.size())
    {
        int ver = q.top().second;
        int dis = q.top().first;
        q.pop();
        if(st[ver]) continue;
        st[ver] = true;
        for(auto v:g[ver])
        {
            if(dist[v] > dist[ver] + 1)
            {
                dist[v] = dist[ver] + 1;
                q.push({dist[v], v});
            }
        }
    }
    return dist[n];

}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    int tmp = 0;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(u == 1 || v == 1) tmp = w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = dijkstra();
    if(m == dist[n]) ans += tmp - 1;
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