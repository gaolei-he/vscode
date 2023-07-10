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
const int N = 10 + 1e5, mod = 1e9 + 7;
int dijkstra(vector<vector<int>> &g, int root)
{
    vector<int> dist(SZ(g), inf);
    vector<bool> sta(SZ(g), false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, root});
    dist[root] = 0;
    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        // if(sta[u]) continue;
        // sta[u] = true;
        for(auto v : g[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    int res = 0;
    for(auto x:dist) if(x != inf) res = max(res, x);
    return res;
}
void solve()
{
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<vector<int>> g1(n1+1), g2(n2+1);
    rep(i, 1, m)
    {
        int u, v; cin >> u >> v;
        if(u <= n1) g1[u].push_back(v), g1[v].push_back(u);
        else g2[u-n1].push_back(v-n1), g2[v-n1].push_back(u-n1);
    }
    cout << dijkstra(g1, 1) + dijkstra(g2, n2) + 1 << endl;
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