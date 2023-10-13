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
void solve()
{
    int n, k; cin >> n >> k;
    vector<bool> mark(n);
    rep(i, 1, k)
    {
        int x; cin >> x;
        x --;
        mark[x] = true;
    }
    vector<vector<int>> adj(n);
    rep(i, 1, n - 1)
    {
        int u, v; cin >> u >> v;
        u --, v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n);
    auto bfs = [&](int st)
    {
        dis.assign(n, -1);
        queue<int> q;
        q.push(st);
        dis[st] = 0;
        while(q.size())
        {
            int u = q.front(); q.pop();
            for(auto v : adj[u])
            {
                if(dis[v] == -1)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        int res = -1;
        rep(i, 0, n - 1)
            if(mark[i] && (res == -1 || dis[i] > dis[res]))
                res = i;
        return res;
    };
    int a = bfs(0);
    int b = bfs(a);
    auto vec = dis;
    bfs(b);
    rep(i, 0, n - 1)
        vec[i] = max(vec[i], dis[i]);
    cout << *min_element(vec.begin(), vec.end()) << endl;
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