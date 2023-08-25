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
    int n, x, y, r; cin >> n >> x >> y >> r;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    sort(vec.begin(), vec.end());
    int ans = 0;
    auto f = [&](int val) {
        vector<int> dp(val + 1);
        for(int i=1;i<=val;i++) dp[i] = i / x * x;
        for(int i=y;i<=val;i++) dp[i] = max(dp[i], dp[i-y] + y);
        return dp[val];
    };
    vector<pii> vec1;
    for(auto x : vec)
    {
        int val = f(x);
        vec1.emplace_back(x - val, x);
        // // cerr << x << ' ' << val << endl;
        // ans += (x - min(val, r)) * (x - min(val, r));
        // r -= min(val, r);
    }
    sort(vec1.begin(), vec1.end());
    for(auto &[x, y] : vec1)
    {
        if(r >= y - x)
        {
            // cerr << x << ' ' << y << ' ' << r << endl;
            r -= y - x;
            ans += x * x;
            x = y = 0;
        }
    }
    for(auto &[x, y] : vec1)
    {
        if(y >= r)ans += (y - r) * (y - r), r = 0;
        else ans += y * y;
    }
    if(r) cout << -1 << endl;
    else cout << ans << endl;
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