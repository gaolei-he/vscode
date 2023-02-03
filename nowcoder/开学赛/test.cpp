#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n + 1);
    vector<int> s(n + 1);
    vector<int> d(n + 1);
    vector<int> a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> w[i]; //点权值
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        // vector存图
        a[u].push_back(v);
        a[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int f)
    {
        s[u] += w[u];       //递归第一步，算入自己节点蚂蚁数量
        d[u] = w[u] + d[f]; //树上前缀和
        for (int v : a[u])  //遍历所有子节点
            if (v != f)
                dfs(v, u), s[u] += s[v]; //加上所有子节点蚂蚁
        //数量，即得答案
    };
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << s[i] << ' ' << d[i] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}