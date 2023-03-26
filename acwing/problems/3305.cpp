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
const int N = 10 + 2e3, mod = 1e9 + 7;
int dist[N], n, m, k, t;
bool sta[N];
int w[N];
queue<int> q;
vector<vector<pii>> g;
void spfa()
{
    while(q.size())
    {
        auto x = q.front();
        q.pop();
        sta[x] = false;
        for(auto p:g[x])
        {
            int y = p.first, z = p.second;
            if(dist[z] > max(dist[x], dist[y]) + max(w[x], w[y]))
            {
                dist[z] = max(dist[x], dist[y]) + max(w[x], w[y]);
                if(!sta[z])
                {
                    q.push(z);
                    sta[z] = true;
                }
            }
        }
    }
}
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // dist[0] = 0;
    // pq.push({0, 0});
    while(q.size())
    {
        auto x = q.front();
        q.pop();
        sta[x] = false;
        pq.push({0, x});
    }
    while(pq.size())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second, dis = p.first;
        if(sta[x]) continue;
        for(auto p:g[x])
        {
            int y = p.first, z = p.second;
            if(dist[z] > max(dist[x], dist[y]) + max(w[x], w[y]))
            {
                dist[z] = max(dist[x], dist[y]) + max(w[x], w[y]);
                if(!sta[z]) pq.push({dist[z], z});
            }
        }
        sta[x] = true;
    }
}
void bellman_ford()
{
    using ar3 = array<int, 3>;
    vector<ar3> vec;
    rep(i, 1, n)
        for(auto p:g[i])
            vec.push_back({i, p.first, p.second});
    rep(i, 1, n)
    {
        for(auto p:vec)
        {
            int x = p[0], y = p[1], z = p[2];
            dist[z] = min(dist[z], max(dist[x], dist[y]) + max(w[x], w[y]));
        }
    }
}
void solve()
{
    cin >> n >> m >> k >> t;
    g.resize(n+1);
    rep(i, 1, n) cin >> w[i];
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        dist[x] = 0;
        q.push(x);
        sta[x] = true;
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dijkstra();
    // rep(i, 1, n) cerr << dist[i] << ' ';
    cout << dist[t] << endl;
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