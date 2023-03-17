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
const int N = 10 + 2.5e4, mod = 1e9 + 7;
vector<vector<pii>> g;
int dist[N];
bool sta[N];
int t, r, p, s;
void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    deque<int> q;
    q.push_back(s);
    sta[s] = true;
    while(q.size())
    {
        int t = q.front();
        q.pop_front();
        sta[t] = false;
        for(auto p:g[t])
        {
            int ver = p.first, dis = p.second;
            if(dist[ver] > dist[t] + dis)
            {
                dist[ver] = dist[t] + dis;
                if(!sta[ver])
                {
                    if(q.size() && dist[ver] < dist[q.front()])
                        q.push_front(ver);
                    else q.push_back(ver);
                    sta[ver] = true;
                }
            }
        }
    }
}
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(pq.size())
    {
        auto t = pq.top();
        pq.pop();
        int ver = t.second, dis = t.first;
        if(sta[ver]) continue;
        for(auto p:g[ver])
        {
            if(dist[p.first] > p.second + dis)
            {
                dist[p.first] = p.second + dis;
                if(!sta[p.first]) pq.push({dist[p.first], p.first});
            }
        }
        sta[ver] = true;
    }
}
void solve()
{
    cin >> t >> r >> p >> s;
    g.resize(t + 1);
    rep(i, 1, r + p)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        g[a].push_back({b, c});
        if(i <= r) g[b].push_back({a, c});
    }
    spfa();
    rep(i, 1, t)
    {
        if(dist[i] > inf / 2) cout << "NO PATH\n";
        else cout << dist[i] << endl;
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