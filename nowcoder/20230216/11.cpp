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
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int d[N];
bool st[N];
vector<vector<int>> g;
int ans = 0, root;
int dfs(int x)
{
    if(d[x]) return d[x];
    else if(x == root) return 0;
    ans ++;
    d[x] = dfs(g[x].front()) + 1;
    return d[x];
}
void solve()
{
    int n, m; cin >> n >> m;
    int x;
    g.resize(n+1);
    rep(i, 1, n)
    {
        cin >> x;
        if(x < 0){root = i; continue;}
        g[i].push_back(x);
    }
    priority_queue<int, vector<int>, less<int>> pq;
    
    rep(i, 1, m)
    {
        cin >> x;
        d[x] = dfs(x);
        pq.push(d[x]);
        cout << ans * 2 - pq.top() << endl;
    }
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