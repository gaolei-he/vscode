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
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    vector<pii> vec(m);
    for(auto &[x, y] : vec) cin >> x >> y;
    int ans = inf;
    vector<int> store;
    function<void(int)> dfs = [&](int cnt)
    {
        if(cnt == m)
        {
            auto v = a;
            for (int i = 0; i < cnt; i++)
            {
                if(store[i] == -1) v[vec[i].second - 1] += 3;
                else if(store[i] == 0) v[vec[i].first - 1] += 1, v[vec[i].second - 1] += 1;
                else if(store[i] == 1) v[vec[i].first - 1] += 3;
            }
            int val = v.front();
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            int res = 0;
            for(auto x : v)
            {
                res ++;
                if(x == val) break;
            }
            ans = min(ans, res);
            return;
        }
        rep(i, -1, 1)
        {
            store.push_back(i);
            dfs(cnt + 1);
            store.pop_back();
        }
    };
    dfs(0);
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