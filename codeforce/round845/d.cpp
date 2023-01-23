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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
const int N = 10 + 1e5, mod = 1e9 + 7;

void solve()
{
    int n; cin >> n;
    vector<int> g[n+1];
    rep(i, 1, n-1)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dep(n+1, 0);
    vector<char> st(n+1, 0);
    function<int(int)> dfs = [&](int v) {
        if(g[v].size() == 1 && v != 1)
        {
            if(st[v]) return 0;
            st[v] = 1;
            dep[v] = 0;
            return 0;
        }
        int d = 0;
        for(auto i:g[v])
        {
            if(st[i]) continue;
            st[v] = 1;
            d = max(d, dfs(i)+1);
        }
        return dep[v] = d;
    };
    dfs(1);
    rep(i, 1, n) dep[i] ++;
    rep(i, 1, n) cerr << dep[i] << ' ';
    int ans = 0;
    rep(i, 1, n) ans = (dep[i] + ans) % mod;
    rep(i, 1, n-1) ans = ans * 2 % mod;
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