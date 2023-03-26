//luogu P3379
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 5e5+10;
int fa[N][21];
int depth[N];
void lca(vector<vector<int>>& g, int root)
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
int query(int a, int b)
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
int main()
{
    vector<vector<int>> g;
    int n, m, s;
    cin >> n >> m >> s;
    g.resize(n+1);
    for(int i=1;i<=n - 1;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    lca(g, s);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    
    return 0;
}