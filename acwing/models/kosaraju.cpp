#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<vector<int>> g, g2;
vector<int> s, color;
int sccCnt;
int n, m;
void dfs1(int u) {
  vis[u] = true;
  for (int v : g[u])
    if (!vis[v]) dfs1(v);
  s.push_back(u);
}

void dfs2(int u) {
  color[u] = sccCnt;
  for (int v : g2[u])
    if (!color[v]) dfs2(v);
}

void kosaraju() {
  sccCnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs1(i);
  for (int i = n; i >= 1; --i)
    if (!color[s[i]]) {
      ++sccCnt;
      dfs2(s[i]);
    }
}
int main()
{
    cin >> n >> m;
    s.push_back(0);
    g.resize(n+1);
    g2.resize(n+1);
    color.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g2[b].push_back(a);
    }
    kosaraju();
    cout << sccCnt << endl;
    return 0;
}