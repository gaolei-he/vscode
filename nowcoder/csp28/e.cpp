#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <functional>
#include <set>
#define rep(i, a, n) for(int i=(a);i<=(n); ++i)
// #define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
#define int __int128
using namespace std;

const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f;
pair<int, int> my_min(pair<int, int> a, pair<int, int> b)
{
    if(b.first == b.second and b.first == 0) return a;
    int resa = 1, resb = 1;
    if(a.first * (resa << a.second) < b.first * (resb << b.second)) return a;
    return b;
}
class Node
{
private:
    int a, b;
    int ver;
public:
    Node(int ver, int a, int b)
    {
        this->a = a;
        this->b = b;
        this->ver = ver;
    }
    int vertex() const { return ver;}
    int distance() const
    {
        int res = 1;
        return a * (res << b);
        // TODO
        return 0;
    }
    bool operator<(const Node &node) const
    {
        return this->distance() < node.distance();
        // TODO
        return 0;
    }
    bool operator>(const Node &node) const
    {
        return this->distance() > node.distance();
        //TODO
        return 0;
    }
};

using pii = pair<Node, int>;


void solve2(int n, int m, vector<vector<int>> &vec, vector<int> &tmp_dist)
{
    vector<map<int, pair<int, int>>> tmp_g(n + 1);
    vector<vector<Node>> g(n + 1);
    for(auto &v : vec)
    {
        int l1 = v[0], r1 = v[1], l2 = v[2], r2 = v[3], a = v[4], b = v[5];
        rep(i, l1, r1)
            rep(j, l2, r2)
                {
                    auto p = make_pair(a, b);
                    tmp_g[j][i] = my_min(p, tmp_g[j][i]);
                }
    }
    rep(i, 1, n)
    {
        for(auto &p : tmp_g[i])
        {
            g[i].emplace_back(p.first, p.second.first, p.second.second);
        }
    }
    vector<int> dist(n + 1, inf);
    vector<bool> st(n + 1, false);
    auto dijkstra = [&](int root = 1) 
    {
        dist[root] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        q.emplace(root, 0, 0);
        while(q.size())
        {
            int ver = q.top().vertex();
            int dis = q.top().distance();
            q.pop();
            if(st[ver]) continue;
            st[ver] = true;
            for(auto p:g[ver])
            {
                int v = p.vertex();
                dist[v] = min(dist[v], dist[ver]+p.distance());
                if(!st[v]) q.emplace(v, dist[v], 0);
            }
        }
    };
    dijkstra();
    for(auto &x : dist) if(x == inf) x = -1;
    rep(i, 2, n)
    {
        if(dist[i] == -1 || tmp_dist[i] == -1) cout << -1 << ' ';
        else
        {
            long long val = (dist[i] % mod + tmp_dist[i] % mod) % mod;
            cout << val << ' ';
        }

    }
}


void solve1()
{
    long long n, m; cin >> n >> m;
    vector<vector<int>> vec(m, vector<int>(6));
    for(auto &v : vec)
        for(auto &x : v)
        {
            long long val; cin >> val;
            x = val;
        }

    vector<map<int, pair<int, int>>> tmp_g(n + 1);
    vector<vector<Node>> g(n + 1);
    for(auto &v : vec)
    {
        int l1 = v[0], r1 = v[1], l2 = v[2], r2 = v[3], a = v[4], b = v[5];
        rep(i, l1, r1)
            rep(j, l2, r2)
                {
                    auto p = make_pair(a, b);
                    tmp_g[i][j] = my_min(p, tmp_g[i][j]);
                }
    }
    rep(i, 1, n)
    {
        for(auto &p : tmp_g[i])
        {
            g[i].emplace_back(p.first, p.second.first, p.second.second);
        }
    }

    vector<int> dist(n + 1, inf);
    vector<bool> st(n + 1, false);
    auto dijkstra = [&](int root = 1) 
    {
        dist[root] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        q.emplace(root, 0, 0);
        while(q.size())
        {
            int ver = q.top().vertex();
            int dis = q.top().distance();
            q.pop();
            if(st[ver]) continue;
            st[ver] = true;
            for(auto p:g[ver])
            {
                int v = p.vertex();
                dist[v] = min(dist[v], dist[ver]+p.distance());
                if(!st[v]) q.emplace(v, dist[v], 0);
            }
        }
    };
    dijkstra();
    for(auto &x : dist) if(x == inf) x = -1;
    solve2(n, m, vec, dist);
    // rep(i, 1, n) cout << dist[i] << ' ';
}

signed main()
{

    solve1();
    return 0;
}