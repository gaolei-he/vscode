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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n+1);
    set<pii> st;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        st.insert({min(u, v), max(u, v)});
    }

    vector<int> dist(n+1, linf);
    int ans = 0;
    auto bfs = [&]() {
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto v : g[u]) {
                if(dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    st.erase({min(u, v), max(u, v)});
                }
            }
        }
    };
    bfs();
    rep(i, 1, n) if(dist[i] <= k) ans ++;
    for(auto &[u, v] : st)
    {
        if(dist[u] <= k and dist[v] <= k)
            ans += k - dist[u] + k - dist[v];
    }
    rep(i, 1, n)
    {
        if(g[i].size() == 1 and dist[g[i].front()] < dist[i] and dist[i] < k)
        {
            // cerr << k << " " << i << " " << dist[i] << endl;
            ans += k - dist[i];
        }
    }
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