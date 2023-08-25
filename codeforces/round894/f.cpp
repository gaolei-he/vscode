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
const int N = 10 + 1e2, mod = 1e9 + 7;
void solve()
{
    int w, f; cin >> w >> f;
    int n; cin >> n;
    int sm = 0;
    vector<int> a(n);
    for(auto &x : a)
    {
        cin >> x;
        sm += x;
    }
    vector<int> dp(sm + 1, 0);
    for(auto x : a)
    {
        dec(i, sm, x)
            dp[i] = max(dp[i], dp[i - x] + x);
    }
    rep(i, 1, mod)
    {
        if(dp[min(i*w, sm)] + i * f >= sm)
        {
            cout << i << endl;
            return;
        }
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