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
const int N = 10 + 2e5, mod = 1e9 + 7;
int son[N];
bool sta[N];
int quick_pow(int a, int b, int mod)
{
    a %= mod;
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    rep(i, 1, n-1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(k & 1)
    {
        cout << 1 << endl;
        return;
    }
    function<int(int)> dfs = [&](int ver) {
        sta[ver] = true;
        int res = 0;
        for(auto i:g[ver])
            if(!sta[i])
                res += dfs(i);
        return son[ver] = res + 1;
    };
    dfs(1);
    int ans = 0;
    // rep(i, 1, n) cerr << son[i] << ' ';
    memset(sta, 0, sizeof(sta));
    function<void(int)> dfs1 = [&](int ver) {
        sta[ver] = true;
        int sm = 0;
        vector<int> tmp;
        for(auto i:g[ver])
        {
            if(!sta[i])
            {
                dfs1(i);
                sm += son[i];
                tmp.push_back(son[i]);
            }
            else
            {
                sm += n - son[ver];
                tmp.push_back(n - son[ver]);
            }
        }
        int v = 0;
        for(auto x:tmp) v += x * (sm - x);
        ans += n - 1 + v / 2;
        ans %= mod;
    };
    dfs1(1);
    // cerr << ans << endl;
    cout << ans * quick_pow(n * (n - 1) / 2, mod - 2, mod) % mod  << endl;
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