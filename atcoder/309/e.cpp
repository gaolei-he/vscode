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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, 2, n) 
    {
        int x; cin >> x;
        g[x].push_back(i);
    }

    vector<int> vec(n+1, 0);
    rep(i, 1, m)
    {
        int x, y; cin >> x >> y;
        vec[x] = y + 1;
    }
    int ans = 0;
    int val = 0;
    function<void(int, int)> dfs = [&](int ver, int dis) {
        dis = max(vec[ver], dis);
        val ++;
        if(dis) ans ++;
        for(auto x : g[ver]) dfs(x, dis-1);
    };
    dfs(1, vec[1]);
    if(val != n) exit(-1);
    cout << ans << endl;
    
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