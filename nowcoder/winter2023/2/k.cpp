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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int deg[N];
bool vis[N];
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<PII> edges;
    vector<vector<int>> g(n+1);
    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        deg[a] ++;
        deg[b] ++;
        edges.push_back({a, b});
    }
    for(auto i:edges)
    {
        int a = i.first, b = i.second;
        if(deg[a] > deg[b]) g[b].push_back(a);
        else g[a].push_back(b);
    }
    rep(i, 1, q)
    {
        int k; cin >> k;
        vector<int> node(k);
        for(auto& x:node) cin >> x;
        for(auto x:node) vis[x] = true;
        int ans = 0;
        for(auto& i:node)
        {
            for(auto j:g[i]) if(vis[j]) ans ++;
        }
        cout << ans << endl;
        for(auto i:node) vis[i] = false;
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