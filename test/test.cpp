#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int fa[N][20], dep[N], n, m;
void get_fa(vector<vector<int>>& g, int root)
{
    queue<int> q;
    q.push(root);
    memset(dep, 0x3f, sizeof(dep));
    dep[0] = 0, dep[root] = 1;
    while(q.size())
    {
        int ver = q.front();
        q.pop();
        for(auto x:g[ver])
        {
            if(dep[x] > dep[ver] + 1)
            {
                dep[x] = dep[ver] + 1;
                q.push(x);
                fa[x][0] = ver;
                for(int i=1;i<20;i++)
                    fa[x][i] = fa[fa[x][i-1]][i-1];
            }
        }
    }
}
int lca(int a, int b)
{
    if(dep[a] < dep[b]) swap(a, b);
    for(int i=19;i>=0;i--)
        if(dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    if(a == b) return a;
    for(int i=19;i>=0;i--)
    {
        if(fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s; cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    get_fa(g, s);
    while(m--)
    {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}