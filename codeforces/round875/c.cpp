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
    int n; cin >> n;
    unordered_map<string, int> mp;
    vector<vector<int>> g(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        mp[to_string(u) + " " + to_string(v)] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vector<bool> sta(n + 1, false);
    queue<int> q1;
    unordered_set<int> q2;
    function<void(int, int)> dfs = [&](int u, int pri)
    {
        sta[u] = true;
        for(auto v : g[u])
        {
            if(sta[v]) continue;
            int t = mp[to_string(min(u, v)) + " " + to_string(max(u, v))];
            if(t > pri) dfs(v, t);
            else q2.insert(u);
        }
    };
    q1.push(1);
    while(q1.size())
    {
        ans ++;
        while(q1.size())
        {
            int u = q1.front(); q1.pop();
            dfs(u, 0);
        }
        for(auto x : q2) q1.push(x);
        q2.clear();
    }
    cout << ans << endl;
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