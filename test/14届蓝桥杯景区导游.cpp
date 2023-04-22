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
const int N = 10 + 1e5, mod = 1e9 + 7;
int dist[N];
bool sta[N];
void shortest_path(vector<vector<pii>>& g)
{
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    sta[1] = true;
    while(q.size())
    {
        int ver = q.front();
        q.pop();
        for(auto& p:g[ver])
        {
            if(sta[p.first])
                continue;
            dist[p.first] = dist[ver] + p.second;
            sta[p.first] = true;
            q.push(p.first);
        }
    }
}
int fa[N][21], depth[N];
void get_fa(vector<vector<pii>>& g, int root)
{
    queue<int> q;
    q.push(root);
    memset(depth, 0x3f, sizeof(depth));
    depth[0] = 0, depth[root] = 1;
    while(q.size())
    {
        int ver = q.front();
        q.pop();
        for(auto& p:g[ver])
        {
            if(depth[p.first] > depth[ver] + 1)
            {
                q.push(p.first);
                depth[p.first] = depth[ver] + 1;
                fa[p.first][0] = ver;
                for(int k=1;k<=20;k++)
                    fa[p.first][k] = fa[fa[p.first][k-1]][k-1];
            }
        }
    }
}
int lca(int a, int b)
{
    
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 20; k >= 0; k --)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return a;
    for(int k = 20; k >= 0; k--)
        if(fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}
void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<pii>> g(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    get_fa(g, 1);
    shortest_path(g);
    vector<int> vec(k);
    for(auto& x:vec) cin >> x;
    int sm = 0;
    for (int i = 0; i < vec.size() - 1; i++)
        sm += dist[vec[i]] + dist[vec[i+1]] - 2 * dist[lca(vec[i], vec[i+1])];
    for (int i = 0; i < vec.size(); i++)
    {
        if(i == 0) cout << sm - (dist[vec[i]] + dist[vec[i+1]] - 2 * dist[lca(vec[i], vec[i+1])]) << endl;
        else if(i == vec.size() - 1) cout << sm - (dist[vec[i]] + dist[vec[i-1]] - 2 * dist[lca(vec[i], vec[i-1])]) << endl;
        else
        {
            int tmp = sm;
            sm -= dist[vec[i]] + dist[vec[i+1]] - 2 * dist[lca(vec[i], vec[i+1])];
            sm -= dist[vec[i]] + dist[vec[i-1]] - 2 * dist[lca(vec[i], vec[i-1])];
            sm += dist[vec[i-1]] + dist[vec[i+1]] - 2 * dist[lca(vec[i-1], vec[i+1])];
            cout << sm << endl;
            sm = tmp;
        }
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