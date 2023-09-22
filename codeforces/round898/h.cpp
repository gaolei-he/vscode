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
vector<int> p;
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> g(n + 1);
    p.resize(n + 1);
    vector<int> cycle;
    iota(p.begin(), p.end(), 0);
    rep(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        if(fu == fv) cycle.push_back(u), cycle.push_back(v);
        p[fu] = fv;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    bool flag = false;
    function<void(int, int)> dfs = [&](int fa, int son) {
        if(flag) return;
        vis[son] = true;
        for(auto ver : g[son])
        {
            cycle.push_back(ver);
            if(!vis[ver]) dfs(son, ver);
            else if(vis[ver] and ver != fa) flag = true;
            if(!flag) cycle.pop_back();
            else return;
        }
    };
    vis[cycle.front()] = true;
    dfs(cycle.front(), cycle.back());
    cycle.pop_back();
    set<int> st;
    for(auto v : cycle) st.insert(v);
    if(a == b)
    {
        cout << "NO" << endl;
        return;
    }
    else if(st.count(b))
    {
        cout << "YES" << endl;
        return;
    }
    vector<int> dist1(n + 1, inf), dist2(n + 1, inf);
    auto bfs = [&](int ver, vector<int>& dist) {
        queue<int> q;
        q.push(ver);
        dist[ver] = 0;
        while(q.size())
        {
            int v = q.front();
            q.pop();
            for(auto u : g[v])
            {
                if(dist[u] == inf)
                {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
    };
    bfs(a, dist1);
    bfs(b, dist2);
    int ans = -1, tmp = inf;
    rep(i, 1, n)
        if(st.count(i) and dist2[i] < tmp)
            tmp = dist2[i], ans = i;
    if(dist1[ans] <= dist2[ans]) cout << "NO" << endl;
    else cout << "YES" << endl;

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