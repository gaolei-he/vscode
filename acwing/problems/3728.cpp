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
const int N = 10 + 2e3, mod = 1e9 + 7;
int c[N], k[N];
pii a[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n)
    {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> k[i];
    vector<pair<int, pii>> vec;
    rep(i, 1, n-1)
        rep(j, i+1, n)
        {
            int dis = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
            vec.push_back({dis * (k[i] + k[j]), {i, j}});
            // pq.push({dis * (k[i] + k[j]), {j, i}});
        }
    rep(i, 1, n)
    {
        vec.push_back({c[i], {0, i}});
        // pq.push({c[i], {i, 0}});
    }
    sort(vec.begin(), vec.end());
    vector<vector<int>> g(n+1);
    vector<int> p(n+1);
    rep(i, 1, n) p[i] = i;
    function<int(int)> find = [&](int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    };
    int ans = 0;
    for(auto tmp:vec)
    {
        // cerr << tmp.first << endl;
        int x = tmp.second.first, y = tmp.second.second;
        int a = find(x), b = find(y);
        if(a != b)
        {
            p[a] = b;
            ans += tmp.first;
            g[x].push_back(y);
        }
    }
    cout << ans << endl << g[0].size() << endl;
    for(auto x:g[0]) cout << x << ' ';
    if(g[0].size()) cout << endl;
    int tmp = 0;
    rep(i, 1, n) tmp += g[i].size();
    cout << tmp << endl;
    rep(i, 1, n)
        for(auto j:g[i]) cout << i << ' ' << j << endl;
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