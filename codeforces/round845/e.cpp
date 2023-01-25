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
using pii = pair<int, int>;
using ar3 = array<int, 3>;
const int N = 10 + 2e5, mod = 1e9 + 7;
int n, m;
vector<vector<int>> g;
vector<ar3> edges;
void solve()
{
    g.clear();
    edges.clear();
    cin >> n >> m;
    g.resize(n+1);
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int l = 0, r = mod - 3;
    vector<vector<int>> g2;
    vector<char> vis;
    function<void(int&, int)> dfs = [&](int& root, int k) {
        vis[k] = 1;
        for(auto i:g2[k])
            if(!vis[i])
                dfs(root, i);
        root = k;
    };
    function<void(int)> countf = [&](int st) {
        vis[st] = 1;
        for(auto i:g2[st])
            if(!vis[i])
                countf(i);
    };
    function<bool(int)> check = [&](int c) {
        vis.clear();
        vis.resize(n+1);
        int root;
        rep(i, 1, n) if(!vis[i]) dfs(root, i);
        vis.clear();
        vis.resize(n+1);
        countf(root);
        rep(i, 1, n) if(!vis[i]) return false;
        return true;
    };
    while(l < r)
    {
        int mid = l + r >> 1;
        g2.clear();
        g2.resize(n+1);
        for(auto e:edges)
        {
            g2[e[0]].push_back(e[1]);
            if(e[2] <= mid) g2[e[1]].push_back(e[0]);
        }
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l > mod - 6) l = -1;
    cout << l << endl;
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

/*
题目链接
https://codeforces.com/contest/1777/problem/E

题目大意
给定n个点，m条边，每条边都有一个权重，你可以翻转一些边或者不翻转，使得存在一个点，
从该点出发可到达其他所有的点，定义cost为你翻转的所有边中权重最大的一条，你需要输出最小的cost

解法
二分答案，对于权重小于等于mid的边，可以当做双向边，其余的边不变，对该图进行遍历，
找到一个root，如果从root出发可以遍历其余所有的点，那么mid就是合法的
*/