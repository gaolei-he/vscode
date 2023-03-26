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
vector<vector<pii>> g;
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(pq.size())
    {
        auto t = pq.top();
        pq.pop();
        if(sta[t.second]) continue;
        for(auto i:g[t.second])
        {
            if(sta[i.first]) continue;
            if(dist[i.first] > t.first + i.second)
            {
                dist[i.first] = t.first + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
        sta[t.second] = true;
    }
}
void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    sta[0] = true;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        sta[t] = false;
        for(auto p:g[t])
        {
            if(dist[p.first] > dist[t] + p.second)
            {
                dist[p.first] = dist[t] + p.second;
                if(!sta[p.first])
                {
                    q.push(p.first);
                    sta[p.first] = true;
                }
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    rep(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int k; cin >> k;
    rep(i, 1, k)
    {
        int x; cin >> x;
        g[0].push_back({x, 0});
        g[x].push_back({0, 0});
    }
    spfa();
    int q; cin >> q;
    
    rep(i, 1, q)
    {
        int x; cin >> x;
        cout << dist[x] << endl;
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