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
const int N = 10 + 1e3, mod = 1e9 + 7;
bool sta[N];
vector<vector<int>> g;
int ans = -1;
int x, y;
void dfs(int ver, int dis)
{
    if(ver == y)
    {
        ans = dis;
        return;
    }
    for(auto v:g[ver])
    {
        if(!sta[v])
        {
            sta[v] = true;
            dfs(v, dis+1);
        }
    }
}
void solve()
{
    int n, m;
    g.clear();
    cin >> n >> m;
    g.resize(n+1);
    rep(i, 1, n)
    {
        rep(j, 1, 2)
        {
            int x; cin >> x;
            if(x != -1)
            {
                g[i].push_back(x);
                g[x].push_back(i);
            }
        }
    }
    rep(i, 1, m)
    {
        cin >> x >> y;
        rep(i, 1, n) sta[i] = false;
        sta[x] = true;
        dfs(x, 0);
        cout << ans << endl;
    }
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