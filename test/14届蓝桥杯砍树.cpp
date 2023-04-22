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
const int N = 10 + 1e5, mod = 1e9 + 7;
int d[N], ans, n, m;
int fa[N][21], depth[N];
vector<vector<int>> g;
unordered_map<string, int> mp;
void get_fa(vector<vector<int>>& g, int root)
{
    queue<int> q;
    q.push(root);
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    while(!q.empty())
    {
        int ver = q.front();
        q.pop();
        for(auto x:g[ver])
        {
            if(depth[x] > depth[ver] + 1)
            {
                q.push(x);
                depth[x] = depth[ver] + 1;
                fa[x][0] = ver;
                for(int k = 1; k <= 20; k++)
                    fa[x][k] = fa[fa[x][k-1]][k-1];
            }
        }
    }
}
bool sta[N], sta1[N];
int f(int ver)
{
    sta[ver] = true;
    for(auto x:g[ver])
        if(!sta[x])
        {
            int val = f(x);
            d[ver] += val;
            if(val == m) ans = max(ans, mp[to_string(min(ver, x)) + " " + to_string(max(ver, x))]);
        }
    return d[ver];
}
int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 20; k >= 0; k--)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return a;
    for(int k = 20; k >= 0; k--)
        if(fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}
void solve()
{
    
    cin >> n >> m;
    g.resize(n + 1);
    
    rep(i, 1, n-1)
    {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        mp[to_string(a) + " " + to_string(b)] = i;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    get_fa(g, 1);
    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        d[a] += 1;
        d[b] += 1;
        d[lca(a, b)] -= 2;
    }
    // exit(0);
    sta[1] = true;
    f(1);
    cout << ans;
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