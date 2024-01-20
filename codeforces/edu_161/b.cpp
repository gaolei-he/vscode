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
    auto C = [&](int n, int k)
    {
        if(n < k) return 0ll;
        int res = 1;
        rep(i, 1, k) res = res * (n - i + 1);
        rep(i, 1, k) res /= i;
        return res;
    };
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    map<int, int> mp;
    for(auto x : vec) mp[x] ++;
    int sm = 0, ans = 0;
    for(auto [k, v] : mp)
    {
        if(v > 1) ans += C(v, 3) + C(v, 2) * sm;
        sm += v;
    }
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