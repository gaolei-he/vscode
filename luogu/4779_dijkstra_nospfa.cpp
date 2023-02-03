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
int n, m, s;
vector<vector<pii>> g;

void dijkstra()
{
    rep(i, 1, n) dist[i] = (1<<31)-1;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while(q.size())
    {
        int ver = q.top().second;
        int dis = q.top().first;
        q.pop();
        if(st[ver]) continue;
        st[ver] = true;
        for(auto p:g[ver])
        {
            int v = p.first;
            dist[v] = min(dist[v], dist[ver]+p.second);
            if(!st[v]) q.push({dist[v], v});
        }
    }

}
void solve()
{
    
    cin >> n >> m >> s;
    g.resize(n+1);
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra();
    rep(i, 1, n) cout << dist[i] << ' ';
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