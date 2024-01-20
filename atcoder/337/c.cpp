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
#include <regex>
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
    vector<int> vec(n + 1);
    rep(i, 1, n) cin >> vec[i];
    vector<vector<int>> g(n + 1);
    int root;
    rep(i, 1, n)
    {
        if(vec[i] == -1) root = i;
        else g[vec[i]].push_back(i);
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int ver)
    {
        ans.push_back(ver);
        if(g[ver].empty()) return;
        dfs(g[ver].front());
    };
    dfs(root);
    // reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // int t; cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}