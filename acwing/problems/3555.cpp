// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <set>
// #include <bitset>
// #include <queue>
// #include <map>
// #include <stack>
// #include <random>
// #include <cassert>
// #include <functional>
// #include <iomanip>
// #include <array>
// #include <unordered_map>
// #include <unordered_set>
// #define inf 0x3f3f3f3f
// #define linf 0x3f3f3f3f3f3f3f3fll
// #define endl '\n'
// #define ll long long
// #define int long long
// #define ull unsigned long long
// #define SZ(x) (int)x.size()
// #define rep(i, a, n) for (int i = (a); i <= (n); i++)
// #define dec(i, n, a) for (int i = (n); i >= (a); i--)
// using namespace std;
// using pii = pair<int, int>;
// using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
// const int N = 10 + 1e3, mod = 1e9 + 7;
// bool sta[N];
// vector<vector<int>> g;
// int ans = -1;
// int x, y;
// void dfs(int ver, int dis)
// {
//     if(ver == y)
//     {
//         ans = dis;
//         return;
//     }
//     for(auto v:g[ver])
//     {
//         if(!sta[v])
//         {
//             sta[v] = true;
//             dfs(v, dis+1);
//         }
//     }
// }
// void solve()
// {
//     int n, m;
//     g.clear();
//     cin >> n >> m;
//     g.resize(n+1);
//     rep(i, 1, n)
//     {
//         rep(j, 1, 2)
//         {
//             int x; cin >> x;
//             if(x != -1)
//             {
//                 g[i].push_back(x);
//                 g[x].push_back(i);
//             }
//         }
//     }
//     rep(i, 1, m)
//     {
//         cin >> x >> y;
//         rep(i, 1, n) sta[i] = false;
//         sta[x] = true;
//         dfs(x, 0);
//         cout << ans << endl;
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t; cin >> t;
//     while(t--)
//         solve();

//     return 0;
// }
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
const int N = 10 + 1e3, mod = 1e9 + 7;
int depth[N], fa[N][13];
void bfs(vector<vector<int>>& g, int root)
{
    memset(depth, 0x3f, sizeof(depth));
    memset(fa, 0, sizeof(fa));
    queue<int> q;
    q.push(root);
    depth[0] = 0, depth[root] = 1;
    while(!q.empty())
    {
        int ver = q.front();
        q.pop();
        for(auto x:g[ver])
        {
            if(depth[x] > depth[ver] + 1)
            {
                depth[x] = depth[ver] + 1;
                q.push(x);
                fa[x][0] = ver;
                rep(k, 1, 12)
                    fa[x][k] = fa[fa[x][k-1]][k-1];
            }
        }
    }
}
int query(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    dec(k, 12, 0)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return a;
    dec(k, 12, 0)
        if(fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, 1, n)
    {
        rep(j, 1, 2)
        {
            int x; cin >> x;
            if(x != -1) g[i].push_back(x);
        }
    }
    bfs(g, 1);
    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        int lca = query(a, b);
        cout << depth[a] + depth[b] - 2 * depth[lca] << endl;
    }
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